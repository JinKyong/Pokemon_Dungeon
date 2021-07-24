#include "stdafx.h"
#include "dungeonScene.h"
#include "Team.h"
#include "Enemy.h"
#include "Apple.h"
#include "Gummy.h"
#include "ThrowItem.h"

HRESULT dungeonScene::init(Player * player)
{
	Scene::init(player);
	_width = 121;
	_height = 121; 
	_type=TILEMANAGER->getType();
	TILEMANAGER->init(_width, _height, _type);
	CAMERAMANAGER->setBackScreenSize((_width - 1) * TILEWIDTH, (_height - 1) * TILEHEIGHT);
	
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

	TURNMANAGER->randomSetting();

	_itemManager = new ItemManager;
	_itemManager->init();

	COLLISIONMANAGER->init(this);

	return S_OK;
}

void dungeonScene::release()
{
	TILEMANAGER->release();
}

void dungeonScene::update()
{
	if (KEYMANAGER->isOnceKeyDown('T'))SCENEMANAGER->changeScene("select");
	if (KEYMANAGER->isOnceKeyDown('R'))
	{
		if (SCENEMANAGER->getSceneCount() >= 5)
		{
			this->release();
			SCENEMANAGER->changeScene("boss");
		}
		else
		{
			
			SCENEMANAGER->setSceneCount(SCENEMANAGER->getSceneCount()+1);
			TILEMANAGER->init(_width, _height, _type);
			_player->release();
			TURNMANAGER->randomSetting();

		}
	}
	TILEMANAGER->update();

	//if (DIALOGMANAGER->getPrint())
	//	DIALOGMANAGER->update();
	//else {
		if (UIMANAGER->getOpen())
			UIMANAGER->update();
		else {
			_itemManager->update();
			TURNMANAGER->update();
			EFFECTMANAGER->update();
		}
	//}

	CAMERAMANAGER->updateScreen(_player->getX(), _player->getY());
}

void dungeonScene::render()
{
	TILEMANAGER->render();

	_itemManager->render();
	TURNMANAGER->render();
	EFFECTMANAGER->render();

	UIMANAGER->renderDown();

//if (DIALOGMANAGER->getPrint())
//	DIALOGMANAGER->render();
}

void dungeonScene::changeScene()
{
}
