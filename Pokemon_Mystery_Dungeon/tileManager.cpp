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
	_floor++;
	//�ش� ������ �������� �Ǹ�
	//������ �����ϵ���

	//���� ���� ����
	dungeon(_width, _height);
	//������ �� -> Ÿ�Ϸ� ��ȯ
	setup();
	minimap();
	return S_OK;
}

HRESULT tileManager::init(int width, int height, int type)
{
	//��ü �� ũ�� ����
	_width = width;
	_height = height;
	_type = type;

	//Ÿ�ϸ� �̹��� ���
	_Mapbase[0] = IMAGEMANAGER->addFrameDImage("terrain0", L"img/map/tiles/terrain_0.png", 720, 192, SAMPLETILEX, SAMPLETILEY);
	_Mapbase[1] = IMAGEMANAGER->addFrameDImage("terrain1", L"img/map/tiles/terrain_1.png", 720, 192, SAMPLETILEX, SAMPLETILEY);
	_Mapbase[2] = IMAGEMANAGER->addFrameDImage("terrain2", L"img/map/tiles/terrain_2.png", 720, 192, SAMPLETILEX, SAMPLETILEY);
	_Mapbase[3] = IMAGEMANAGER->addFrameDImage("terrain3", L"img/map/tiles/terrain_3.png", 720, 192, SAMPLETILEX, SAMPLETILEY);
	_Mapbase[4] = IMAGEMANAGER->addFrameDImage("terrain4", L"img/map/tiles/terrain_4.png", 720, 192, SAMPLETILEX, SAMPLETILEY);
	_Mapbase[5] = IMAGEMANAGER->addFrameDImage("terrain5", L"img/map/tiles/terrain_5.png", 720, 192, SAMPLETILEX, SAMPLETILEY);
	_Mapbase[6] = IMAGEMANAGER->addFrameDImage("terrain6", L"img/map/tiles/terrain_6.png", 720, 192, SAMPLETILEX, SAMPLETILEY);
	_Mapbase[7] = IMAGEMANAGER->addFrameDImage("terrain7", L"img/map/tiles/terrain_7.png", 720, 192, SAMPLETILEX, SAMPLETILEY);
	_Obbase = IMAGEMANAGER->addFrameDImage("object", L"img/map/tiles/object_all.png", 720, 192, SAMPLETILEX, SAMPLETILEY);
	_minibase = IMAGEMANAGER->addFrameDImage("minimap", L"img/map/tiles/minimap temp.png", 184, 8, 23, 1);

	if (_type == 0)
	{
		//�̸��� �����ְ�
		//����.clear()
		//����.push_back(27);
		//�ֵ� ���������� 5 ~ 10 10 15

		_dungeonName = L"���߻��߻�";
		_enemyList.clear();
		_enemyList.push_back(1);
		_enemyList.push_back(2);
		_enemyList.push_back(4);
		_enemyList.push_back(7);
		_enemyList.push_back(10);
		_enemyList.push_back(13);
		_enemyList.push_back(16);
		_enemyList.push_back(17);
		_enemyList.push_back(26);
		_enemyList.push_back(35);
		_bossPokemon = 36;
		_minLevel = 5;
		_maxLevel = 8;
		
	}
	else if (_type == 1)
	{
		_dungeonName = L"������ ����";
		_enemyList.clear();
		_enemyList.push_back(2);
		_enemyList.push_back(3);
		_enemyList.push_back(5);
		_enemyList.push_back(8);
		_enemyList.push_back(9);
		_enemyList.push_back(11);
		_enemyList.push_back(12);
		_enemyList.push_back(14);
		_enemyList.push_back(15);
		_enemyList.push_back(17);
		_enemyList.push_back(18);
		_enemyList.push_back(20);
		_enemyList.push_back(21);
		_enemyList.push_back(22);
		_enemyList.push_back(23);
		_enemyList.push_back(24);
		_enemyList.push_back(25);
		_enemyList.push_back(26);
		_enemyList.push_back(27);
		_enemyList.push_back(29);
		_enemyList.push_back(30);
		_enemyList.push_back(31);
		_enemyList.push_back(35);
		_enemyList.push_back(36);
		_bossPokemon = 19;
		_minLevel = 30;
		_maxLevel = 35;

	
	}
	else if (_type == 2)
	{
		_dungeonName = L"�Ϸ�Ʈ�� ���";
		_enemyList.clear();
		_enemyList.push_back(3);
		_enemyList.push_back(5);
		_enemyList.push_back(6);
		_enemyList.push_back(9);
		_enemyList.push_back(15);
		_enemyList.push_back(18);
		_enemyList.push_back(22);
		_enemyList.push_back(25);
		_enemyList.push_back(26);
		_enemyList.push_back(27);
		_enemyList.push_back(29);
		_enemyList.push_back(35);
		_enemyList.push_back(36);
		_bossPokemon = 32;
		_minLevel = 40;
		_maxLevel = 45;

		
	}
	else if (_type == 3)
	{
		_dungeonName = L"�ٴ尡 ����";
		_enemyList.clear();
		_enemyList.push_back(5);
		_enemyList.push_back(8);
		_enemyList.push_back(9);
		_enemyList.push_back(11);
		_enemyList.push_back(12);
		_enemyList.push_back(14);
		_enemyList.push_back(20);
		_enemyList.push_back(21);
		_enemyList.push_back(24);
		_enemyList.push_back(25);
		_enemyList.push_back(28);
		_enemyList.push_back(29);
		_enemyList.push_back(30);
		_enemyList.push_back(31);
		_bossPokemon = 38;
		_minLevel = 22;
		_maxLevel = 27;

		
	}
	else if (_type == 4)
	{
		_dungeonName = L"����� ����";
		_enemyList.clear();
		_enemyList.push_back(5);
		_enemyList.push_back(10);
		_enemyList.push_back(11);
		_enemyList.push_back(13);
		_enemyList.push_back(14);
		_enemyList.push_back(21);
		_enemyList.push_back(25);
		_enemyList.push_back(26);
		_enemyList.push_back(27);
		_enemyList.push_back(28);
		_enemyList.push_back(35);
		_bossPokemon = 12;
		_minLevel = 8;
		_maxLevel = 12;

		
	}
	else if (_type == 5)
	{
		_dungeonName = L"����� ��";
		_enemyList.clear();
		_enemyList.push_back(1);
		_enemyList.push_back(4);
		_enemyList.push_back(5);
		_enemyList.push_back(7);
		_enemyList.push_back(8);
		_enemyList.push_back(16);
		_enemyList.push_back(20);
		_enemyList.push_back(21);
		_enemyList.push_back(22);
		_enemyList.push_back(23);
		_enemyList.push_back(29);
		_enemyList.push_back(35);
		_bossPokemon = 37;
		_minLevel = 10;
		_maxLevel = 15;

		
	}
	else if (_type == 6)
	{
		_dungeonName = L"������ �Ϲ�";
		_enemyList.clear();
		_enemyList.push_back(2);
		_enemyList.push_back(3);
		_enemyList.push_back(5);
		_enemyList.push_back(6);
		_enemyList.push_back(8);
		_enemyList.push_back(10);
		_enemyList.push_back(11);
		_enemyList.push_back(17);
		_enemyList.push_back(18);
		_enemyList.push_back(20);
		_enemyList.push_back(24);
		_enemyList.push_back(25);
		_enemyList.push_back(35);
		_bossPokemon = 33;
		_minLevel = 18;
		_maxLevel = 24;

		
	}
	else if (_type == 7)
	{
		_dungeonName = L"�Ի�";
		_enemyList.clear();
		_enemyList.push_back(1);
		_enemyList.push_back(2);
		_enemyList.push_back(5);
		_enemyList.push_back(7);
		_enemyList.push_back(8);
		_enemyList.push_back(13);
		_enemyList.push_back(14);
		_enemyList.push_back(16);
		_enemyList.push_back(17);
		_enemyList.push_back(20);
		_enemyList.push_back(22);
		_enemyList.push_back(24);
		_enemyList.push_back(30);
		_enemyList.push_back(31);
		_enemyList.push_back(35);
		_bossPokemon = 34;
		_minLevel = 13;
		_maxLevel = 18;

		
	}

	_floor = 0;

	return S_OK;
}

void tileManager::release()
{
	vector<tagTile*>::iterator tiles = _vTile.begin();
	
	for (; tiles != _vTile.end();) {
		SAFE_DELETE(*tiles);
		tiles = _vTile.erase(tiles);
	}

	_vTile.clear();
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


	for (int i = 0; i < _width*_height; ++i)
	{
		if ((_mini[i].terrainFrameX == 0 && _mini[i].terrainFrameY == 0) ||
			(_mini[i].terrainFrameX == 1 && _mini[i].terrainFrameY == 0) ||
			(_mini[i].terrainFrameX == 2 && _mini[i].terrainFrameY == 0) ||
			(_mini[i].terrainFrameX == 0 && _mini[i].terrainFrameY == 1) ||
			(_mini[i].terrainFrameX == 1 && _mini[i].terrainFrameY == 1) ||
			(_mini[i].terrainFrameX == 2 && _mini[i].terrainFrameY == 1) ||
			(_mini[i].terrainFrameX == 0 && _mini[i].terrainFrameY == 2) ||
			(_mini[i].terrainFrameX == 1 && _mini[i].terrainFrameY == 2) ||
			(_mini[i].terrainFrameX == 2 && _mini[i].terrainFrameY == 2)) {
			_mini[i].terrainFrameX = 22; _mini[i].terrainFrameY = 0;
		}
		if (_mini[i].rc.left == (_playerX * 8) && _mini[i].rc.top == (_playerY * 8)) {
			_mini[i].terrainFrameX = 0; _mini[i].terrainFrameY = 0;
		}
	}
}

void tileManager::render()
{
	D2D1_RECT_F rc = CAMERAMANAGER->getScreen();
	//������ ������ Ÿ�ϸ� render
	for (int i = _initY; i <= _endY; i++)
		for (int j = _initX; j <= _endX; j++) {
			int index = i * _width + j;

			_Mapbase[_type]->frameRender(
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
		for (int i = 0; i < _width*_height; ++i)
		{
			_minibase->frameRender(
				rc.left + (_mini[i].rc.left / 2), rc.top + (_mini[i].rc.top / 2),
				_mini[i].terrainFrameX, _mini[i].terrainFrameY);
		}
}
void tileManager::maprender()
{
	D2D1_RECT_F rc = CAMERAMANAGER->getScreen();
	for (int i = 0; i < _width * _height; ++i)
	{
		_Mapbase[_type]->frameRender(
			_vTile[i]->rc.left, _vTile[i]->rc.top,
			_vTile[i]->terrainFrameX, _vTile[i]->terrainFrameY);
	}
	for (int i = 0; i < _width * _height; ++i)
	{
		if (_vTile[i]->obj == OBJ_NONE) continue;

		_Obbase->frameRender(
			_vTile[i]->rc.left, _vTile[i]->rc.top,
			_vTile[i]->objFrameX, _vTile[i]->objFrameY);
	}
	if (PRINTMANAGER->isDebug())
		for (int i = 0; i < _width*_height; ++i)
		{
			_minibase->frameRender(
				rc.left + (_mini[i].rc.left / 2), rc.top + (_mini[i].rc.top / 2),
				_mini[i].terrainFrameX, _mini[i].terrainFrameY);
		}
}
void tileManager::setup()
{
	//Ÿ�� rect�����ؼ� �־��ְ�
	if (_vTile.size() == 0) {
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

				SetRect(&_mini[i*_width + j].rc,
					j * (TILESIZE / 6),
					i * (TILESIZE / 6),
					j * (TILESIZE / 6) + (TILESIZE / 6),
					i * (TILESIZE / 6) + (TILESIZE / 6));
			}
		}
	}

	int i = 0;
	vector<char>::iterator _viChar;

	//���������� �� ���� ������� Ÿ�� �̹����� �Ӽ� ����
	for (_viChar = _vChar.begin(); _viChar != _vChar.end(); ++_viChar, i++)
	{
		if ((*_viChar) == Unused)
		{
			_vTile[i]->terrainFrameX = 10;
			_vTile[i]->terrainFrameY = 1;
			_vTile[i]->objFrameX = 0;
			_vTile[i]->objFrameY = 0;
			_vTile[i]->terrain = TR_BLOCK;
			_vTile[i]->obj = OBJ_NONE;
		}

		else if ((*_viChar) == UpStairs)
		{
			_vTile[i]->terrainFrameX = 0;
			_vTile[i]->terrainFrameY = 0;
			_vTile[i]->objFrameX = 13;
			_vTile[i]->objFrameY = 0;
			_vTile[i]->terrain = TR_GRASS;
			_vTile[i]->obj = OBJ_STAIR;
		}
		else if ((*_viChar) == DownStairs)
		{
			_vTile[i]->terrainFrameX = 1;
			_vTile[i]->terrainFrameY = 0;
			_vTile[i]->objFrameX = 14;
			_vTile[i]->objFrameY = 0;
			_vTile[i]->terrain = TR_GRASS;
			_vTile[i]->obj = OBJ_STAIR;
		}
		else if ((*_viChar) == ClearTrap)
		{
			_vTile[i]->terrainFrameX = 1;
			_vTile[i]->terrainFrameY = 0;
			_vTile[i]->objFrameX = 0;
			_vTile[i]->objFrameY = 0;
			_vTile[i]->terrain = TR_GRASS;
			_vTile[i]->obj = OBJ_TRAP;
		}
		else if ((*_viChar) == PowerTrap)
		{
			_vTile[i]->terrainFrameX = 1;
			_vTile[i]->terrainFrameY = 0;
			_vTile[i]->objFrameX = 1;
			_vTile[i]->objFrameY = 0;
			_vTile[i]->terrain = TR_GRASS;
			_vTile[i]->obj = OBJ_TRAP1;
		}
		else if ((*_viChar) == LeftTriWall)
		{
			_vTile[i]->terrainFrameX = 2;
			_vTile[i]->terrainFrameY = 3;
			_vTile[i]->objFrameX = 0;
			_vTile[i]->objFrameY = 0;
			_vTile[i]->terrain = TR_BLOCK;
			_vTile[i]->obj = OBJ_NONE;
		}
		else if ((*_viChar) == RightTriWall)
		{
			_vTile[i]->terrainFrameX = 3;
			_vTile[i]->terrainFrameY = 3;
			_vTile[i]->objFrameX = 0;
			_vTile[i]->objFrameY = 0;
			_vTile[i]->terrain = TR_BLOCK;
			_vTile[i]->obj = OBJ_NONE;
		}
		else if ((*_viChar) == TopTriWall)
		{
			_vTile[i]->terrainFrameX = 0;
			_vTile[i]->terrainFrameY = 3;
			_vTile[i]->objFrameX = 0;
			_vTile[i]->objFrameY = 0;
			_vTile[i]->terrain = TR_BLOCK;
			_vTile[i]->obj = OBJ_NONE;
		}
		else if ((*_viChar) == BottomTriWall)
		{
			_vTile[i]->terrainFrameX = 1;
			_vTile[i]->terrainFrameY = 3;
			_vTile[i]->objFrameX = 0;
			_vTile[i]->objFrameY = 0;
			_vTile[i]->terrain = TR_BLOCK;
			_vTile[i]->obj = OBJ_NONE;
		}
		else if ((*_viChar) == LeftOpenWall)
		{
			_vTile[i]->terrainFrameX = 6;
			_vTile[i]->terrainFrameY = 3;
			_vTile[i]->objFrameX = 0;
			_vTile[i]->objFrameY = 0;
			_vTile[i]->terrain = TR_BLOCK;
			_vTile[i]->obj = OBJ_NONE;
		}
		else if ((*_viChar) == RightOpenWall)
		{
			_vTile[i]->terrainFrameX = 7;
			_vTile[i]->terrainFrameY = 3;
			_vTile[i]->objFrameX = 0;
			_vTile[i]->objFrameY = 0;
			_vTile[i]->terrain = TR_BLOCK;
			_vTile[i]->obj = OBJ_NONE;
		}
		else if ((*_viChar) == TopOpenWall)
		{
			_vTile[i]->terrainFrameX = 4;
			_vTile[i]->terrainFrameY = 3;
			_vTile[i]->objFrameX = 0;
			_vTile[i]->objFrameY = 0;
			_vTile[i]->terrain = TR_BLOCK;
			_vTile[i]->obj = OBJ_NONE;
		}
		else if ((*_viChar) == BottomOpenWall)
		{
			_vTile[i]->terrainFrameX = 5;
			_vTile[i]->terrainFrameY = 3;
			_vTile[i]->objFrameX = 0;
			_vTile[i]->objFrameY = 0;
			_vTile[i]->terrain = TR_BLOCK;
			_vTile[i]->obj = OBJ_NONE;
		}

		else if ((*_viChar) == LeftOpenCorner)
		{
			_vTile[i]->terrainFrameX = 6;
			_vTile[i]->terrainFrameY = 0;
			_vTile[i]->objFrameX = 0;
			_vTile[i]->objFrameY = 0;
			_vTile[i]->terrain = TR_BLOCK;
			_vTile[i]->obj = OBJ_NONE;
		}
		else if ((*_viChar) == RightOpenCorner)
		{
			_vTile[i]->terrainFrameX = 8;
			_vTile[i]->terrainFrameY = 0;
			_vTile[i]->objFrameX = 0;
			_vTile[i]->objFrameY = 0;
			_vTile[i]->terrain = TR_BLOCK;
			_vTile[i]->obj = OBJ_NONE;
		}
		else if ((*_viChar) == LeftOpenBottom)
		{
			_vTile[i]->terrainFrameX = 6;
			_vTile[i]->terrainFrameY = 2;
			_vTile[i]->objFrameX = 0;
			_vTile[i]->objFrameY = 0;
			_vTile[i]->terrain = TR_BLOCK;
			_vTile[i]->obj = OBJ_NONE;
		}
		else if ((*_viChar) == RightOpenBottom)
		{
			_vTile[i]->terrainFrameX = 8;
			_vTile[i]->terrainFrameY = 2;
			_vTile[i]->objFrameX = 0;
			_vTile[i]->objFrameY = 0;
			_vTile[i]->terrain = TR_BLOCK;
			_vTile[i]->obj = OBJ_NONE;
		}
		else if ((*_viChar) == VerticalLeftWall)
		{
			_vTile[i]->terrainFrameX = 11;
			_vTile[i]->terrainFrameY = 1;
			_vTile[i]->objFrameX = 0;
			_vTile[i]->objFrameY = 0;
			_vTile[i]->terrain = TR_BLOCK;
			_vTile[i]->obj = OBJ_NONE;
		}
		else if ((*_viChar) == VerticalRightWall)
		{
			_vTile[i]->terrainFrameX = 9;
			_vTile[i]->terrainFrameY = 1;
			_vTile[i]->objFrameX = 0;
			_vTile[i]->objFrameY = 0;
			_vTile[i]->terrain = TR_BLOCK;
			_vTile[i]->obj = OBJ_NONE;
		}
		else if ((*_viChar) == HorizontalTopWall)
		{
			_vTile[i]->terrainFrameX = 10;
			_vTile[i]->terrainFrameY = 2;
			_vTile[i]->objFrameX = 0;
			_vTile[i]->objFrameY = 0;
			_vTile[i]->terrain = TR_BLOCK;
			_vTile[i]->obj = OBJ_NONE;
		}
		else if ((*_viChar) == HorizontalBottomWall)
		{
			_vTile[i]->terrainFrameX = 10;
			_vTile[i]->terrainFrameY = 0;
			_vTile[i]->objFrameX = 0;
			_vTile[i]->objFrameY = 0;
			_vTile[i]->terrain = TR_BLOCK;
			_vTile[i]->obj = OBJ_NONE;
		}
		else if ((*_viChar) == LeftCorner)
		{
			_vTile[i]->terrainFrameX = 3;
			_vTile[i]->terrainFrameY = 0;
			_vTile[i]->objFrameX = 0;
			_vTile[i]->objFrameY = 0;
			_vTile[i]->terrain = TR_BLOCK;
			_vTile[i]->obj = OBJ_NONE;
		}
		else if ((*_viChar) == RightCorner)
		{
			_vTile[i]->terrainFrameX = 5;
			_vTile[i]->terrainFrameY = 0;
			_vTile[i]->objFrameX = 0;
			_vTile[i]->objFrameY = 0;
			_vTile[i]->terrain = TR_BLOCK;
			_vTile[i]->obj = OBJ_NONE;
		}
		else if ((*_viChar) == LeftBottom)
		{
			_vTile[i]->terrainFrameX = 3;
			_vTile[i]->terrainFrameY = 2;
			_vTile[i]->objFrameX = 0;
			_vTile[i]->objFrameY = 0;
			_vTile[i]->terrain = TR_BLOCK;
			_vTile[i]->obj = OBJ_NONE;
		}
		else if ((*_viChar) == RightBottom)
		{
			_vTile[i]->terrainFrameX = 5;
			_vTile[i]->terrainFrameY = 2;
			_vTile[i]->objFrameX = 0;
			_vTile[i]->objFrameY = 0;
			_vTile[i]->terrain = TR_BLOCK;
			_vTile[i]->obj = OBJ_NONE;
		}
		else if ((*_viChar) == VerticalWall)
		{
			_vTile[i]->terrainFrameX = 3;
			_vTile[i]->terrainFrameY = 1;
			_vTile[i]->objFrameX = 0;
			_vTile[i]->objFrameY = 0;
			_vTile[i]->terrain = TR_BLOCK;
			_vTile[i]->obj = OBJ_NONE;
		}
		else if ((*_viChar) == HorizontalWall)
		{
			_vTile[i]->terrainFrameX = 4;
			_vTile[i]->terrainFrameY = 0;
			_vTile[i]->objFrameX = 0;
			_vTile[i]->objFrameY = 0;
			_vTile[i]->terrain = TR_BLOCK;
			_vTile[i]->obj = OBJ_NONE;
		}
		else if ((*_viChar) == ClosedDoor)
		{
			_vTile[i]->terrainFrameX = RND->getInt(3);
			_vTile[i]->terrainFrameY = RND->getInt(3);
			_vTile[i]->objFrameX = 0;
			_vTile[i]->objFrameY = 0;
			_vTile[i]->terrain = TR_GRASS;
			_vTile[i]->obj = OBJ_NONE;
		}
		else if ((*_viChar) == LeftBlockWall)
		{
			_vTile[i]->terrainFrameX = 8;
			_vTile[i]->terrainFrameY = 1;
			_vTile[i]->objFrameX = 0;
			_vTile[i]->objFrameY = 0;
			_vTile[i]->terrain = TR_BLOCK;
			_vTile[i]->obj = OBJ_NONE;
		}
		else if ((*_viChar) == RightBlockWall)
		{
			_vTile[i]->terrainFrameX = 6;
			_vTile[i]->terrainFrameY = 1;
			_vTile[i]->objFrameX = 0;
			_vTile[i]->objFrameY = 0;
			_vTile[i]->terrain = TR_BLOCK;
			_vTile[i]->obj = OBJ_NONE;
		}
		else if ((*_viChar) == TopBlockWall)
		{
			_vTile[i]->terrainFrameX = 7;
			_vTile[i]->terrainFrameY = 0;
			_vTile[i]->objFrameX = 0;
			_vTile[i]->objFrameY = 0;
			_vTile[i]->terrain = TR_BLOCK;
			_vTile[i]->obj = OBJ_NONE;
		}
		else if ((*_viChar) == BottomBlockWall)
		{
			_vTile[i]->terrainFrameX = 7;
			_vTile[i]->terrainFrameY = 2;
			_vTile[i]->objFrameX = 0;
			_vTile[i]->objFrameY = 0;
			_vTile[i]->terrain = TR_BLOCK;
			_vTile[i]->obj = OBJ_NONE;
		}
		else if ((*_viChar) == VerticalTopRight)
		{
			_vTile[i]->terrainFrameX = 12;
			_vTile[i]->terrainFrameY = 0;
			_vTile[i]->objFrameX = 0;
			_vTile[i]->objFrameY = 0;
			_vTile[i]->terrain = TR_BLOCK;
			_vTile[i]->obj = OBJ_NONE;
		}
		else if ((*_viChar) == VerticalTopLeft)
		{
			_vTile[i]->terrainFrameX = 13;
			_vTile[i]->terrainFrameY = 0;
			_vTile[i]->objFrameX = 0;
			_vTile[i]->objFrameY = 0;
			_vTile[i]->terrain = TR_BLOCK;
			_vTile[i]->obj = OBJ_NONE;
		}
		else if ((*_viChar) == VerticalBottomRight)
		{
			_vTile[i]->terrainFrameX = 12;
			_vTile[i]->terrainFrameY = 1;
			_vTile[i]->objFrameX = 0;
			_vTile[i]->objFrameY = 0;
			_vTile[i]->terrain = TR_BLOCK;
			_vTile[i]->obj = OBJ_NONE;
		}
		else if ((*_viChar) == VerticalBottomLeft)
		{
			_vTile[i]->terrainFrameX = 13;
			_vTile[i]->terrainFrameY = 1;
			_vTile[i]->objFrameX = 0;
			_vTile[i]->objFrameY = 0;
			_vTile[i]->terrain = TR_BLOCK;
			_vTile[i]->obj = OBJ_NONE;
		}
		else if ((*_viChar) == HorizontalTopLeft)
		{
			_vTile[i]->terrainFrameX = 12;
			_vTile[i]->terrainFrameY = 3;
			_vTile[i]->objFrameX = 0;
			_vTile[i]->objFrameY = 0;
			_vTile[i]->terrain = TR_BLOCK;
			_vTile[i]->obj = OBJ_NONE;
		}
		else if ((*_viChar) == HorizontalTopRight)
		{
			_vTile[i]->terrainFrameX = 13;
			_vTile[i]->terrainFrameY = 3;
			_vTile[i]->objFrameX = 0;
			_vTile[i]->objFrameY = 0;
			_vTile[i]->terrain = TR_BLOCK;
			_vTile[i]->obj = OBJ_NONE;
		}
		else if ((*_viChar) == HorizontalBottomLeft)
		{
			_vTile[i]->terrainFrameX = 12;
			_vTile[i]->terrainFrameY = 2;
			_vTile[i]->objFrameX = 0;
			_vTile[i]->objFrameY = 0;
			_vTile[i]->terrain = TR_BLOCK;
			_vTile[i]->obj = OBJ_NONE;
		}
		else if ((*_viChar) == HorizontalBottomRight)
		{
			_vTile[i]->terrainFrameX = 13;
			_vTile[i]->terrainFrameY = 2;
			_vTile[i]->objFrameX = 0;
			_vTile[i]->objFrameY = 0;
			_vTile[i]->terrain = TR_BLOCK;
			_vTile[i]->obj = OBJ_NONE;
		}
		else if ((*_viChar) == AllOpenLeft)
		{
			_vTile[i]->terrainFrameX = 10;
			_vTile[i]->terrainFrameY = 3;
			_vTile[i]->objFrameX = 0;
			_vTile[i]->objFrameY = 0;
			_vTile[i]->terrain = TR_BLOCK;
			_vTile[i]->obj = OBJ_NONE;
		}
		else if ((*_viChar) == AllOpenRight)
		{
			_vTile[i]->terrainFrameX = 11;
			_vTile[i]->terrainFrameY = 3;
			_vTile[i]->objFrameX = 0;
			_vTile[i]->objFrameY = 0;
			_vTile[i]->terrain = TR_BLOCK;
			_vTile[i]->obj = OBJ_NONE;
		}
		else if ((*_viChar) == OpenConnectTopLeft)
		{
			_vTile[i]->terrainFrameX = 14;
			_vTile[i]->terrainFrameY = 3;
			_vTile[i]->objFrameX = 0;
			_vTile[i]->objFrameY = 0;
			_vTile[i]->terrain = TR_BLOCK;
			_vTile[i]->obj = OBJ_NONE;
		}
		else if ((*_viChar) == OpenConnectTopRight)
		{
			_vTile[i]->terrainFrameX = 14;
			_vTile[i]->terrainFrameY = 1;
			_vTile[i]->objFrameX = 0;
			_vTile[i]->objFrameY = 0;
			_vTile[i]->terrain = TR_BLOCK;
			_vTile[i]->obj = OBJ_NONE;
		}
		else if ((*_viChar) == OpenConnectBottomLeft)
		{
			_vTile[i]->terrainFrameX = 14;
			_vTile[i]->terrainFrameY = 2;
			_vTile[i]->objFrameX = 0;
			_vTile[i]->objFrameY = 0;
			_vTile[i]->terrain = TR_BLOCK;
			_vTile[i]->obj = OBJ_NONE;
		}
		else if ((*_viChar) == OpenConnectBottomRight)
		{
			_vTile[i]->terrainFrameX = 14;
			_vTile[i]->terrainFrameY = 0;
			_vTile[i]->objFrameX = 0;
			_vTile[i]->objFrameY = 0;
			_vTile[i]->terrain = TR_BLOCK;
			_vTile[i]->obj = OBJ_NONE;
		}
		else if ((*_viChar) == LeftTopBlockCorner)
		{
			_vTile[i]->terrainFrameX = 11;
			_vTile[i]->terrainFrameY = 2;
			_vTile[i]->objFrameX = 0;
			_vTile[i]->objFrameY = 0;
			_vTile[i]->terrain = TR_BLOCK;
			_vTile[i]->obj = OBJ_NONE;
		}
		else if ((*_viChar) == RightTopBlockCorner)
		{
			_vTile[i]->terrainFrameX = 9;
			_vTile[i]->terrainFrameY = 2;
			_vTile[i]->objFrameX = 0;
			_vTile[i]->objFrameY = 0;
			_vTile[i]->terrain = TR_BLOCK;
			_vTile[i]->obj = OBJ_NONE;
		}
		else if ((*_viChar) == LeftBottomBlockCorner)
		{
			_vTile[i]->terrainFrameX = 11;
			_vTile[i]->terrainFrameY = 0;
			_vTile[i]->objFrameX = 0;
			_vTile[i]->objFrameY = 0;
			_vTile[i]->terrain = TR_BLOCK;
			_vTile[i]->obj = OBJ_NONE;
		}
		else if ((*_viChar) == RightBottomBlockCorner)
		{
			_vTile[i]->terrainFrameX = 9;
			_vTile[i]->terrainFrameY = 0;
			_vTile[i]->objFrameX = 0;
			_vTile[i]->objFrameY = 0;
			_vTile[i]->terrain = TR_BLOCK;
			_vTile[i]->obj = OBJ_NONE;
		}
		else
		{
			_vTile[i]->terrainFrameX = RND->getInt(3);
			_vTile[i]->terrainFrameY = RND->getInt(3);
			_vTile[i]->objFrameX = 0;
			_vTile[i]->objFrameY = 0;
			_vTile[i]->terrain = TR_GRASS;
			_vTile[i]->obj = OBJ_NONE;
		}
	}

}

void tileManager::load(const char * mapName)
{
	HANDLE file;
	DWORD read;

	file = CreateFile(mapName, GENERIC_READ, NULL, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	ReadFile(file, _tiles, sizeof(tagTile) * _width * _height, &read, NULL);

	memset(_attribute, 0, sizeof(DWORD) *  _width * _height);
	_vTile.clear();
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

	for (int i = 0; i < _width*_height; ++i)
	{
		_vTile[i]->terrainFrameX = _tiles[i].terrainFrameX;
		_vTile[i]->terrainFrameY = _tiles[i].terrainFrameY;
		_vTile[i]->objFrameX = _tiles[i].objFrameX;
		_vTile[i]->objFrameY = _tiles[i].objFrameY;
		_vTile[i]->terrain = _tiles[i].terrain;
		_vTile[i]->obj = _tiles[i].obj;
	}
	//STEP 01
	//Ÿ���� �ҷ��� ���� Ÿ���� � �������� ������Ʈ���� �к��ؼ�
	//�ش� Ÿ�Ͽ� �Ӽ��� �ο����ݴϴ�

	//for (int i = 0; i < _width * _height; ++i)
	//{
	//	if (_tiles[i].obj == OBJ_BLOCK1) _attribute[i] |= ATTR_UNMOVE;
	//	else if (_tiles[i].obj == OBJ_BLOCK2) _attribute[i] |= ATTR_UNMOVE;
	//	else if (_tiles[i].obj == OBJ_BLOCK3) _attribute[i] |= ATTR_UNMOVE;
	//	else if (_tiles[i].obj == OBJ_BLOCK4) _attribute[i] |= ATTR_UNMOVE;
	//	else if (_tiles[i].obj == OBJ_BLOCK5) _attribute[i] |= ATTR_UNMOVE;
	//	else if (_tiles[i].obj == OBJ_BLOCK6) _attribute[i] |= ATTR_UNMOVE;
	//	else if (_tiles[i].obj == OBJ_BLOCK7) _attribute[i] |= ATTR_UNMOVE;
	//	else if (_tiles[i].obj == OBJ_BLOCK8) _attribute[i] |= ATTR_UNMOVE;
	//	else if (_tiles[i].obj == OBJ_WATER) _attribute[i] |= ATTR_WATER;
	//}



	CloseHandle(file);
}

void tileManager::minimap()
{
	D2D1_RECT_F rc = CAMERAMANAGER->getScreen();

	for (int i = 0; i < _width * _height; ++i)
	{


		_mini[i].terrainFrameX = _vTile[i]->terrainFrameX;
		_mini[i].terrainFrameY = _vTile[i]->terrainFrameY;
		_mini[i].objFrameX = _vTile[i]->objFrameX;
		_mini[i].objFrameY = _vTile[i]->objFrameY;
		_mini[i].terrain = _vTile[i]->terrain;
		_mini[i].obj = _vTile[i]->obj;


		if ((_mini[i].terrainFrameX == 0 && _mini[i].terrainFrameY == 0) ||
			(_mini[i].terrainFrameX == 1 && _mini[i].terrainFrameY == 0) ||
			(_mini[i].terrainFrameX == 2 && _mini[i].terrainFrameY == 0) ||
			(_mini[i].terrainFrameX == 0 && _mini[i].terrainFrameY == 1) ||
			(_mini[i].terrainFrameX == 1 && _mini[i].terrainFrameY == 1) ||
			(_mini[i].terrainFrameX == 2 && _mini[i].terrainFrameY == 1) ||
			(_mini[i].terrainFrameX == 0 && _mini[i].terrainFrameY == 2) ||
			(_mini[i].terrainFrameX == 1 && _mini[i].terrainFrameY == 2) ||
			(_mini[i].terrainFrameX == 2 && _mini[i].terrainFrameY == 2)) {
			_mini[i].terrainFrameX = 22; _mini[i].terrainFrameY = 0;
		}

		else if (_mini[i].terrainFrameX == 10 && _mini[i].terrainFrameY == 2) { _mini[i].terrainFrameX = 10; _mini[i].terrainFrameY = 0; }

		else if (_mini[i].terrainFrameX == 10 && _mini[i].terrainFrameY == 0)
		{
			_mini[i].terrainFrameX = 11; _mini[i].terrainFrameY = 0;
		}

		else if (_mini[i].terrainFrameX == 9 && _mini[i].terrainFrameY == 1)
		{
			_mini[i].terrainFrameX = 12; _mini[i].terrainFrameY = 0;
		}

		else if (_mini[i].terrainFrameX == 11 && _mini[i].terrainFrameY == 1)
		{
			_mini[i].terrainFrameX = 13; _mini[i].terrainFrameY = 0;
		}

		else if (_mini[i].terrainFrameX == 6 && _mini[i].terrainFrameY == 0) { _mini[i].terrainFrameX = 14; _mini[i].terrainFrameY = 0; }

		else if (_mini[i].terrainFrameX == 8 && _mini[i].terrainFrameY == 0) { _mini[i].terrainFrameX = 16; _mini[i].terrainFrameY = 0; }

		else if (_mini[i].terrainFrameX == 6 && _mini[i].terrainFrameY == 2) { _mini[i].terrainFrameX = 18; _mini[i].terrainFrameY = 0; }

		else if (_mini[i].terrainFrameX == 8 && _mini[i].terrainFrameY == 2) { _mini[i].terrainFrameX = 20; _mini[i].terrainFrameY = 0; }


		else {
			_mini[i].terrainFrameX = 22; _mini[i].terrainFrameY = 0;

		}
		if ((_mini[i].objFrameX == 0 && _mini[i].objFrameY == 0 && _mini[i].obj == OBJ_TRAP)) {
			_mini[i].terrainFrameX = 8; _mini[i].terrainFrameY = 0;
		}

		else if ((_mini[i].objFrameX == 1 && _mini[i].objFrameY == 0 && _mini[i].obj == OBJ_TRAP1))
		{
			_mini[i].terrainFrameX = 8; _mini[i].terrainFrameY = 0;
		}

		else if ((_mini[i].objFrameX == 13 && _mini[i].objFrameY == 0 && _mini[i].obj == OBJ_STAIR))
		{
			_mini[i].terrainFrameX = 7; _mini[i].terrainFrameY = 0;
		}

		else if ((_mini[i].objFrameX == 14 && _mini[i].objFrameY == 0 && _mini[i].obj == OBJ_STAIR))
		{
			_mini[i].terrainFrameX = 7; _mini[i].terrainFrameY = 0;
		}
		else
		{
			_mini[i].objFrameX = 22; _mini[i].objFrameY = 0;
		}
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
	//��������
	_trapCount = 5;
	//�ִ� �� �� feature �������� ���ؼ� ���� ����
	//(feature == �� || ����)
	generate(15);

}

void tileManager::generate(int maxFeatures)
{
	_trapCount--;
	// place the first room in the center
	//_width�� ���� �ִ°ɷ� ù�� X��ġ ��������, _height�� Y��ġ, �⺻�� �߾��� 1/2
	if (!makeRoom(_width / 2, _height / 2, static_cast<Direction>(RND->getInt(4))))
		return;


	// we already placed 1 feature (the first room)
	//2��° ���� ����(1��°�� ������ ù��)
	for (int i = 1; i < maxFeatures; ++i)
	{
		if (!createFeature())
			break;
	}

	//����� ������ 
	if (_type < 4)
	{
		if (!placeObject(UpStairs))
		{
			return;
		}
	}

	//�Ʒ���� ������
	if (_type >= 4)
	{
		if (!placeObject(DownStairs))
		{
			return;
		}
	}
	//���� ����
	for (int j = 0; j < _trapCount; j++)
	{
		int i = RND->getInt(5);
		int trap = 0;
		if (i < 2)
		{
			trap = ClearTrap;
		}
		else
		{
			trap = PowerTrap;
		}
		if (!placeObject(trap))
		{
			return;
		}
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
	for (int y = rc.top - 1; y <= rc.bottom; y++)
		for (int x = rc.left - 1; x <= rc.right; x++)
		{
			int LeftCorner=((getChar(x - 1, y) == HorizontalTopWall && (getChar(x, y - 1) == VerticalLeftWall)) ||
				(getChar(x - 1, y) == LeftOpenCorner && (getChar(x, y - 1) == VerticalLeftWall)) ||
				(getChar(x - 1, y) == RightTopBlockCorner && (getChar(x, y - 1) == VerticalLeftWall)) ||
				(getChar(x - 1, y) == HorizontalTopWall && (getChar(x, y - 1) == LeftBottomBlockCorner)) ||
				(getChar(x - 1, y) == LeftOpenCorner && (getChar(x, y - 1) == LeftBottomBlockCorner)) ||
				(getChar(x - 1, y) == RightTopBlockCorner && (getChar(x, y - 1) == LeftBottomBlockCorner)) ||
				(getChar(x - 1, y) == HorizontalTopWall && (getChar(x, y - 1) == LeftOpenCorner)) ||
				(getChar(x - 1, y) == LeftOpenCorner && (getChar(x, y - 1) == LeftOpenCorner)) ||
				(getChar(x - 1, y) == RightTopBlockCorner && (getChar(x, y - 1) == LeftOpenCorner)));

			int RightCorner= ((getChar(x + 1, y) == HorizontalTopWall && (getChar(x, y - 1) == VerticalRightWall)) ||
				(getChar(x + 1, y) == RightOpenCorner && (getChar(x, y - 1) == VerticalRightWall)) ||
				(getChar(x + 1, y) == LeftTopBlockCorner && (getChar(x, y - 1) == VerticalRightWall)) ||
				(getChar(x + 1, y) == HorizontalTopWall && (getChar(x, y - 1) == RightBottomBlockCorner)) ||
				(getChar(x + 1, y) == RightOpenCorner && (getChar(x, y - 1) == RightBottomBlockCorner)) ||
				(getChar(x + 1, y) == LeftTopBlockCorner && (getChar(x, y - 1) == RightBottomBlockCorner)) ||
				(getChar(x + 1, y) == HorizontalTopWall && (getChar(x, y - 1) == RightOpenCorner)) ||
				(getChar(x + 1, y) == RightOpenCorner && (getChar(x, y - 1) == RightOpenCorner)) ||
				(getChar(x + 1, y) == LeftTopBlockCorner && (getChar(x, y - 1) == RightOpenCorner)));
			
			int RightBottom= ((getChar(x + 1, y) == HorizontalBottomWall && (getChar(x, y + 1) == VerticalRightWall)) ||
				(getChar(x + 1, y) == RightOpenBottom && (getChar(x, y + 1) == VerticalRightWall)) ||
				(getChar(x + 1, y) == LeftBottomBlockCorner && (getChar(x, y + 1) == VerticalRightWall)) ||
				(getChar(x + 1, y) == HorizontalBottomWall && (getChar(x, y + 1) == RightTopBlockCorner)) ||
				(getChar(x + 1, y) == RightOpenBottom && (getChar(x, y + 1) == RightTopBlockCorner)) ||
				(getChar(x + 1, y) == LeftBottomBlockCorner && (getChar(x, y + 1) == RightTopBlockCorner)) ||
				(getChar(x + 1, y) == HorizontalBottomWall && (getChar(x, y + 1) == RightOpenBottom)) ||
				(getChar(x + 1, y) == RightOpenBottom && (getChar(x, y + 1) == RightOpenBottom)) ||
				(getChar(x + 1, y) == LeftBottomBlockCorner && (getChar(x, y + 1) == RightOpenBottom)));
			
			int LeftBottom = ((getChar(x - 1, y) == HorizontalBottomWall && (getChar(x, y + 1) == VerticalLeftWall)) ||
				(getChar(x - 1, y) == LeftOpenBottom && (getChar(x, y + 1) == VerticalLeftWall)) ||
				(getChar(x - 1, y) == RightBottomBlockCorner && (getChar(x, y + 1) == VerticalLeftWall)) ||
				(getChar(x - 1, y) == HorizontalBottomWall && (getChar(x, y + 1) == LeftTopBlockCorner)) ||
				(getChar(x - 1, y) == LeftOpenBottom && (getChar(x, y + 1) == LeftTopBlockCorner)) ||
				(getChar(x - 1, y) == RightBottomBlockCorner && (getChar(x, y + 1) == LeftTopBlockCorner)) ||
				(getChar(x - 1, y) == HorizontalBottomWall && (getChar(x, y + 1) == LeftOpenBottom)) ||
				(getChar(x - 1, y) == LeftOpenBottom && (getChar(x, y + 1) == LeftOpenBottom)) ||
				(getChar(x - 1, y) == RightBottomBlockCorner && (getChar(x, y + 1) == LeftOpenBottom)));

			if ((x > rc.left - 1 && x < rc.right) &&
				(y == rc.top - 1) &&
				(getChar(x, y - 1) == Unused ||
					getChar(x, y - 1) == HorizontalBottomWall ||
					getChar(x, y - 1) == LeftOpenBottom ||
					getChar(x, y - 1) == RightOpenBottom))
				setChar(x, y, HorizontalTopWall);

			else if ((x > rc.left - 1 && x < rc.right) &&
				(y == rc.bottom) &&
				(getChar(x, y + 1) == Unused ||
					getChar(x, y + 1) == HorizontalTopWall ||
					getChar(x, y + 1) == LeftOpenCorner ||
					getChar(x, y + 1) == RightOpenCorner ||
					getChar(x, y + 1) == LeftOpenBottom ||
					getChar(x, y + 1) == RightOpenBottom))
				setChar(x, y, HorizontalBottomWall);

			else if ((x == rc.left - 1) &&
				(y > rc.top - 1 && y < rc.bottom) &&
				(getChar(x - 1, y) == Unused ||
					getChar(x - 1, y) == VerticalRightWall ||
					getChar(x - 1, y) == LeftOpenCorner ||
					getChar(x - 1, y) == RightOpenCorner ||
					getChar(x - 1, y) == LeftOpenBottom ||
					getChar(x - 1, y) == RightOpenBottom))
				setChar(x, y, VerticalLeftWall);

			else if ((x == rc.right) &&
				(y > rc.top - 1 && y < rc.bottom) &&
				(getChar(x + 1, y) == Unused ||
					getChar(x + 1, y) == VerticalLeftWall ||
					getChar(x + 1, y) == LeftOpenCorner ||
					getChar(x + 1, y) == RightOpenCorner ||
					getChar(x + 1, y) == LeftOpenBottom ||
					getChar(x + 1, y) == RightOpenBottom))
				setChar(x, y, VerticalRightWall);



			else if (LeftCorner)
				setChar(x, y, LeftTopBlockCorner);

			else if (RightCorner)
				setChar(x, y, RightTopBlockCorner);
			

			else if (LeftBottom)
				setChar(x, y, LeftBottomBlockCorner);

			else if (RightBottom)
				setChar(x, y, RightBottomBlockCorner);

			else if ((x == rc.right&&y == rc.bottom ||
				x == rc.left - 1 && y == rc.bottom ||
				x == rc.left - 1 && y == rc.top - 1 ||
				x == rc.right&&y == rc.top - 1) &&
				(getChar(x - 1, y) == HorizontalTopWall &&
					getChar(x + 1, y) == HorizontalTopWall))
				setChar(x, y, HorizontalTopWall);

			else if ((x == rc.right&&y == rc.bottom ||
				x == rc.left - 1 && y == rc.bottom ||
				x == rc.left - 1 && y == rc.top - 1 ||
				x == rc.right&&y == rc.top - 1) &&
				(getChar(x - 1, y) == HorizontalBottomWall &&
					getChar(x + 1, y) == HorizontalBottomWall))
				setChar(x, y, HorizontalBottomWall);

			else if ((x == rc.right&&y == rc.bottom ||
				x == rc.left - 1 && y == rc.bottom ||
				x == rc.left - 1 && y == rc.top - 1 ||
				x == rc.right&&y == rc.top - 1) &&
				(getChar(x, y - 1) == VerticalLeftWall &&
					getChar(x, y + 1) == VerticalLeftWall))
				setChar(x, y, VerticalLeftWall);

			else if ((x == rc.right&&y == rc.bottom ||
				x == rc.left - 1 && y == rc.bottom ||
				x == rc.left - 1 && y == rc.top - 1 ||
				x == rc.right&&y == rc.top - 1) &&
				(getChar(x, y - 1) == VerticalRightWall &&
					getChar(x, y + 1) == VerticalRightWall))
				setChar(x, y, VerticalRightWall);

			else if ((x == rc.left - 1 && y == rc.top - 1) &&
				((getChar(x - 1, y) == Unused && getChar(x, y - 1) == Unused) ||
				(getChar(x - 1, y) == RightOpenWall ||
					getChar(x - 1, y) == RightOpenCorner ||
					getChar(x - 1, y) == RightOpenBottom) &&
					(getChar(x, y - 1) == BottomOpenWall ||
						getChar(x, y - 1) == RightOpenBottom ||
						getChar(x, y - 1) == LeftOpenBottom)))
				setChar(x, y, LeftOpenCorner);
			else if ((x == rc.right&&y == rc.top - 1) &&
				((getChar(x + 1, y) == Unused && getChar(x, y - 1) == Unused) ||
				(getChar(x + 1, y) == LeftOpenWall ||
					getChar(x + 1, y) == LeftOpenCorner ||
					getChar(x + 1, y) == LeftOpenBottom) &&
					(getChar(x, y - 1) == BottomOpenWall ||
						getChar(x, y - 1) == RightOpenBottom ||
						getChar(x, y - 1) == LeftOpenBottom)))
				setChar(x, y, RightOpenCorner);
			else if ((x == rc.left - 1 && y == rc.bottom) &&
				((getChar(x - 1, y) == Unused && getChar(x, y + 1) == Unused) ||
				(getChar(x - 1, y) == RightOpenWall ||
					getChar(x - 1, y) == RightOpenCorner ||
					getChar(x - 1, y) == RightOpenBottom) &&
					(getChar(x, y + 1) == BottomOpenWall ||
						getChar(x, y + 1) == RightOpenBottom ||
						getChar(x, y + 1) == LeftOpenBottom)))
				setChar(x, y, LeftOpenBottom);
			else if ((x == rc.right&&y == rc.bottom) &&
				((getChar(x + 1, y) == Unused && getChar(x, y + 1) == Unused) ||
				(getChar(x + 1, y) == LeftOpenWall ||
					getChar(x + 1, y) == LeftOpenCorner ||
					getChar(x + 1, y) == LeftOpenBottom) &&
					(getChar(x, y + 1) == BottomOpenWall ||
						getChar(x, y + 1) == RightOpenBottom ||
						getChar(x, y + 1) == LeftOpenBottom)))
				setChar(x, y, RightOpenBottom);


			//else if (y == rc.top - 1 || y == rc.bottom)
			//	setChar(x, y, HorizontalWall);
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
	if (frameX == 3 && frameY == 0)
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
		return OBJ_BLOCK;
	}


	return OBJ_BLOCK;
}

void tileManager::playBGM()
{
	char music[128];

	switch (_type) {
	case 0:
		sprintf_s(music, "Mt.Bristle");
		break;
	case 1:
		sprintf_s(music, "Concealed Ruins");
		break;
	case 2:
		sprintf_s(music, "Amp Plains");
		break;
	case 3:
		sprintf_s(music, "Brine Cave");
		break;
	case 4:
		sprintf_s(music, "Waterfall Cave");
		break;
	case 5:
		sprintf_s(music, "Apple Woods");
		break;
	case 6:
		sprintf_s(music, "Craggy Coast");
		break;
	case 7:
		sprintf_s(music, "Mt.Horn");
		break;
	default:
		sprintf_s(music, "");
		break;
	}

	if (!SOUNDMANAGER->isPlaySound(music))
		SOUNDMANAGER->play(music);
}

void tileManager::stopBGM()
{
	char music[128];

	switch (_type) {
	case 0:
		sprintf_s(music, "Mt.Bristle");
		break;
	case 1:
		sprintf_s(music, "Concealed Ruins");
		break;
	case 2:
		sprintf_s(music, "Amp Plains");
		break;
	case 3:
		sprintf_s(music, "Brine Cave");
		break;
	case 4:
		sprintf_s(music, "Waterfall Cave");
		break;
	case 5:
		sprintf_s(music, "Apple Woods");
		break;
	case 6:
		sprintf_s(music, "Craggy Coast");
		break;
	case 7:
		sprintf_s(music, "Mt.Horn");
		break;
	default:
		sprintf_s(music, "");
		break;
	}

	if (SOUNDMANAGER->isPlaySound(music))
		SOUNDMANAGER->stop(music);
}
