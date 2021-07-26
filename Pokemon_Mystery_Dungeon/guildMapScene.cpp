#include "stdafx.h"
#include "guildMapScene.h"
#include "Apple.h"

HRESULT guildMapScene::init(Player * player)
{
	Scene::init(player);
	_width = 8;
	_height = 8;
	_type = 0;
	TILEMANAGER->setType(_type);
//	TILEMANAGER->init(_width, _height);
	TILEMANAGER->load("housemap.map");
	_background = IMAGEMANAGER->addDImage("guild", L"img/map/house.png", 384, 384);
	CAMERAMANAGER->setBackScreenSize((_width)* TILEWIDTH, (_height)* TILEHEIGHT);
	TURNMANAGER->init();
	player->initXY(4,8);

	_itemManager = new ItemManager;
	_itemManager->init();

	Apple* apple;
	apple = new Apple;
	apple->init(5, 5, PI);

	COLLISIONMANAGER->init(this);
	return S_OK;
}

void guildMapScene::release()
{
}

void guildMapScene::update()
{
	if (UIMANAGER->getOpen())
		UIMANAGER->update();
	else {
		_itemManager->update();
		TURNMANAGER->update();
		EFFECTMANAGER->update();
	}
	CAMERAMANAGER->updateScreen(_player->getX(), _player->getY());
	if (_player->getY() > 8)
	{
		this->release();
		SCENEMANAGER->changeScene("crossroad");
	}
}

void guildMapScene::render()
{
	TILEMANAGER->maprender();
	_background->render(0, 0);
	_itemManager->render();
	TURNMANAGER->render();
	EFFECTMANAGER->render();

	UIMANAGER->renderDown();
}

void guildMapScene::changeScene()
{
}
