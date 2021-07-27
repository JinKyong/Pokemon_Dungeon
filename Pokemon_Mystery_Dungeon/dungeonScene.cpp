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

	CAMERAMANAGER->setBackScreenSize((TILEMANAGER->getWidth() - 1) * TILEWIDTH, (TILEMANAGER->getHeight() - 1) * TILEHEIGHT);

	//TILEMANAGER->init();
	TURNMANAGER->init();

	TURNMANAGER->randomSetting();

	_itemManager = new ItemManager;
	_itemManager->init();

	UIMANAGER->changeUpMenu("statusMenu");
	UIMANAGER->changeDownMenu("logMenu");

	COLLISIONMANAGER->init(this);

	return S_OK;
}

void dungeonScene::release()
{
	TILEMANAGER->release();
	TURNMANAGER->release();
}

void dungeonScene::update()
{
	TILEMANAGER->update();

		if (UIMANAGER->getOpen())
			UIMANAGER->update();
		else {
			_itemManager->update();
			TURNMANAGER->update();
			EFFECTMANAGER->update();
		}
	changeScene();

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
	if (CAMERAMANAGER->getAlpha() == 1.0) {
		if (TILEMANAGER->getFloor() == 10)
			SCENEMANAGER->changeScene("result");
		else
			SCENEMANAGER->changeScene("loading");
	}
}
