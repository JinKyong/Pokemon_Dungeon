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
	if (KEYMANAGER->isStayKeyDown(VK_RBUTTON)) { _ctrSelect = CTRL_ERASER; setMap(); }

	if (type == 1 && KEYMANAGER->isStayKeyDown(VK_LBUTTON)) { _ctrSelect = CTRL_TERRAINDRAW; setMap(); }
	if (type == 2 && KEYMANAGER->isStayKeyDown(VK_LBUTTON)) { _ctrSelect = CTRL_OBJDRAW; setMap(); }
	


	if (type <= 0)type = 1;
	if (type >= 4)type = 3;

	
}

void Maptool::render()
{
	
	D2D1_RECT_F _rc =CAMERAMANAGER->getScreen();
	RECT rc;
	rc = RectMakeCenter(_ptMouse.x, _ptMouse.y, 5, 5);
	for (int i = 0; i < TILEX * TILEY; ++i)
	{
	_maptile->frameRender(
			_vTile[i]->rc.left, _vTile[i]->rc.top,
			_vTile[i]->terrainFrameX, _vTile[i]->terrainFrameY);
	}
	for (int i = 0; i < TILEX * TILEY; ++i)
	{
		if (_vTile[i]->obj == OBJ_NONE) continue;

		_object->frameRender(
			_vTile[i]->rc.left, _vTile[i]->rc.top,
			_vTile[i]->objFrameX, _vTile[i]->objFrameY);
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
	
	//처음 컨트롤 상태는 지형으로
	_ctrSelect = CTRL_TERRAINDRAW;

	//타일셋 먼저 세팅
	for (int i = 0; i < SAMPLETILEY; ++i)
	{
		for (int j = 0; j < SAMPLETILEX; ++j)
		{
			PSTILE sampleTile;
			sampleTile = new STILE;
			
			sampleTile->terrainFrameX = j;
			sampleTile->terrainFrameY = i;
			
			//타일셋에 렉트를 씌움
			SetRect(&sampleTile->rcTile,
				(WINSIZEX - IMAGEMANAGER->findDImage("object")->getWidth()) + j * TILESIZE,
				i * TILESIZE,
				(WINSIZEX - IMAGEMANAGER->findDImage("object")->getWidth()) + j * TILESIZE + TILESIZE,
				i * TILESIZE + TILESIZE);
			_vSampleTile.push_back(sampleTile);
		}
	}

	//타일 영역
	for (int i = 0; i < TILEY; ++i)
	{
		for (int j = 0; j < TILEX; ++j)
		{
			PTILE Tile;
			Tile = new TILE;
			SetRect(&Tile->rc,
				j * TILESIZE,
				i * TILESIZE,
				j * TILESIZE + TILESIZE,
				i * TILESIZE + TILESIZE);
			_vTile.push_back(Tile);
		}
	}


	for (int i = 0; i < TILEX * TILEY; ++i)
	{
		_vTile[i]->terrainFrameX = 1;
		_vTile[i]->terrainFrameY = 0;
		_vTile[i]->objFrameX = 0;
		_vTile[i]->objFrameY = 0;
		_vTile[i]->terrain = terrainSelect(_vTile[i]->terrainFrameX, _vTile[i]->terrainFrameY);
		_vTile[i]->obj = OBJ_NONE;
	}
}

void Maptool::setMap()
{
	
	//타일셋에 내가 그리고싶은 타일 또는 오브젝트 클릭
	for (int i = 0; i < SAMPLETILEX * SAMPLETILEY; ++i)
	{
		if (PtInRect(&_vSampleTile[i]->rcTile, _ptMouse))
		{
			_currentTile.x = _vSampleTile[i]->terrainFrameX;
			_currentTile.y = _vSampleTile[i]->terrainFrameY;
			break;
		}
	}

	for (int i = 0; i < TILEX * TILEY; ++i)
	{
		if (PtInRect(&_vTile[i]->rc, _ptMouse))
		{
			if (_ctrSelect == CTRL_TERRAINDRAW)
			{
				_vTile[i]->terrainFrameX = _currentTile.x;
				_vTile[i]->terrainFrameY = _currentTile.y;

				_vTile[i]->terrain = terrainSelect(_currentTile.x, _currentTile.y);
			}
			else if (_ctrSelect == CTRL_OBJDRAW)
			{
				_vTile[i]->objFrameX = _currentTile.x;
				_vTile[i]->objFrameY = _currentTile.y;

				_vTile[i]->obj = objSelect(_currentTile.x, _currentTile.y);
			}
			else if (_ctrSelect == CTRL_ERASER)
			{
				_vTile[i]->objFrameX = NULL;
				_vTile[i]->objFrameY = NULL;
				_vTile[i]->obj = OBJ_NONE;
			}

			InvalidateRect(_hWnd, NULL, false);
			break;
		}
	}
}



void Maptool::minimap()
{
	

	//D2D1_RECT_F rc = CAMERAMANAGER->getScreen();
	//
	//for (int i = 0; i < TILEX * TILEY; ++i)
	//{
	//	_maptile->frameRender(
	//		rc.right-(_vTile[i]->rc.left/(TILESIZE/3)), rc.bottom-(_vTile[i]->rc.top / (TILESIZE/3)),
	//		_vTile[i]->terrainFrameX, _vTile[i]->terrainFrameY, MINITILESIZE, MINITILESIZE);
	//	
	//	if (_vTile[i]->obj == OBJ_NONE) continue;
	//	_object->frameRender(
	//		rc.right - (_vTile[i]->rc.left / (TILESIZE / 3)), rc.bottom - (_vTile[i]->rc.top / (TILESIZE / 3)),
	//		_vTile[i]->objFrameX, _vTile[i]->objFrameY, MINITILESIZE, MINITILESIZE);
	//}
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

