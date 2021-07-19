#include "stdafx.h"
#include "testScene.h"
#include "Player.h"
#include "Enemy.h"

HRESULT testScene::init(Player * player)
{
	Scene::init(player);

	CAMERAMANAGER->setBackScreenSize(3840, 2160);
	_back = IMAGEMANAGER->addDImage("back", L"img/sample1.jpg", 3840, 2160);

	TURNMANAGER->init();
	TURNMANAGER->addAllPlayer(player);
	//_testEnemy = new Enemy;
	//_testEnemy->init(3);
	//TURNMANAGER->addAllPlayer(_testEnemy);

	DIALOGMANAGER->init();
	DIALOGMANAGER->loadMetaData(L"data/test3");
	
	return S_OK;
}

void testScene::release()
{
}

void testScene::update()
{
	//_player->update();

	if (DIALOGMANAGER->getPrint())
		DIALOGMANAGER->update();
	else {
		TURNMANAGER->update();
		EFFECTMANAGER->update();
	}

	CAMERAMANAGER->updateScreen(_player->getX(), _player->getY());
	//CAMERAMANAGER->vibrateScreen(_player->getX(), _player->getY());
}

void testScene::render()
{
	//배경(이미지 클리핑)
	D2D1_RECT_F rc = CAMERAMANAGER->getScreen();
	_back->render(rc.left, rc.top, rc.left, rc.top,
		rc.right - rc.left, rc.bottom - rc.top);

	if (PRINTMANAGER->isDebug()) {
		for (int i = TILEHEIGHT / 2; i < _back->getHeight(); i += TILEHEIGHT)
			for (int j = TILEWIDTH / 2; j < _back->getWidth(); j += TILEWIDTH) {
				D2D1_RECT_F tmp = dRectMakeCenter(j, i, TILEWIDTH, TILEHEIGHT);
				DTDMANAGER->Rectangle(tmp);
			}
	}

	//_player->render();
	TURNMANAGER->render();
	EFFECTMANAGER->render();
	if (DIALOGMANAGER->getPrint())
		DIALOGMANAGER->render();
}

void testScene::changeScene()
{
}