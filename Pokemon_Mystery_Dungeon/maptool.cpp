#include "stdafx.h"
#include "maptool.h"

Maptool::Maptool()
{
}

Maptool::~Maptool()
{
}

HRESULT Maptool::init()
{
	_maptile =IMAGEMANAGER->addFrameDImage("maptiles", L"img/map/tiles/maptile.png", 768, 384, 16, 8);
	_object =IMAGEMANAGER->addFrameDImage("object", L"img/map/tiles/object.png", 864, 576, SAMPLETILEX, SAMPLETILEY);
	type = 1;
	setup();


	return S_OK;
}

void Maptool::release()
{
}

void Maptool::update()
{
	if (KEYMANAGER->isOnceKeyDown('1'))type--;
	if (KEYMANAGER->isOnceKeyDown('2'))type++;
	if (KEYMANAGER->isOnceKeyDown('3'))save();
	if (KEYMANAGER->isOnceKeyDown('4'))load();
	if (KEYMANAGER->isStayKeyDown(VK_RBUTTON)) { _ctrSelect = CTRL_ERASER; setMap(); }

	if (type == 1 && KEYMANAGER->isStayKeyDown(VK_LBUTTON)) { _ctrSelect = CTRL_TERRAINDRAW; setMap(); }
	if (type == 2 && KEYMANAGER->isStayKeyDown(VK_LBUTTON)) { _ctrSelect = CTRL_OBJDRAW; setMap(); }
	


	if (type <= 0)type = 1;
	if (type >= 4)type = 3;

	
}

void Maptool::render()
{
	for (int i = 0; i < TILEX * TILEY; ++i)
	{
	_maptile->frameRender(
			_tiles[i].rc.left, _tiles[i].rc.top,
			_tiles[i].terrainFrameX, _tiles[i].terrainFrameY);
	}
	for (int i = 0; i < TILEX * TILEY; ++i)
	{
		if (_tiles[i].obj == OBJ_NONE) continue;

		_object->frameRender(
			_tiles[i].rc.left, _tiles[i].rc.top,
			_tiles[i].objFrameX, _tiles[i].objFrameY);
	}

	if (type==1)
	{
		_maptile->render(WINSIZEX - IMAGEMANAGER->findDImage("object")->getWidth(), 0);
	}
	else if (type==2)
	{
		_object->render(WINSIZEX - IMAGEMANAGER->findDImage("object")->getWidth(), 0);
	}
}

void Maptool::setup()
{
	
	//처음 컨트롤 상태는 지형으로
	_ctrSelect = CTRL_TERRAINDRAW;

	//타일셋 먼저 세팅
	for (int i = 0; i < SAMPLETILEY; ++i)
	{
		for (int j = 0; j < SAMPLETILEX; ++j)
		{
			_sampleTile[i * SAMPLETILEX + j].terrainFrameX = j;
			_sampleTile[i * SAMPLETILEX + j].terrainFrameY = i;

			//타일셋에 렉트를 씌움
			SetRect(&_sampleTile[i * SAMPLETILEX + j].rcTile,
				(WINSIZEX - IMAGEMANAGER->findDImage("object")->getWidth()) + j * TILESIZE,
				i * TILESIZE,
				(WINSIZEX - IMAGEMANAGER->findDImage("object")->getWidth()) + j * TILESIZE + TILESIZE,
				i * TILESIZE + TILESIZE);
		}
	}

	//타일 영역
	for (int i = 0; i < TILEY; ++i)
	{
		for (int j = 0; j < TILEX; ++j)
		{
			SetRect(&_tiles[i * TILEX + j].rc,
				j * TILESIZE,
				i * TILESIZE,
				j * TILESIZE + TILESIZE,
				i * TILESIZE + TILESIZE);
		}
	}


	for (int i = 0; i < TILEX * TILEY; ++i)
	{
		_tiles[i].terrainFrameX = 1;
		_tiles[i].terrainFrameY = 0;
		_tiles[i].objFrameX = 0;
		_tiles[i].objFrameY = 0;
		_tiles[i].terrain = terrainSelect(_tiles[i].terrainFrameX, _tiles[i].terrainFrameY);
		_tiles[i].obj = OBJ_NONE;
	}
}

void Maptool::setMap()
{
	//타일셋에 내가 그리고싶은 타일 또는 오브젝트 클릭
	for (int i = 0; i < SAMPLETILEX * SAMPLETILEY; ++i)
	{
		if (PtInRect(&_sampleTile[i].rcTile, _ptMouse))
		{
			_currentTile.x = _sampleTile[i].terrainFrameX;
			_currentTile.y = _sampleTile[i].terrainFrameY;
			break;
		}
	}

	for (int i = 0; i < TILEX * TILEY; ++i)
	{
		if (PtInRect(&_tiles[i].rc, _ptMouse))
		{
			if (_ctrSelect == CTRL_TERRAINDRAW)
			{
				_tiles[i].terrainFrameX = _currentTile.x;
				_tiles[i].terrainFrameY = _currentTile.y;

				_tiles[i].terrain = terrainSelect(_currentTile.x, _currentTile.y);
			}
			else if (_ctrSelect == CTRL_OBJDRAW)
			{
				_tiles[i].objFrameX = _currentTile.x;
				_tiles[i].objFrameY = _currentTile.y;

				_tiles[i].obj = objSelect(_currentTile.x, _currentTile.y);
			}
			else if (_ctrSelect == CTRL_ERASER)
			{
				_tiles[i].objFrameX = NULL;
				_tiles[i].objFrameY = NULL;
				_tiles[i].obj = OBJ_NONE;
			}

			InvalidateRect(_hWnd, NULL, false);
			break;
		}
	}
}

void Maptool::save()
{
	HANDLE file;
	DWORD write;

	file = CreateFile("tileSave.map", GENERIC_WRITE, NULL, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	WriteFile(file, _tiles, sizeof(tagTile)*TILEX*TILEX, &write, NULL);
	CloseHandle(file);
}

void Maptool::load()
{
	HANDLE file;
	DWORD read;

	file = CreateFile("tileSave.map", GENERIC_READ, NULL, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	ReadFile(file, _tiles, sizeof(tagTile)*TILEX*TILEX, &read, NULL);
	ReadFile(file, _pos, sizeof(int) * 2, &read, NULL);
	CloseHandle(file);
}

void Maptool::minimap()
{
	D2D1_RECT_F rc = CAMERAMANAGER->getScreen();
	for (int i = (TILEX * TILEY); i > 0; --i)
	{
		_maptile->frameRender(
			rc.right-(_tiles[i].rc.left/(TILESIZE/3)), rc.bottom-(_tiles[i].rc.top / (TILESIZE/3)),
			_tiles[i].terrainFrameX, _tiles[i].terrainFrameY, MINITILESIZE, MINITILESIZE);
		
		if (_tiles[i].obj == OBJ_NONE) continue;
		_object->frameRender(
			rc.right - (_tiles[i].rc.left / (TILESIZE / 3)), rc.bottom - (_tiles[i].rc.top / (TILESIZE / 3)),
			_tiles[i].objFrameX, _tiles[i].objFrameY, MINITILESIZE, MINITILESIZE);
	}
}



TERRAIN Maptool::terrainSelect(int frameX, int frameY)
{
	if (frameX == 1 && frameY == 0)
	{
		return TR_CEMENT;
	}
	else if (frameX == 2 && frameY == 0)
	{
		return TR_DESERT;
	}
	else if (frameX == 3 && frameY == 0)
	{
		return TR_GRASS;
	}
	else if (frameX == 4 && frameY == 0)
	{
		return TR_WATER;
	}

	return TR_GRASS;
}

OBJECT Maptool::objSelect(int frameX, int frameY)
{
	if (frameX == 0 && frameY == 0)
	{
		return OBJ_BLOCK1;
	}
	else if (frameX == 0 && frameY == 8)
	{
		return OBJ_TRAP;
	}
	else if (frameX == 0 && frameY == 1)
	{
		return OBJ_BLOCK1;
	}
	else if (frameX == 0 && frameY == 2)
	{
		return OBJ_BLOCK3;
	}
	else if (frameX == 15 && frameY == 3)
	{
		return OBJ_BLOCK8;
	}

	return OBJ_BLOCK1;
}
