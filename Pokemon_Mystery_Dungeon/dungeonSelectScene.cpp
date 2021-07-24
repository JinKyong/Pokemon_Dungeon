#include "stdafx.h"
#include "dungeonSelectScene.h"

HRESULT dungeonSelectScene::init(Player * player)
{
	_width = 11;
	_height = 7;
	CAMERAMANAGER->setBackScreenSize(TILEWIDTH*_width, TILEHEIGHT*_height);
	_background = IMAGEMANAGER->addDImage("dungeonSelect", L"img/map/dungeonmap.png", 528, 336);

	_x = 0;
	_y = 0;
	
	TURNMANAGER->init();
	player->init(4, 5);


	TURNMANAGER->addAllPlayer(player);
	_selector = RectMake(_x,_y, 12, 12);
	_d0 = RectMake(72, 72, 24, 24);
	_d1 = RectMake(72, 200, 24, 24);
	_d2 = RectMake(72, 264, 48, 48);
	_d3 = RectMake(192, 180, 24, 24);
	_d4 = RectMake(306, 60, 24, 24);
	_d5 = RectMake(300, 120, 24, 24);
	_d6 = RectMake(294, 288, 24, 24);
	_d7 = RectMake(330, 288, 24, 24);
	return S_OK;
}

void dungeonSelectScene::release()
{
}

void dungeonSelectScene::update()
{
	RECT tmp;
	if (KEYMANAGER->isStayKeyDown('W'))_y -= 10;
	if (KEYMANAGER->isStayKeyDown('A'))_x -= 10;
	if (KEYMANAGER->isStayKeyDown('S'))_y += 10;
	if (KEYMANAGER->isStayKeyDown('D'))_x += 10;

	if (_x <= 0)_x = 0;
	if (_y <= 0)_y = 0;
	if (_x >= TILEWIDTH * _width)_x = TILEWIDTH * _width;
	if (_y >= TILEHEIGHT * _height)_y = TILEHEIGHT * _height;
	if (IntersectRect(&tmp,&_d0,&_selector))
	{
		TURNMANAGER->release();
		TILEMANAGER->setType(6);
		SCENEMANAGER->changeScene("dungeon");
	}
	if (IntersectRect(&tmp, &_d1, &_selector))
	{
		TURNMANAGER->release();
		TILEMANAGER->setType(7);
		SCENEMANAGER->changeScene("dungeon");
	}
	if (IntersectRect(&tmp, &_d2, &_selector))
	{
		TURNMANAGER->release();
		TILEMANAGER->setType(2);
		SCENEMANAGER->changeScene("dungeon");
	}
	if (IntersectRect(&tmp, &_d3, &_selector))
	{
		TURNMANAGER->release();
		TILEMANAGER->setType(1);
		SCENEMANAGER->changeScene("dungeon");
	}
	if (IntersectRect(&tmp, &_d4, &_selector))
	{
		TURNMANAGER->release();
		TILEMANAGER->setType(4);
		SCENEMANAGER->changeScene("dungeon");
	}
	if (IntersectRect(&tmp, &_d5, &_selector))
	{
		TURNMANAGER->release();
		TILEMANAGER->setType(0);
		SCENEMANAGER->changeScene("dungeon");
	}
	if (IntersectRect(&tmp, &_d6, &_selector))
	{
		TURNMANAGER->release();
		TILEMANAGER->setType(5);
		SCENEMANAGER->changeScene("dungeon");
	}
	if (IntersectRect(&tmp, &_d7, &_selector))
	{
		TURNMANAGER->release();
		TILEMANAGER->setType(3);
		SCENEMANAGER->changeScene("dungeon");
	}
	CAMERAMANAGER->updateScreen(WINSIZEX/2, WINSIZEY/2);
	_selector = RectMake(_x, _y, 12, 12);
	
}

void dungeonSelectScene::render()
{
	
	_background->render(0, 0);
	DTDMANAGER->Rectangle(_d0);
	DTDMANAGER->Rectangle(_d1);
	DTDMANAGER->Rectangle(_d2);
	DTDMANAGER->Rectangle(_d3);
	DTDMANAGER->Rectangle(_d4);
	DTDMANAGER->Rectangle(_d5);
	DTDMANAGER->Rectangle(_d6);
	DTDMANAGER->Rectangle(_d7);
	DTDMANAGER->Rectangle(_selector);
}

void dungeonSelectScene::changeScene()
{
}
