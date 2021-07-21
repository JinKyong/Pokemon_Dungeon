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
	//전체 맵 크기 설정
	_width = width;
	_height = height;

	//타일맵 이미지 등록
	_Mapbase = IMAGEMANAGER->addFrameDImage("maptiles", L"img/map/tiles/maptile.png", 768, 384, 16, 8);
	_Obbase = IMAGEMANAGER->addFrameDImage("object", L"img/map/tiles/object.png", 864, 576, 18, 12);

	//던전 랜덤 생성
	dungeon(_width, _height);
	//생성된 맵 -> 타일로 변환
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
	//정해진 범위의 타일만 render
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

	//미니맵(이거 키면 (진경 컴퓨터 기준)렉 걸림)
	if (PRINTMANAGER->isDebug())
		minimap();
}
void tileManager::setup()
{
	//타일 rect생성해서 넣어주고
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
			Tile->x = j;
			Tile->y = i;
			_vTile.push_back(Tile);
		}
	}

	int i = 0;
	vector<char>::iterator _viChar;

	//랜던생성된 맵 정보 기반으로 타일 이미지와 속성 매핑
	for (_viChar=_vChar.begin(); _viChar != _vChar.end(); ++_viChar,i++)
		{
			if ((*_viChar) == Unused)
			{
				_vTile[i]->terrainFrameX = 3;
				_vTile[i]->terrainFrameY = 1;
				_vTile[i]->objFrameX = 1;
				_vTile[i]->objFrameY = 1;
				_vTile[i]->terrain = terrainSelect(_vTile[i] ->terrainFrameX, _vTile[i]->terrainFrameY);
				_vTile[i]->obj = objSelect(_vTile[i]->objFrameX, _vTile[i]->objFrameY);
			}
			
			else if ((*_viChar) == UpStairs)
			{
				_vTile[i]->terrainFrameX = 1;
				_vTile[i]->terrainFrameY = 0;
				_vTile[i]->objFrameX = 3;
				_vTile[i]->objFrameY = 2;
				_vTile[i]->terrain = terrainSelect(_vTile[i]->terrainFrameX, _vTile[i]->terrainFrameY);
				_vTile[i]->obj = OBJ_BLOCK1;
			}
			else if ((*_viChar) == DownStairs)
			{
				_vTile[i]->terrainFrameX = 1;
				_vTile[i]->terrainFrameY = 0;
				_vTile[i]->objFrameX = 6;
				_vTile[i]->objFrameY = 3;
				_vTile[i]->terrain = terrainSelect(_vTile[i]->terrainFrameX, _vTile[i]->terrainFrameY);
				_vTile[i]->obj = OBJ_BLOCK1;
			}
			else if ((*_viChar) == LeftCorner)
			{
				_vTile[i]->terrainFrameX = 1;
				_vTile[i]->terrainFrameY = 0;
				_vTile[i]->objFrameX = 6;
				_vTile[i]->objFrameY = 0;
				_vTile[i]->terrain = terrainSelect(_vTile[i]->terrainFrameX, _vTile[i]->terrainFrameY);
				_vTile[i]->obj = OBJ_BLOCK1;
			}
			else if ((*_viChar) == RightCorner)
			{
				_vTile[i]->terrainFrameX = 1;
				_vTile[i]->terrainFrameY = 0;
				_vTile[i]->objFrameX = 8;
				_vTile[i]->objFrameY = 0;
				_vTile[i]->terrain = terrainSelect(_vTile[i]->terrainFrameX, _vTile[i]->terrainFrameY);
				_vTile[i]->obj = OBJ_BLOCK1;
			}
			else if ((*_viChar) == LeftBottom)
			{
				_vTile[i]->terrainFrameX = 1;
				_vTile[i]->terrainFrameY = 0;
				_vTile[i]->objFrameX = 6;
				_vTile[i]->objFrameY = 2;
				_vTile[i]->terrain = terrainSelect(_vTile[i]->terrainFrameX, _vTile[i]->terrainFrameY);
				_vTile[i]->obj = OBJ_BLOCK1;
			}
			else if ((*_viChar) == RightBottom)
			{
				_vTile[i]->terrainFrameX = 1;
				_vTile[i]->terrainFrameY = 0;
				_vTile[i]->objFrameX = 8;
				_vTile[i]->objFrameY = 2;
				_vTile[i]->terrain = terrainSelect(_vTile[i]->terrainFrameX, _vTile[i]->terrainFrameY);
				_vTile[i]->obj = OBJ_BLOCK1;
			}
			else if ((*_viChar) == VerticalWall)
			{
				_vTile[i]->terrainFrameX = 1;
				_vTile[i]->terrainFrameY = 0;
				_vTile[i]->objFrameX = 6;
				_vTile[i]->objFrameY = 1;
				_vTile[i]->terrain = terrainSelect(_vTile[i]->terrainFrameX, _vTile[i]->terrainFrameY);
				_vTile[i]->obj = OBJ_BLOCK1;
			}
			else if ((*_viChar) == HorizontalWall)
			{
				_vTile[i]->terrainFrameX = 1;
				_vTile[i]->terrainFrameY = 0;
				_vTile[i]->objFrameX = 7;
				_vTile[i]->objFrameY = 0;
				_vTile[i]->terrain = terrainSelect(_vTile[i]->terrainFrameX, _vTile[i]->terrainFrameY);
				_vTile[i]->obj = OBJ_BLOCK1;
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
	//출구와 방 vector 비우기
	_vExit.clear();
	_vRoom.clear();
	_vChar.clear();

	//맵 크기에 맞춰서 랜덤 맵(Unused)상태로 초기화
	for (int i = 0; i < width * height; ++i)
	{
		_vChar.push_back(Unused);
	}

	//최대 몇 개 feature 생성할지 정해서 랜덤 생성
	//(feature == 방 || 복도)
	generate(15);
}

void tileManager::generate(int maxFeatures)
{
	// place the first room in the center
	//_width에 비율 주는걸로 첫방 X위치 조절가능, _height는 Y위치, 기본은 중앙인 1/2
	if ( !makeRoom(_width/2 , _height/2, static_cast<Direction>(RND->getInt(4)) ) )
		return;


	// we already placed 1 feature (the first room)
	//2번째 구조 생성(1번째는 무조건 첫방)
	for (int i = 1; i < maxFeatures; ++i)
	{
		if (!createFeature()) 
			break;
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
		//Exit가 없으면 중단
		if (_vExit.empty())
			break;

		// choose a random side of a random room or corridor
		int index = RND->getInt(_vExit.size());
		int x = RND->getFromIntTo(_vExit[index].left - 1, _vExit[index].right + 1);
		int y = RND->getFromIntTo(_vExit[index].top - 1, _vExit[index].bottom + 1);

		// north, south, west, east
		//j= 방향, 방향에 따른 방/복도 생성
		for (int j = 0; j < DirectionCount; ++j)
		{
			if (createFeature(x, y, static_cast<Direction>(j)))
			{
				_vExit.erase(_vExit.begin() + index);
				return true;
			}
		}
	}

	return false;
}

bool tileManager::createFeature(int x, int y, Direction dir)
{
	//방 생성 확률
	float roomChance = 0.2; // corridorChance = 1.0 - roomChance

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

	//방 || 복도에 연결되어 있나 확인
	if (getChar(x + dx, y + dy) != Floor && getChar(x + dx, y + dy) != Corridor)
		return false;

	//방과 연결되어 있으면 무조건 복도로 생성
	if (getChar(x + dx, y + dy) == Floor) {
		if (makeCorridor(x, y, dir))
		{
			if (getChar(x + dx, y + dy) == Floor)
				setChar(x, y, ClosedDoor);
			else // don't place a door between corridors
				setChar(x, y, Corridor);

			return true;
		}
	}
	//복도와 연결되어 있으면 방 또는 복도 생성
	else {
		//확률에 따라 방 생성
		if (RND->getFloat(1.0) < roomChance)
		{
			if (makeRoom(x, y, dir))
			{
				setChar(x, y, ClosedDoor);

				return true;
			}
		}
		//복도 생성
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
	}

	//방 || 복도가 생성 안되었으면 return false
	return false;
}

bool tileManager::makeRoom(int x, int y, Direction dir)
{
	//방 최소, 최대 size 설정
	static const int minRoomSize = 7;
	static const int maxRoomSize = 15;

	
	//방 생성
	int width, height;
	int tmpX, tmpY;

	//방 크기 랜덤 설정 (범위 최소 ~ 최대)
	width = RND->getFromIntTo(minRoomSize, maxRoomSize + 1);
	height = RND->getFromIntTo(minRoomSize, maxRoomSize + 1);

	if (dir == North)
	{
		tmpX = x - RND->getInt(width);
		tmpY = y - height;
	}

	else if (dir == South)
	{
		tmpX = x - RND->getInt(width);
		tmpY = y + 1;
	}

	else if (dir == West)
	{
		tmpX = x - width;
		tmpY = y - RND->getInt(height);
	}

	else if (dir == East)
	{
		tmpX = x + 1;
		tmpY = y - RND->getInt(height);
	}
	RECT room = RectMake(tmpX, tmpY, width, height);


	//방이 생성되면
	if (placeRect(room, Floor))
	{
		_vRoom.emplace_back(room);

		//Exit RECT 생성
		if (dir != South) // north side
			_vExit.emplace_back(RECT{ room.left, room.top - 1, room.right, room.top });
		if (dir != North) // south side
			_vExit.emplace_back(RECT{ room.left, room.bottom, room.right, room.bottom + 1 });
		if (dir != East) // west side
			_vExit.emplace_back(RECT{ room.left - 1, room.top, room.left, room.bottom });
		if (dir != West) // east side
			_vExit.emplace_back(RECT{ room.right, room.top, room.right + 1, room.bottom });

		return true;
	}

	//방이 생성 안되었으면 return true;
	return false;
}

bool tileManager::makeCorridor(int x, int y, Direction dir)
{
	//복도 최소 최대 길이 설정
	static const int minCorridorLength = 8;
	static const int maxCorridorLength = 15;

	int tmpX, tmpY;
	tmpX = x;
	tmpY = y;

	int width, height;

	//복도 생성
	if (dir == West || dir == East) // horizontal corridor
	{
		//복도 길이 랜덤 설정 (범위 최소 ~ 최대)
		width = RND->getFromIntTo(minCorridorLength, maxCorridorLength + 1);
		height = 1;

		tmpY = y;

		if (dir == West)	//West
			tmpX = x - width;
		else				//East
			tmpX = x;
	}

	else // vertical corridor
	{
		//복도 길이 랜덤 설정 (범위 최소 ~ 최대)
		width = 1;
		height = RND->getFromIntTo(minCorridorLength, maxCorridorLength + 1);

		tmpX = x;

		if (dir == North)	//North
			tmpY = y - height;
		else				//South
			tmpY = y;
	}
	RECT corridor = RectMake(tmpX, tmpY, width, height);


	//복도가 생성되면
	if (placeRect(corridor, Corridor))
	{
		//Exit RECT 생성
		if (dir != South && width != 1) // north side
			_vExit.emplace_back(RECT{ corridor.left, corridor.top - 1, corridor.right, corridor.top });
		if (dir != North && width != 1) // south side
			_vExit.emplace_back(RECT{ corridor.left, corridor.bottom, corridor.right, corridor.bottom + 1 });
		if (dir != East && height != 1) // west side
			_vExit.emplace_back(RECT{ corridor.left - 1, corridor.top, corridor.left, corridor.bottom });
		if (dir != West && height != 1) // east side
			_vExit.emplace_back(RECT{ corridor.right, corridor.top, corridor.right + 1, corridor.bottom });

		return true;
	}

	//복도가 생성 안되었으면 return false
	return false;
}

bool tileManager::placeRect(RECT rc, char Char)
{
	//RECT 범위가 맵 보다 크면 false
	if (rc.left < 1 || rc.top < 1 || rc.right > _width - 1 || rc.bottom > _height - 1)
		return false;

	//RECT 범위 내 이미 타일이 깔려 있으면 (== 타일이 Unused상태가 아니면) false
	for (int y = rc.top; y < rc.bottom; ++y)
		for (int x = rc.left; x < rc.right; ++x)
		{
			if (getChar(x, y) != Unused)
				return false; // the area already used
		}
	
	//RECT 테두리에 벽 설정
	for (int y = rc.top - 1; y <= rc.bottom; ++y)
		for (int x = rc.left - 1; x <= rc.right; ++x)
		{
			
			if (x == rc.left - 1 && y == rc.top - 1) 
				setChar(x, y, LeftCorner);
			else if (x == rc.right&& y == rc.top - 1)
				setChar(x, y, RightCorner);
			else if (x == rc.left - 1 && y == rc.bottom) 
				setChar(x, y, LeftBottom);
			else if (x == rc.right&&y == rc.bottom) 
				setChar(x, y, RightBottom);
			else if (x == rc.left - 1 || x == rc.right)
				setChar(x, y, VerticalWall);
			else if(y == rc.top - 1 ||y == rc.bottom)
				setChar(x, y, HorizontalWall);
			else
				setChar(x, y, Char);
		}
	
	//생성 가능하면 true
	return true;
}

bool tileManager::placeObject(char Char)
{
	//방이 없으면 false
	if (_vRoom.empty())
		return false;

	//방을 랜덤으로 선택해서 방 내에 x, y 랜덤 설정
	int index = RND->getInt(_vRoom.size()); // choose a random room
	int x = RND->getFromIntTo(_vRoom[index].left + 1, _vRoom[index].right - 1);
	int y = RND->getFromIntTo(_vRoom[index].top + 1, _vRoom[index].bottom - 1);

	//x, y타일이 Floor일 경우
	if (getChar(x, y) == Floor)
	{
		//object 생성
		setChar(x, y, Char);

		return true;
	}

	//object가 생성 안되었으면 false
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
