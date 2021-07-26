#include "stdafx.h"
#include "crossroadScene.h"
#include "Apple.h"

HRESULT crossroadScene::init(Player * player)
{
	Scene::init(player);
	_width = 8;
	_height = 10;
	_type = 0;
	TILEMANAGER->setType(_type);
//	TILEMANAGER->init(_width, _height);
	TILEMANAGER->load("crossroad.map");
	_background = IMAGEMANAGER->addDImage("crossroad", L"img/map/crossroad.png", 384, 480);
	CAMERAMANAGER->setBackScreenSize((_width)* TILEWIDTH, (_height)* TILEHEIGHT);
	TURNMANAGER->init();
	player->init(4, 5);


	TURNMANAGER->addAllPlayer(player);
	_itemManager = new ItemManager;
	_itemManager->init();

	Apple* apple;
	apple = new Apple;
	apple->init(5, 5, PI);

	COLLISIONMANAGER->init(this);
	return S_OK;
}

void crossroadScene::release()
{
}

void crossroadScene::update()
{
	if (UIMANAGER->getOpen())
		UIMANAGER->update();
	else {
		_itemManager->update();
		TURNMANAGER->update();
		EFFECTMANAGER->update();
	}
	CAMERAMANAGER->updateScreen(_player->getX(), _player->getY());
	if (_player->getX() < 1)
	{
		TURNMANAGER->release();
		SCENEMANAGER->changeScene("town");

	}
	if (_player->getY() > 8)
	{
		TURNMANAGER->release();
		SCENEMANAGER->changeScene("select");
	}
	if (_player->getY() < 1)
	{
		TURNMANAGER->release();
		SCENEMANAGER->changeScene("guild");
	}
	if (_player->getX() > 8)
	{
		_player->setX(8);
	}
}

void crossroadScene::render()
{
	TILEMANAGER->maprender();
	_background->render(0, 0);
	_itemManager->render();
	TURNMANAGER->render();
	EFFECTMANAGER->render();

	UIMANAGER->renderDown();
}

void crossroadScene::changeScene()
{
}
