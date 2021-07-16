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
	_maptile=IMAGEMANAGER->addFrameDImage("maptiles", L"img/map/tiles/maptile.png", 768, 384, 16, 8);
	_object =IMAGEMANAGER->addFrameDImage("object", L"img/map/tiles/object.png", 864, 576, SAMPLETILEX, SAMPLETILEY);
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
	RECT rc;
	rc = RectMakeCenter(_ptMouse.x, _ptMouse.y, 5, 5);
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
	DTDMANAGER->Rectangle(rc);
	
}

void Maptool::setup()
{
	
	//ó�� ��Ʈ�� ���´� ��������
	_ctrSelect = CTRL_TERRAINDRAW;

	//Ÿ�ϼ� ���� ����
	for (int i = 0; i < SAMPLETILEY; ++i)
	{
		for (int j = 0; j < SAMPLETILEX; ++j)
		{
			_sampleTile[i * SAMPLETILEX + j].terrainFrameX = j;
			_sampleTile[i * SAMPLETILEX + j].terrainFrameY = i;

			//Ÿ�ϼ¿� ��Ʈ�� ����
			SetRect(&_sampleTile[i * SAMPLETILEX + j].rcTile,
				(WINSIZEX - IMAGEMANAGER->findDImage("object")->getWidth()) + j * TILESIZE,
				i * TILESIZE,
				(WINSIZEX - IMAGEMANAGER->findDImage("object")->getWidth()) + j * TILESIZE + TILESIZE,
				i * TILESIZE + TILESIZE);
		}
	}

	//Ÿ�� ����
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
	//Ÿ�ϼ¿� ���� �׸������� Ÿ�� �Ǵ� ������Ʈ Ŭ��
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

	WriteFile(file, _tiles, sizeof(tagTile)*TILEX*TILEY, &write, NULL);
	CloseHandle(file);
}

void Maptool::load()
{
	HANDLE file;
	DWORD read;

	file = CreateFile("tileSave.map", GENERIC_READ, NULL, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	ReadFile(file, _tiles, sizeof(tagTile)*TILEX*TILEY, &read, NULL);

	memset(_attribute, 0, sizeof(DWORD) * TILEX * TILEY);
	memset(_pos, 0, sizeof(int) * 2);

	CloseHandle(file);
}

void Maptool::minimap()
{
	

	D2D1_RECT_F rc = CAMERAMANAGER->getScreen();

	for (int i = 0; i < TILEX * TILEY; ++i)
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

//void Maptool::example(int TerrainX, int TerrainY, int ObjX, int ObjY, OBJECT obj)
//{
//	
//		_tile.terrainFrameX = TerrainX;
//		_tile.terrainFrameY = TerrainY;
//		_tile.objFrameX = ObjX;
//		_tile.objFrameY = ObjY;
//		_tile.terrain = terrainSelect(_tile.terrainFrameX, _tile.terrainFrameY);
//		_tile.obj = obj;
//}



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
	if ((frameX ==6  && frameY == 0)&&
		(frameX ==6 && frameY == 3)&&
		(frameX ==6 && frameY == 6)&&
		(frameX ==6 && frameY == 9)&&
		(frameX == 15 && frameY == 0) &&
		(frameX == 15 && frameY == 3) &&
		(frameX == 15 && frameY == 6) &&
		(frameX == 15 && frameY == 9))
	{
		return OBJ_BLOCK1;
	}
	else if ((frameX ==7 && frameY == 0) &&
			(frameX == 7 && frameY == 3) &&
			(frameX == 7 && frameY == 6) &&
			(frameX == 7 && frameY == 9)&&
			(frameX == 7 && frameY == 2) &&
			(frameX == 7 && frameY == 5) &&
			(frameX == 7 && frameY == 8) &&
			(frameX == 7 && frameY == 11)&&
		(frameX == 16 && frameY == 0) &&
		(frameX == 16 && frameY == 3) &&
		(frameX == 16 && frameY == 6) &&
		(frameX == 16 && frameY == 9) &&
		(frameX == 16 && frameY == 2) &&
		(frameX == 16 && frameY == 5) &&
		(frameX == 16 && frameY == 8) &&
		(frameX == 16 && frameY == 11))
	{
		return OBJ_BLOCK2;
	}
	else if ((frameX ==8 && frameY == 0) &&
			(frameX ==8 && frameY == 3) &&
			(frameX ==8 && frameY == 6) &&
			(frameX ==8 && frameY == 9)&&
		(frameX == 17 && frameY == 0) &&
		(frameX == 17 && frameY == 3) &&
		(frameX == 17 && frameY == 6) &&
		(frameX == 17 && frameY == 9))
	{
		return OBJ_BLOCK3;
	}
	else if ((frameX == 6 && frameY == 1) &&
			(frameX == 6 && frameY == 4) &&
			(frameX == 6 && frameY == 7) &&
			(frameX == 6 && frameY == 10) &&
			(frameX == 8 && frameY == 1) &&
			(frameX == 8 && frameY == 4) &&
			(frameX == 8 && frameY == 7) &&
			(frameX == 8 && frameY == 10)&&
		(frameX == 15 && frameY == 1) &&
		(frameX == 15 && frameY == 4) &&
		(frameX == 15 && frameY == 7) &&
		(frameX == 15 && frameY == 10) &&
		(frameX == 17 && frameY == 1) &&
		(frameX == 17 && frameY == 4) &&
		(frameX == 17 && frameY == 7) &&
		(frameX == 17 && frameY == 10))
	{
		return OBJ_BLOCK4;
	}
	else if ((frameX ==7 && frameY == 1) &&
			(frameX == 7 && frameY == 4) &&
			(frameX == 7 && frameY == 7) &&
			(frameX == 7 && frameY == 10)&&
		(frameX == 16 && frameY == 1) &&
		(frameX == 16 && frameY == 4) &&
		(frameX == 16 && frameY == 7) &&
		(frameX == 16 && frameY == 10))
	{
		return OBJ_BLOCK5;
	}
	else if ((frameX ==6 && frameY == 2) &&
			(frameX == 6 && frameY == 5) &&
			(frameX == 6 && frameY == 8) &&
			(frameX == 6 && frameY == 11)&&
		(frameX == 15 && frameY == 2) &&
		(frameX == 15 && frameY == 5) &&
		(frameX == 15 && frameY == 8) &&
		(frameX == 15 && frameY == 11))
	{
		return OBJ_BLOCK6;
	}
	else if ((frameX ==8 && frameY == 2) &&
			(frameX == 8 && frameY == 5) &&
			(frameX == 8 && frameY == 8) &&
			(frameX == 8 && frameY == 11)&&
		(frameX == 17 && frameY == 2) &&
		(frameX == 17 && frameY == 5) &&
		(frameX == 17 && frameY == 8) &&
		(frameX == 17 && frameY == 11))
	{
		return OBJ_BLOCK7;
	}
	else if ((frameX == 3 && frameY == 0) &&
		(frameX == 3 && frameY == 1) &&
		(frameX == 3 && frameY == 2) &&
		(frameX == 4 && frameY == 0) &&
		(frameX == 4 && frameY == 1) &&
		(frameX == 4 && frameY == 2) &&
		(frameX == 5 && frameY == 0) &&
		(frameX == 5 && frameY == 1) && 
		(frameX == 5 && frameY == 2)&&
		(frameX == 3 && frameY == 3) &&
		(frameX == 3 && frameY == 4) &&
		(frameX == 3 && frameY == 5) &&
		(frameX == 4 && frameY == 3) &&
		(frameX == 4 && frameY == 4) &&
		(frameX == 4 && frameY == 5) &&
		(frameX == 5 && frameY == 3) &&
		(frameX == 5 && frameY == 4) &&
		(frameX == 5 && frameY == 5) &&
		(frameX == 3 && frameY == 6) &&
		(frameX == 3 && frameY == 7) &&
		(frameX == 3 && frameY == 8) &&
		(frameX == 4 && frameY == 6) &&
		(frameX == 4 && frameY == 7) &&
		(frameX == 4 && frameY == 8) &&
		(frameX == 5 && frameY == 6) &&
		(frameX == 5 && frameY == 7) &&
		(frameX == 5 && frameY == 8) &&
		(frameX == 3 && frameY == 9) &&
		(frameX == 3 && frameY == 10) &&
		(frameX == 3 && frameY == 11) &&
		(frameX == 4 && frameY == 9) &&
		(frameX == 4 && frameY == 10) &&
		(frameX == 4 && frameY == 11) &&
		(frameX == 5 && frameY == 9) &&
		(frameX == 5 && frameY == 10) &&
		(frameX == 5 && frameY == 11) &&
		(frameX == 12 && frameY == 0) &&
		(frameX == 12 && frameY == 1) &&
		(frameX == 12 && frameY == 2) &&
		(frameX == 13 && frameY == 0) &&
		(frameX == 13 && frameY == 1) &&
		(frameX == 13 && frameY == 2) &&
		(frameX == 14 && frameY == 0) &&
		(frameX == 14 && frameY == 1) &&
		(frameX == 14 && frameY == 2) &&
		(frameX == 12 && frameY == 3) &&
		(frameX == 12 && frameY == 4) &&
		(frameX == 12 && frameY == 5) &&
		(frameX == 13 && frameY == 3) &&
		(frameX == 13 && frameY == 4) &&
		(frameX == 13 && frameY == 5) &&
		(frameX == 14 && frameY == 3) &&
		(frameX == 14 && frameY == 4) &&
		(frameX == 14 && frameY == 5) &&
		(frameX == 12 && frameY == 6) &&
		(frameX == 12 && frameY == 7) &&
		(frameX == 12 && frameY == 8) &&
		(frameX == 13 && frameY == 6) &&
		(frameX == 13 && frameY == 7) &&
		(frameX == 13 && frameY == 8) &&
		(frameX == 14 && frameY == 6) &&
		(frameX == 14 && frameY == 7) &&
		(frameX == 14 && frameY == 8) &&
		(frameX == 12 && frameY == 9) &&
		(frameX == 12 && frameY == 10) &&
		(frameX == 12 && frameY == 11) &&
		(frameX == 13 && frameY == 9) &&
		(frameX == 13 && frameY == 10) &&
		(frameX == 13 && frameY == 11) &&
		(frameX == 14 && frameY == 9) &&
		(frameX == 14 && frameY == 10) &&
		(frameX == 14 && frameY == 11))
	{
		return OBJ_WATER;
	}

	return OBJ_BLOCK8;
}
