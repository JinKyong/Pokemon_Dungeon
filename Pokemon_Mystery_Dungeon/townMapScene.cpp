#include "stdafx.h"
#include "townMapScene.h"
#include "Apple.h"

HRESULT townMapScene::init(Player * player)
{
	Scene::init(player);
	_width = 24;
	_height = 10;
	_type = 0;
	TILEMANAGER->setType(_type);
//	TILEMANAGER->init(_width, _height);
	TILEMANAGER->load("townmap.map");
	_background = IMAGEMANAGER->addDImage("town", L"img/map/village.png", 1152, 480);
	CAMERAMANAGER->setBackScreenSize((_width)* TILEWIDTH, (_height)* TILEHEIGHT);
	TURNMANAGER->init();
	player->init(24,4);


	TURNMANAGER->addAllPlayer(player);
	_itemManager = new ItemManager;
	_itemManager->init();

	Apple* apple;
	apple = new Apple;
	apple->init(5, 5, PI);

	COLLISIONMANAGER->init(this);
	return S_OK;
}

void townMapScene::release()
{
}

void townMapScene::update()
{
	if (UIMANAGER->getOpen())
		UIMANAGER->update();
	else {
		_itemManager->update();
		TURNMANAGER->update();
		EFFECTMANAGER->update();
	}
	if (_player->getX() < 1)
	{
		_player->setX(1);
	}
	if (_player->getX() > 24)
	{
		this->release();
		SCENEMANAGER->changeScene("crossroad");
	}
	CAMERAMANAGER->updateScreen(_player->getX(), _player->getY());
}

void townMapScene::render()
{
	TILEMANAGER->maprender();
	_background->render(0, 0);
	_itemManager->render();
	TURNMANAGER->render();
	EFFECTMANAGER->render();

	UIMANAGER->renderDown();
}

void townMapScene::changeScene()
{
}
