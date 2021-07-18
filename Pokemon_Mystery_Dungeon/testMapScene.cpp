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

	TILEMANAGER->init(MAPWIDTH, MAPHEIGHT);
	CAMERAMANAGER->setBackScreenSize((MAPWIDTH - 1) * TILEWIDTH, (MAPHEIGHT - 1) * TILEHEIGHT);
	//TILEMANAGER->load("tileSave.map");

	TURNMANAGER->init();
	TURNMANAGER->addAllPlayer(player);

	_pokemon1 = new Enemy;
	_pokemon1->init(RND->getInt(15) + 1);
	TURNMANAGER->addAllPlayer(_pokemon1);

	//_pokemon2 = new Enemy;
	//_pokemon2->init(RND->getInt(15) + 1);
	//TURNMANAGER->addAllPlayer(_pokemon2);
	//
	//_pokemon3 = new Enemy;
	//_pokemon3->init(RND->getInt(15) + 1);
	//TURNMANAGER->addAllPlayer(_pokemon3);

	_im = new ItemManager;
	_im->init();

	Apple* apple;
	apple = new Apple;
	apple->init(25, 15, PI);

	Gummy* jelly;
	jelly = new Gummy;
	jelly->init(26, 15, PI);

	ThrowItem* titem;
	titem = new ThrowItem;
	titem->init(27, 15, PI);

	_im->addItem(apple);
	_im->addItem(jelly);
	_im->addItem(titem);

	COLLISIONMANAGER->init(this, _im);

	return S_OK;
}

void testMapScene::release()
{
	TILEMANAGER->release();
}

void testMapScene::update()
{
	TILEMANAGER->update();
	if (UIMANAGER->getOpen())
		UIMANAGER->update();
	else {
		_im->update();
		TURNMANAGER->update();
		EFFECTMANAGER->update();
	}

	CAMERAMANAGER->updateScreen(_player->getX(), _player->getY());

}

void testMapScene::render()
{

	TILEMANAGER->render();
	_im->render();
	TURNMANAGER->render();
	EFFECTMANAGER->render();

	UIMANAGER->renderDown();
}

void testMapScene::changeScene()
{
}
