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
	//��ü �� ũ�� ����
	_width = width;
	_height = height;

	//Ÿ�ϸ� �̹��� ���
	_Mapbase = IMAGEMANAGER->addFrameDImage("maptiles", L"img/map/tiles/maptile.png", 768, 384, 16, 8);
	_Obbase = IMAGEMANAGER->addFrameDImage("object", L"img/map/tiles/object.png", 864, 576, 18, 12);

	//���� ���� ����
	dungeon(_width, _height);
	//������ �� -> Ÿ�Ϸ� ��ȯ
	setup();
	
	return S_OK;
}

void tileManager::release()
{
}

void tileManager::update()
{
	//�̹��� Ŭ����(���� ����/�ε��� ����)
	//->ī�޶� ��ũ�� ��������
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
	//������ ������ Ÿ�ϸ� render
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

	//�̴ϸ�(�̰� Ű�� (���� ��ǻ�� ����)�� �ɸ�)
	if (PRINTMANAGER->isDebug())
		minimap();
}
void tileManager::setup()
{
	//Ÿ�� rect�����ؼ� �־��ְ�
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

	//���������� �� ���� ������� Ÿ�� �̹����� �Ӽ� ����
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
//	//Ÿ���� �ҷ��� ���� Ÿ���� � �������� ������Ʈ���� �к��ؼ�
//	//�ش� Ÿ�Ͽ� �Ӽ��� �ο����ݴϴ�
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
	//�ⱸ�� �� vector ����
	_vExit.clear();
	_vRoom.clear();
	_vChar.clear();

	//�� ũ�⿡ ���缭 ���� ��(Unused)���·� �ʱ�ȭ
	for (int i = 0; i < width * height; ++i)
	{
		_vChar.push_back(Unused);
	}

	//�ִ� �� �� feature �������� ���ؼ� ���� ����
	//(feature == �� || ����)
	generate(15);
}

void tileManager::generate(int maxFeatures)
{
	// place the first room in the center
	//_width�� ���� �ִ°ɷ� ù�� X��ġ ��������, _height�� Y��ġ, �⺻�� �߾��� 1/2
	if ( !makeRoom(_width/2 , _height/2, static_cast<Direction>(RND->getInt(4)) ) )
		return;


	// we already placed 1 feature (the first room)
	//2��° ���� ����(1��°�� ������ ù��)
	for (int i = 1; i < maxFeatures; ++i)
	{
		if (!createFeature()) 
			break;
	}

	//����� ������ 
	if (!placeObject(UpStairs))
	{
		return;
	}

	//�Ʒ���� ������
	if (!placeObject(DownStairs))
	{
		return;
	}
}

bool tileManager::createFeature()
{
	for (int i = 0; i < 1000; ++i)
	{
		//Exit�� ������ �ߴ�
		if (_vExit.empty())
			break;

		// choose a random side of a random room or corridor
		int index = RND->getInt(_vExit.size());
		int x = RND->getFromIntTo(_vExit[index].left - 1, _vExit[index].right + 1);
		int y = RND->getFromIntTo(_vExit[index].top - 1, _vExit[index].bottom + 1);

		// north, south, west, east
		//j= ����, ���⿡ ���� ��/���� ����
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
	//�� ���� Ȯ��
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

	//�� || ������ ����Ǿ� �ֳ� Ȯ��
	if (getChar(x + dx, y + dy) != Floor && getChar(x + dx, y + dy) != Corridor)
		return false;

	//��� ����Ǿ� ������ ������ ������ ����
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
	//������ ����Ǿ� ������ �� �Ǵ� ���� ����
	else {
		//Ȯ���� ���� �� ����
		if (RND->getFloat(1.0) < roomChance)
		{
			if (makeRoom(x, y, dir))
			{
				setChar(x, y, ClosedDoor);

				return true;
			}
		}
		//���� ����
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

	//�� || ������ ���� �ȵǾ����� return false
	return false;
}

bool tileManager::makeRoom(int x, int y, Direction dir)
{
	//�� �ּ�, �ִ� size ����
	static const int minRoomSize = 7;
	static const int maxRoomSize = 15;

	
	//�� ����
	int width, height;
	int tmpX, tmpY;

	//�� ũ�� ���� ���� (���� �ּ� ~ �ִ�)
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


	//���� �����Ǹ�
	if (placeRect(room, Floor))
	{
		_vRoom.emplace_back(room);

		//Exit RECT ����
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

	//���� ���� �ȵǾ����� return true;
	return false;
}

bool tileManager::makeCorridor(int x, int y, Direction dir)
{
	//���� �ּ� �ִ� ���� ����
	static const int minCorridorLength = 8;
	static const int maxCorridorLength = 15;

	int tmpX, tmpY;
	tmpX = x;
	tmpY = y;

	int width, height;

	//���� ����
	if (dir == West || dir == East) // horizontal corridor
	{
		//���� ���� ���� ���� (���� �ּ� ~ �ִ�)
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
		//���� ���� ���� ���� (���� �ּ� ~ �ִ�)
		width = 1;
		height = RND->getFromIntTo(minCorridorLength, maxCorridorLength + 1);

		tmpX = x;

		if (dir == North)	//North
			tmpY = y - height;
		else				//South
			tmpY = y;
	}
	RECT corridor = RectMake(tmpX, tmpY, width, height);


	//������ �����Ǹ�
	if (placeRect(corridor, Corridor))
	{
		//Exit RECT ����
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

	//������ ���� �ȵǾ����� return false
	return false;
}

bool tileManager::placeRect(RECT rc, char Char)
{
	//RECT ������ �� ���� ũ�� false
	if (rc.left < 1 || rc.top < 1 || rc.right > _width - 1 || rc.bottom > _height - 1)
		return false;

	//RECT ���� �� �̹� Ÿ���� ��� ������ (== Ÿ���� Unused���°� �ƴϸ�) false
	for (int y = rc.top; y < rc.bottom; ++y)
		for (int x = rc.left; x < rc.right; ++x)
		{
			if (getChar(x, y) != Unused)
				return false; // the area already used
		}
	
	//RECT �׵θ��� �� ����
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
	
	//���� �����ϸ� true
	return true;
}

bool tileManager::placeObject(char Char)
{
	//���� ������ false
	if (_vRoom.empty())
		return false;

	//���� �������� �����ؼ� �� ���� x, y ���� ����
	int index = RND->getInt(_vRoom.size()); // choose a random room
	int x = RND->getFromIntTo(_vRoom[index].left + 1, _vRoom[index].right - 1);
	int y = RND->getFromIntTo(_vRoom[index].top + 1, _vRoom[index].bottom - 1);

	//x, yŸ���� Floor�� ���
	if (getChar(x, y) == Floor)
	{
		//object ����
		setChar(x, y, Char);

		return true;
	}

	//object�� ���� �ȵǾ����� false
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
