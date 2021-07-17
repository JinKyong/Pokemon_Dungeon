#include "stdafx.h"
#include "testMapScene.h"
#include "Team.h"
#include "Enemy.h"

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
}

void testMapScene::render()
{
	
	TILEMANAGER->render();
	//_player->render();
	TURNMANAGER->render();
	EFFECTMANAGER->render();

	if (UIMANAGER->getOpen())
		UIMANAGER->renderDown();
}

void testMapScene::changeScene()
{
}
