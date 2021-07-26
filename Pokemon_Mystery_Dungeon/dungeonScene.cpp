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

	_width = 151;
	_height = 151; 
	_type = TILEMANAGER->getType();

	TILEMANAGER->init(_width, _height, _type);
	CAMERAMANAGER->setBackScreenSize((_width - 1) * TILEWIDTH, (_height - 1) * TILEHEIGHT);
	
	TURNMANAGER->init();
	TURNMANAGER->addAllPlayer(player);

	_pokemon1 = new Enemy;
	_pokemon1->init(TILEMANAGER->getEnemy1());
	TURNMANAGER->addAllPlayer(_pokemon1);


	_pokemon2 = new Enemy;
	_pokemon2->init(TILEMANAGER->getEnemy2());
	TURNMANAGER->addAllPlayer(_pokemon2);

	_pokemon3 = new Enemy;
	_pokemon3->init(TILEMANAGER->getEnemy3());
	TURNMANAGER->addAllPlayer(_pokemon3);

	

	_itemManager = new ItemManager;
	_itemManager->init();
	TURNMANAGER->randomSetting();

	UIMANAGER->changeUpMenu("statusMenu");
	UIMANAGER->changeDownMenu("logMenu");
	COLLISIONMANAGER->init(this);

	return S_OK;
}

void dungeonScene::release()
{
	TILEMANAGER->release();
}

void dungeonScene::update()
{
	if (KEYMANAGER->isOnceKeyDown('T'))
	{
		this->release();
		TURNMANAGER->release();
		SCENEMANAGER->changeScene("select");
	}
	if (KEYMANAGER->isOnceKeyDown('R'))
	{
		if (SCENEMANAGER->getSceneCount() >= 5)
		{
			this->release();
			TURNMANAGER->release();
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
	//for(int i=0;i<_width*_height;++i)
	//{
	//	TILEMANAGER->getvTile()[i].
	//}
	////if (_mini[i].rc.left == (_playerX * 8) && _mini[i].rc.top == (_playerY * 8))
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
