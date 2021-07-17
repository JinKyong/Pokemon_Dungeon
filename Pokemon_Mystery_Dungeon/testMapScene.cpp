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

	_sample = new sampleMap;
	_sample->init();

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

	x = 0;
	y = 0;
	return S_OK;
}

void testMapScene::release()
{
}

void testMapScene::update()
{
	if (KEYMANAGER->isStayKeyDown('W'))y -= 47;
	if (KEYMANAGER->isStayKeyDown('A'))x -= 47;
	if (KEYMANAGER->isStayKeyDown('S'))y += 47;
	if (KEYMANAGER->isStayKeyDown('D'))x += 47;

	_sample->update();

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
	_sample->render();

	//_player->render();
	TURNMANAGER->render();
	EFFECTMANAGER->render();

	if (UIMANAGER->getOpen())
		UIMANAGER->renderDown();
}

void testMapScene::changeScene()
{
}

//void testMapScene::mapset()
//{
//	_maptool->example(1, 0, 0, 0, OBJ_NONE);
//	_maptool->example(2, 0, 0, 0, OBJ_NONE);
//}
