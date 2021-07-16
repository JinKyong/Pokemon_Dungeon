#include "stdafx.h"
#include "sampleMap.h"

sampleMap::sampleMap()
{
}

sampleMap::~sampleMap()
{
}

HRESULT sampleMap::init()
{
	_Mapbase=IMAGEMANAGER->addFrameDImage("maptiles", L"img/map/tiles/maptile.png", 768, 384, 16, 8);
	_Obbase=IMAGEMANAGER->addFrameDImage("object", L"img/map/tiles/object.png", 864, 576, SAMPLETILEX, SAMPLETILEY);
	load();
	
	return S_OK;
}

void sampleMap::release()
{
}

void sampleMap::update()
{
}

void sampleMap::render()
{
	for (int i = 0; i < TILEX * TILEY; ++i)
	{
		_Mapbase->frameRender(
			_tile[i].rc.left, _tile[i].rc.top,
			_tile[i].terrainFrameX, _tile[i].terrainFrameY);
	}
	for (int i = 0; i < TILEX * TILEY; ++i)
	{
		if (_tile[i].obj == OBJ_NONE) continue;

		_Obbase->frameRender(
			_tile[i].rc.left, _tile[i].rc.top,
			_tile[i].objFrameX, _tile[i].objFrameY);
	}
}

void sampleMap::load()
{
	HANDLE file;
	DWORD read;

	file = CreateFile("tileSave.map", GENERIC_READ, NULL, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	ReadFile(file, _tile, sizeof(tagTile) * TILEX * TILEY, &read, NULL);
	
	memset(_attribute, 0, sizeof(DWORD) * TILEX * TILEY);
	
	//STEP 01
	//타일을 불러온 다음 타일이 어떤 지형인지 오브젝트인지 분별해서
	//해당 타일에 속성을 부여해줍니다

	for (int i = 0; i < TILEX * TILEY; ++i)
	{
		if (_tile[i].obj == OBJ_WATER) _attribute[i] |= ATTR_WATER;
		if (_tile[i].obj == OBJ_BLOCK1) _attribute[i] |= ATTR_UNMOVE;
		if (_tile[i].obj == OBJ_BLOCK2) _attribute[i] |= ATTR_UNMOVE;
		if (_tile[i].obj == OBJ_BLOCK3) _attribute[i] |= ATTR_UNMOVE;
		if (_tile[i].obj == OBJ_BLOCK4) _attribute[i] |= ATTR_UNMOVE;
		if (_tile[i].obj == OBJ_BLOCK5) _attribute[i] |= ATTR_UNMOVE;
		if (_tile[i].obj == OBJ_BLOCK6) _attribute[i] |= ATTR_UNMOVE;
		if (_tile[i].obj == OBJ_BLOCK7) _attribute[i] |= ATTR_UNMOVE;
		if (_tile[i].obj == OBJ_BLOCK8) _attribute[i] |= ATTR_UNMOVE;
	}



	CloseHandle(file);
}
