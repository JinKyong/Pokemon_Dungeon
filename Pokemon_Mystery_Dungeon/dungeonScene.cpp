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
		if (TILEMANAGER->getFloor() == 2) {
			SCENEMANAGER->changeScene("result");
			char music[128];

			switch (TILEMANAGER->getType()) {
			case 0:
				sprintf_s(music, "Mt.Bristle");
				break;
			case 1:
				sprintf_s(music, "Concealed Ruins");
				break;
			case 2:
				sprintf_s(music, "Amp Plains");
				break;
			case 3:
				sprintf_s(music, "Brine Cave");
				break;
			case 4:
				sprintf_s(music, "Waterfall Cave");
				break;
			case 5:
				sprintf_s(music, "Apple Woods");
				break;
			case 6:
				sprintf_s(music, "Craggy Coast");
				break;
			case 7:
				sprintf_s(music, "Mt.Horn");
				break;
			default:
				sprintf_s(music, "");
				break;
			}

			if (SOUNDMANAGER->isPlaySound(music))
				SOUNDMANAGER->stop(music);
		}
		else
			SCENEMANAGER->changeScene("loading");
	}
}
