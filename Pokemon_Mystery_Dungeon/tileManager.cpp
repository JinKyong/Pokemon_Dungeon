#include "stdafx.h"
#include "tileManager.h"

tileManager::tileManager()
{
}

tileManager::~tileManager()
{
}

HRESULT tileManager::init()
{
	return S_OK;
}

HRESULT tileManager::init(int width, int height)
{
	_width = width;
	_height = height;

	_Mapbase = IMAGEMANAGER->addFrameDImage("maptiles", L"img/map/tiles/maptile.png", 768, 384, 16, 8);
	_Obbase = IMAGEMANAGER->addFrameDImage("object", L"img/map/tiles/object.png", 864, 576, SAMPLETILEX, SAMPLETILEY);
	dungeon(_width, _height);
	setup();
	
	return S_OK;
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
	if (_endX >= _width)
		_endX = _width - 1;
	if (_initY < 0)
		_initY = 0;
	if (_endY >= _height)
		_endY = _height - 1;
}

void tileManager::render()
{
	for (int i = _initY; i <= _endY; i++)
		for (int j = _initX; j <= _endX; j++) {
			int index = i * _width + j;

			_Mapbase->frameRender(
				_vTile[index]->rc.left, _vTile[index]->rc.top,
				_vTile[index]->terrainFrameX, _vTile[index]->terrainFrameY);

			if (PRINTMANAGER->isDebug())
				DTDMANAGER->Rectangle(_vTile[index]->rc);
		}

	for (int i = _initY; i <= _endY; i++)
		for (int j = _initX; j <= _endX; j++) {
			int index = i * _width + j;

			if (_vTile[index]->obj == OBJ_NONE) continue;

			_Obbase->frameRender(
				_vTile[index]->rc.left, _vTile[index]->rc.top,
				_vTile[index]->objFrameX, _vTile[index]->objFrameY);

			if (PRINTMANAGER->isDebug())
				DTDMANAGER->Rectangle(_vTile[index]->rc);
		}
	if (PRINTMANAGER->isDebug())
		minimap();
}
void tileManager::setup()
{
	for (int i = 0; i < _height; ++i)
	{
		for (int j = 0; j < _width; ++j)
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

	int i = 0;
	for (_viChar=_vChar.begin(); _viChar != _vChar.end(); ++_viChar,i++)
		{
			if ((*_viChar) == Unused)
			{
				_vTile[i]->terrainFrameX = 3;
				_vTile[i]->terrainFrameY = 1;
				_vTile[i]->objFrameX = 0;
				_vTile[i]->objFrameY = 0;
				_vTile[i]->terrain = terrainSelect(_vTile[i] ->terrainFrameX, _vTile[i]->terrainFrameY);
				_vTile[i]->obj = OBJ_NONE;
			}
			else if ((*_viChar) == Wall)
			{
				_vTile[i]->terrainFrameX = 1;
				_vTile[i]->terrainFrameY = 0;
				_vTile[i]->objFrameX = 1;
				_vTile[i]->objFrameY = 0;
				_vTile[i]->terrain = terrainSelect(_vTile[i]->terrainFrameX, _vTile[i]->terrainFrameY);
				_vTile[i]->obj = objSelect(_vTile[i]->objFrameX, _vTile[i]->objFrameY);
			}
			else if ((*_viChar) == UpStairs)
			{
				_vTile[i]->terrainFrameX = 1;
				_vTile[i]->terrainFrameY = 0;
				_vTile[i]->objFrameX = 3;
				_vTile[i]->objFrameY = 2;
				_vTile[i]->terrain = terrainSelect(_vTile[i]->terrainFrameX, _vTile[i]->terrainFrameY);
				_vTile[i]->obj = objSelect(_vTile[i]->objFrameX, _vTile[i]->objFrameY);
			}
			else if ((*_viChar) == DownStairs)
			{
				_vTile[i]->terrainFrameX = 1;
				_vTile[i]->terrainFrameY = 0;
				_vTile[i]->objFrameX = 6;
				_vTile[i]->objFrameY = 3;
				_vTile[i]->terrain = terrainSelect(_vTile[i]->terrainFrameX, _vTile[i]->terrainFrameY);
				_vTile[i]->obj = objSelect(_vTile[i]->objFrameX, _vTile[i]->objFrameY);
			}
			else
			{
				_vTile[i]->terrainFrameX = 1;
				_vTile[i]->terrainFrameY = 0;
				_vTile[i]->objFrameX = 0;
				_vTile[i]->objFrameY = 0;
				_vTile[i]->terrain = terrainSelect(_vTile[i]->terrainFrameX, _vTile[i]->terrainFrameY);
				_vTile[i]->obj = OBJ_NONE;
			}
		}
	
}


//void tileManager::save(const char* mapName)
//{
//	HANDLE file;
//	DWORD write;
//
//	file = CreateFile(mapName, GENERIC_WRITE, NULL, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
//
//	WriteFile(file, &_vTile, sizeof(tagTile)*TILEX*TILEY, &write, NULL);
//	CloseHandle(file);
//}
//
//void tileManager::load(const char* mapName)
//{
//	HANDLE file;
//	DWORD read;
//
//	file = CreateFile(mapName, GENERIC_READ, NULL, NULL,
//		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
//
//	ReadFile(file, &_vTile, sizeof(tagTile)*TILEX*TILEY, &read, NULL);
//
//	memset(_attribute, 0, sizeof(DWORD) * TILEX * TILEY);
//
//	CloseHandle(file);
//}
//void tileManager::save(const char * mapName)
//{
//	HANDLE file;
//	DWORD write;
//
//	file = CreateFile(mapName, GENERIC_WRITE, NULL, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
//
//	WriteFile(file, _tile, sizeof(tagTile)*TILEX*TILEY, &write, NULL);
//	CloseHandle(file);
//}
//
//void tileManager::load(const char* mapName)
//{
//	HANDLE file;
//	DWORD read;
//
//	file = CreateFile(mapName, GENERIC_READ, NULL, NULL,
//		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
//
//	ReadFile(file, _tile, sizeof(tagTile) * TILEX * TILEY, &read, NULL);
//
//	memset(_attribute, 0, sizeof(DWORD) * TILEX * TILEY);
//
//	//STEP 01
//	//타일을 불러온 다음 타일이 어떤 지형인지 오브젝트인지 분별해서
//	//해당 타일에 속성을 부여해줍니다
//
//	for (int i = 0; i < TILEX * TILEY; ++i)
//	{
//		if (_tile[i].obj == OBJ_BLOCK1) _attribute[i] |= ATTR_UNMOVE;
//		else if (_tile[i].obj == OBJ_BLOCK2) _attribute[i] |= ATTR_UNMOVE;
//		else if (_tile[i].obj == OBJ_BLOCK3) _attribute[i] |= ATTR_UNMOVE;
//		else if (_tile[i].obj == OBJ_BLOCK4) _attribute[i] |= ATTR_UNMOVE;
//		else if (_tile[i].obj == OBJ_BLOCK5) _attribute[i] |= ATTR_UNMOVE;
//		else if (_tile[i].obj == OBJ_BLOCK6) _attribute[i] |= ATTR_UNMOVE;
//		else if (_tile[i].obj == OBJ_BLOCK7) _attribute[i] |= ATTR_UNMOVE;
//		else if (_tile[i].obj == OBJ_BLOCK8) _attribute[i] |= ATTR_UNMOVE;
//		else if (_tile[i].obj == OBJ_WATER) _attribute[i] |= ATTR_WATER;
//	}
//
//
//
//	CloseHandle(file);
//}

void tileManager::minimap()
{
	D2D1_RECT_F rc = CAMERAMANAGER->getScreen();

	for (int i = 0; i < _width * _height; ++i)
	{
		
		_Mapbase->frameRender(
			rc.right - (_vTile[i]->rc.left / (TILESIZE / 3)), rc.bottom - (_vTile[i]->rc.top / (TILESIZE / 3)),
			_vTile[i]->terrainFrameX, _vTile[i]->terrainFrameY, MINITILESIZE, MINITILESIZE);

		if (_vTile[i]->obj == OBJ_NONE) continue;
		_Obbase->frameRender(
			rc.right - (_vTile[i]->rc.left / (TILESIZE / 3)), rc.bottom - (_vTile[i]->rc.top / (TILESIZE / 3)),
			_vTile[i]->objFrameX, _vTile[i]->objFrameY, MINITILESIZE, MINITILESIZE);
	}
}

void tileManager::dungeon(int width, int height)
{
	_vExit.clear();
	_vRoom.clear();
	for (int i = 0; i < width*height; ++i)
	{
		_vChar.push_back(Unused);
	}
	generate((width+height) / 15);
}

void tileManager::generate(int maxFeatures)
{
	// place the first room in the center
	//_width에 비율 주는걸로 첫방 X위치 조절가능, _height는 Y위치, 기본은 중앙인 1/2
	if (!makeRoom(_width/2 , _height/2, static_cast<Direction>(RND->getInt(4), true)))
	{
		return;
	}
	// we already placed 1 feature (the first room)
	//2번째 구조 생성(1번째는 무조건 첫방)
	for (int i = 1; i < maxFeatures; ++i)
	{
		if (!createFeature())
		{
			break;
		}
	}
	//윗계단 생성자 
	if (!placeObject(UpStairs))
	{
		return;
	}
	//아랫계단 생성자
	if (!placeObject(DownStairs))
	{
		return;
	}
}

bool tileManager::createFeature()
{
	for (int i = 0; i < 1000; ++i)
	{
		if (_vExit.empty())
			break;

		// choose a random side of a random room or corridor
		int r = RND->getInt(_vExit.size());
		int x = RND->getFromIntTo(_vExit[r].x-1, _vExit[r].x + _vExit[r].width-1 );
		int y = RND->getFromIntTo(_vExit[r].y-1, _vExit[r].y + _vExit[r].height-1 );

		// north, south, west, east
		//j= 방향, 방향에 따른 방/복도 생성
		for (int j = 0; j < DirectionCount; ++j)
		{
			if (createFeature(x, y, static_cast<Direction>(j)))
			{
				_vExit.erase(_vExit.begin() + r);
				return true;
			}
		}
	}

	return false;
}

bool tileManager::createFeature(int x, int y, Direction dir)
{
	//방 생성 확률
	static const int roomChance = 50; // corridorChance = 100 - roomChance

	int dx = 0;
	int dy = 0;
	

	if (dir == North)
		dy = 1;
	else if (dir == South)
		dy = -1;
	else if (dir == West)
		dx = 1;
	else if (dir == East)
		dx = -1;

	//출구가 있나 없나 확인
	if (getChar(x + dx, y + dy) != Floor && getChar(x + dx, y + dy) != Corridor)
		return false;

	if (RND->getInt(100) < roomChance)
	{
		if (makeRoom(x, y, dir))
		{
			setChar(x, y, ClosedDoor);

			return true;
		}
	}

	else
	{
		if (makeCorridor(x, y, dir))
		{
			if (getChar(x + dx, y + dy) == Floor)
				setChar(x, y, ClosedDoor);
			else // don't place a door between corridors
				setChar(x, y, Corridor);

			return true;
		}
	}
	return false;
}

bool tileManager::makeRoom(int x, int y, Direction dir, bool firstRoom)
{
	static const int minRoomSize = 2;
	static const int maxRoomSize = 5;

	tagRect room;
	room.width = RND->getFromIntTo(minRoomSize, maxRoomSize);
	room.height = RND->getFromIntTo(minRoomSize, maxRoomSize);

	if (dir == North)
	{
		room.x = x - room.width / 2;
		room.y = y - room.height;
	}

	else if (dir == South)
	{
		room.x = x - room.width / 2;
		room.y = y + 1;
	}

	else if (dir == West)
	{
		room.x = x - room.width;
		room.y = y - room.height / 2;
	}

	else if (dir == East)
	{
		room.x = x + 1;
		room.y = y - room.height / 2;
	}

	if (placeRect(room, Floor))
	{
		_vRoom.emplace_back(room);

		if (dir!= South) // north side
			_vExit.emplace_back(tagRect{ room.x, room.y - 1, RND->getInt(room.width), 1 });
		 if (dir != North) // south side
			_vExit.emplace_back(tagRect{ room.x, room.y + room.height, room.width, 1 });
		 if (dir != East) // west side
			_vExit.emplace_back(tagRect{ room.x - 1, room.y, 1, room.height });
		 if (dir != West) // east side
			_vExit.emplace_back(tagRect{ room.x + room.width, room.y, 1, room.height });

		return true;
	}
	return false;
}

bool tileManager::makeCorridor(int x, int y, Direction dir)
{
	static const int minCorridorLength = 5;
	static const int maxCorridorLength = 8;

	tagRect corridor;
	corridor.x = x;
	corridor.y = y;
	//확률로 왼/오 윗/아래 설정
	bool k = RND->getBool();

	if (k) // horizontal corridor
	{
		corridor.width = RND->getFromIntTo(minCorridorLength, maxCorridorLength);
		corridor.height = 1;

		if (dir == North)
		{
			corridor.y = y - 1;
			k = RND->getBool();
			if (k) // west
				corridor.x = x - corridor.width + 1;
		}

		else if (dir == South)
		{
			corridor.y = y + 1;
			k = RND->getBool();
			if (k) // west
				corridor.x = x - corridor.width + 1;
		}

		else if (dir == West)
			corridor.x = x - corridor.width;

		else if (dir == East)
			corridor.x = x + 1;
	}

	else // vertical corridor
	{
		corridor.width = 1;
		corridor.height = RND->getFromIntTo(minCorridorLength, maxCorridorLength);

		if (dir == North)
			corridor.y = y - corridor.height;

		else if (dir == South)
			corridor.y = y + 1;

		else if (dir == West)
		{
			corridor.x = x - 1;
			k = RND->getBool();
			if (k) // north
				corridor.y = y - corridor.height + 1;
		}

		else if (dir == East)
		{
			corridor.x = x + 1;
			k = RND->getBool();
			if (k) // north
				corridor.y = y - corridor.height + 1;
		}
	}

	if (placeRect(corridor, Corridor))
	{
		if (dir != South && corridor.width != 1) // north side
			_vExit.emplace_back(tagRect{ corridor.x, corridor.y - 1, corridor.width, 1 });
		if (dir != North && corridor.width != 1) // south side
			_vExit.emplace_back(tagRect{ corridor.x, corridor.y + corridor.height, corridor.width, 1 });
		if (dir != East && corridor.height != 1) // west side
			_vExit.emplace_back(tagRect{ corridor.x - 1, corridor.y, 1, corridor.height });
		if (dir != West && corridor.height != 1) // east side
			_vExit.emplace_back(tagRect{ corridor.x + corridor.width, corridor.y, 1, corridor.height });

		return true;
	}
	return false;
}

bool tileManager::placeRect(const tagRect & tag, char Char)
{
	if (tag.x < 1 || tag.y < 1 || tag.x + tag.width > _width - 1 || tag.y + tag.height > _height - 1)
		return false;

	for (int y = tag.y; y < tag.y + tag.height; ++y)
		for (int x = tag.x; x < tag.x + tag.width; ++x)
		{
			if (getChar(x, y) != Unused)
				return false; // the area already used
		}

	for (int y = tag.y - 1; y < tag.y + tag.height + 1; ++y)
		for (int x = tag.x - 1; x < tag.x + tag.width + 1; ++x)
		{
			if (x == tag.x - 1 || y == tag.y - 1 || x == tag.x + tag.width || y == tag.y + tag.height)
				setChar(x, y, Wall);
			else
				setChar(x, y, Char);
		}

	return true;
}

bool tileManager::placeObject(char Char)
{
	if (_vRoom.empty())
		return false;

	int r = RND->getInt(_vRoom.size()); // choose a random room
	int x = RND->getFromIntTo(_vRoom[r].x + 1, _vRoom[r].x + _vRoom[r].width - 1);
	int y = RND->getFromIntTo(_vRoom[r].y, _vRoom[r].y + _vRoom[r].height - 1);

	if (getChar(x, y) == Floor)
	{
		setChar(x, y, Char);

		// place one object in one room (optional)
		_vRoom.erase(_vRoom.begin() + r);

		return true;
	}

	return false;
}

TERRAIN tileManager::terrainSelect(int frameX, int frameY)
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

OBJECT tileManager::objSelect(int frameX, int frameY)
{
	if ((frameX == 6 && frameY == 0) &&
		(frameX == 6 && frameY == 3) &&
		(frameX == 6 && frameY == 6) &&
		(frameX == 6 && frameY == 9) &&
		(frameX == 15 && frameY == 0) &&
		(frameX == 15 && frameY == 3) &&
		(frameX == 15 && frameY == 6) &&
		(frameX == 15 && frameY == 9))
	{
		return OBJ_BLOCK1;
	}
	else if ((frameX == 7 && frameY == 0) &&
		(frameX == 7 && frameY == 3) &&
		(frameX == 7 && frameY == 6) &&
		(frameX == 7 && frameY == 9) &&
		(frameX == 7 && frameY == 2) &&
		(frameX == 7 && frameY == 5) &&
		(frameX == 7 && frameY == 8) &&
		(frameX == 7 && frameY == 11) &&
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
	else if ((frameX == 8 && frameY == 0) &&
		(frameX == 8 && frameY == 3) &&
		(frameX == 8 && frameY == 6) &&
		(frameX == 8 && frameY == 9) &&
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
		(frameX == 8 && frameY == 10) &&
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
	else if ((frameX == 7 && frameY == 1) &&
		(frameX == 7 && frameY == 4) &&
		(frameX == 7 && frameY == 7) &&
		(frameX == 7 && frameY == 10) &&
		(frameX == 16 && frameY == 1) &&
		(frameX == 16 && frameY == 4) &&
		(frameX == 16 && frameY == 7) &&
		(frameX == 16 && frameY == 10))
	{
		return OBJ_BLOCK5;
	}
	else if ((frameX == 6 && frameY == 2) &&
		(frameX == 6 && frameY == 5) &&
		(frameX == 6 && frameY == 8) &&
		(frameX == 6 && frameY == 11) &&
		(frameX == 15 && frameY == 2) &&
		(frameX == 15 && frameY == 5) &&
		(frameX == 15 && frameY == 8) &&
		(frameX == 15 && frameY == 11))
	{
		return OBJ_BLOCK6;
	}
	else if ((frameX == 8 && frameY == 2) &&
		(frameX == 8 && frameY == 5) &&
		(frameX == 8 && frameY == 8) &&
		(frameX == 8 && frameY == 11) &&
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
		(frameX == 5 && frameY == 2) &&
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
