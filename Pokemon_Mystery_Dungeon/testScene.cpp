#include "stdafx.h"
#include "testScene.h"
#include "Player.h"
#include "Enemy.h"
#include "Apple.h"
#include "Gummy.h"
#include "ThrowItem.h"

HRESULT testScene::init(Player * player)
{
	Scene::init(player);

	CAMERAMANAGER->setBackScreenSize(3840, 2160);

	TURNMANAGER->init();
	TURNMANAGER->addAllPlayer(player);
	//_testEnemy = new Enemy;
	//_testEnemy->init(3);
	//TURNMANAGER->addAllPlayer(_testEnemy);

	_im = new ItemManager;
	_im->init();

	Apple* apple;
	apple = new Apple;
	apple->init(20 * TILEWIDTH, 20 * TILEHEIGHT, PI);

	Gummy* jelly;
	jelly = new Gummy;
	jelly->init(35 * TILEWIDTH, 25 * TILEHEIGHT, PI);

	ThrowItem* titem;
	titem = new ThrowItem;
	titem->init(35, 30, PI);

	_im->addItem(apple);
	_im->addItem(jelly);
	_im->addItem(titem);

	_back = IMAGEMANAGER->addDImage("back", L"img/sample1.jpg", 3840, 2160);
	
	return S_OK;
}

void testScene::release()
{
}

void testScene::update()
{
	//_player->update();

	TURNMANAGER->update();
	EFFECTMANAGER->update();

	_im->update();

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

	_im->render();
}

void testScene::changeScene()
{
}