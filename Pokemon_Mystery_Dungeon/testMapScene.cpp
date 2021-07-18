#include "stdafx.h"
#include "testMapScene.h"
#include "Team.h"
#include "Enemy.h"
#include "Apple.h"
#include "Gummy.h"
#include "ThrowItem.h"

HRESULT testMapScene::init(Player * player)
{
	Scene::init(player);

	_width = 80;
	_height = 45;
	CAMERAMANAGER->setBackScreenSize(TILEWIDTH*_width, TILEHEIGHT*_height);

	TILEMANAGER->init();
	TILEMANAGER->load("tileSave.map");

	TURNMANAGER->init();
	TURNMANAGER->addAllPlayer(player);

	_pokemon1 = new Enemy;
	_pokemon1->init(RND->getInt(15) + 1);
	TURNMANAGER->addAllPlayer(_pokemon1);

	_pokemon2 = new Enemy;
	_pokemon2->init(RND->getInt(15) + 1);
	TURNMANAGER->addAllPlayer(_pokemon2);

	_pokemon3 = new Enemy;
	_pokemon3->init(RND->getInt(15) + 1);
	TURNMANAGER->addAllPlayer(_pokemon3);

	_im = new ItemManager;
	_im->init();

	Apple* apple;
	apple = new Apple;
	apple->init(25, 20, PI);

	Gummy* jelly;
	jelly = new Gummy;
	jelly->init(26, 20, PI);

	ThrowItem* titem;
	titem = new ThrowItem;
	titem->init(27, 20, PI);

	_im->addItem(apple);
	_im->addItem(jelly);
	_im->addItem(titem);

	COLLISIONMANAGER->init(this, _im);

	return S_OK;
}

void testMapScene::release()
{
}

void testMapScene::update()
{

	
	TILEMANAGER->update();
	if (UIMANAGER->getOpen())
		UIMANAGER->update();
	else {
		TURNMANAGER->update();
		EFFECTMANAGER->update();
	}

	CAMERAMANAGER->updateScreen(_player->getX(), _player->getY());

	_im->update();
}

void testMapScene::render()
{
	
	TILEMANAGER->render();
	//_player->render();
	TURNMANAGER->render();
	EFFECTMANAGER->render();

	if (UIMANAGER->getOpen())
		UIMANAGER->renderDown();

	_im->render();
}

void testMapScene::changeScene()
{
}
