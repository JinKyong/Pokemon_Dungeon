#include "stdafx.h"
#include "tileManager.h"

tileManager::tileManager()
{
}

tileManager::~tileManager()
{
}

void tileManager::init()
{
	_Mapbase = IMAGEMANAGER->addFrameDImage("maptiles", L"img/map/tiles/maptile.png", 768, 384, 16, 8);
	_Obbase = IMAGEMANAGER->addFrameDImage("object", L"img/map/tiles/object.png", 864, 576, SAMPLETILEX, SAMPLETILEY);
}

void tileManager::release()
{
}

void tileManager::update()
{
	//이미지 클리핑(렌더 범위/인덱스 설정)
	//->카메라 스크린 기준으로
	D2D1_RECT_F screen = CAMERAMANAGER->getScreen();

	_initX = screen.left / TILEWIDTH - 1;
	_endX = screen.right / TILEWIDTH + 1;
	_initY = screen.top / TILEHEIGHT - 1;
	_endY = screen.bottom / TILEHEIGHT + 1;

	if (_initX < 0)
		_initX = 0;
	if (_endX >= TILEX)
		_endX = TILEX - 1;
	if (_initY < 0)
		_initY = 0;
	if (_endY >= TILEY)
		_endY = TILEY - 1;
}

void tileManager::render()
{
	for (int i = _initY; i <= _endY; i++)
		for (int j = _initX; j <= _endX; j++) {
			int index = i * TILEX + j;

			_Mapbase->frameRender(
				_tile[index].rc.left, _tile[index].rc.top,
				_tile[index].terrainFrameX, _tile[index].terrainFrameY);

			if (PRINTMANAGER->isDebug())
				DTDMANAGER->Rectangle(_tile[index].rc);
		}

	for (int i = _initY; i <= _endY; i++)
		for (int j = _initX; j <= _endX; j++) {
			int index = i * TILEX + j;

			if (_tile[index].obj == OBJ_NONE) continue;

			_Obbase->frameRender(
				_tile[index].rc.left, _tile[index].rc.top,
				_tile[index].objFrameX, _tile[index].objFrameY);

			if (PRINTMANAGER->isDebug())
				DTDMANAGER->Rectangle(_tile[index].rc);
		}
}

void tileManager::load(const char* mapName)
{
	HANDLE file;
	DWORD read;

	file = CreateFile(mapName, GENERIC_READ, NULL, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	ReadFile(file, _tile, sizeof(tagTile) * TILEX * TILEY, &read, NULL);

	memset(_attribute, 0, sizeof(DWORD) * TILEX * TILEY);

	//STEP 01
	//타일을 불러온 다음 타일이 어떤 지형인지 오브젝트인지 분별해서
	//해당 타일에 속성을 부여해줍니다

	for (int i = 0; i < TILEX * TILEY; ++i)
	{
		if (_tile[i].obj == OBJ_BLOCK1) _attribute[i] |= ATTR_UNMOVE;
		else if (_tile[i].obj == OBJ_BLOCK2) _attribute[i] |= ATTR_UNMOVE;
		else if (_tile[i].obj == OBJ_BLOCK3) _attribute[i] |= ATTR_UNMOVE;
		else if (_tile[i].obj == OBJ_BLOCK4) _attribute[i] |= ATTR_UNMOVE;
		else if (_tile[i].obj == OBJ_BLOCK5) _attribute[i] |= ATTR_UNMOVE;
		else if (_tile[i].obj == OBJ_BLOCK6) _attribute[i] |= ATTR_UNMOVE;
		else if (_tile[i].obj == OBJ_BLOCK7) _attribute[i] |= ATTR_UNMOVE;
		else if (_tile[i].obj == OBJ_BLOCK8) _attribute[i] |= ATTR_UNMOVE;
		else if (_tile[i].obj == OBJ_WATER) _attribute[i] |= ATTR_WATER;
	}



	CloseHandle(file);
}
