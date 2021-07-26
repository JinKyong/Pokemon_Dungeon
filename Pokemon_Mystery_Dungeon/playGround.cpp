#include "stdafx.h"
#include "playGround.h"
#include "testScene.h"
#include "User.h"
#include "mapToolScene.h"
#include "testMapScene.h"
#include "bossMapScene.h"
#include "dungeonSelectScene.h"
#include "dungeonScene.h"
#include "townMapScene.h"
#include "guildMapScene.h"
#include "crossroadScene.h"
#include "titleScene.h"
#include "mainScene.h"


playGround::playGround()
{
}


playGround::~playGround()
{
}

//초기화는 여기다 하세요 제발
HRESULT playGround::init()
{
	gameNode::init(true);

	_player = new User;
	_player->init(RND->getInt(15) + 1);

	SCENEMANAGER->init(_player);

	SCENEMANAGER->addScene("tool", new mapToolScene);
	SCENEMANAGER->addScene("test", new testScene);
	SCENEMANAGER->addScene("map", new testMapScene);
	SCENEMANAGER->addScene("boss", new bossMapScene);
	SCENEMANAGER->addScene("select", new dungeonSelectScene);
	SCENEMANAGER->addScene("dungeon", new dungeonScene);
	SCENEMANAGER->addScene("crossroad", new crossroadScene);
	SCENEMANAGER->addScene("town", new townMapScene);
	SCENEMANAGER->addScene("guild", new guildMapScene);
	SCENEMANAGER->addScene("title", new titleScene);
	SCENEMANAGER->addScene("main", new mainScene);

	SCENEMANAGER->changeScene("dungeon");
	BATTLEMANAGER->init();

	_debug = false;

	return S_OK;
}

//메모리 해제는 여기다 하세요 제발
void playGround::release()
{
	gameNode::release();


}


void playGround::update()
{
	gameNode::update();

	if (KEYMANAGER->isOnceKeyDown(VK_TAB)) {
		_debug = !_debug;
		PRINTMANAGER->setDebug(_debug);
	}

	SCENEMANAGER->update();
}


void playGround::render()
{
	if (STREAMMANAGER->getCurrentVideo()) {
		if (STREAMMANAGER->getPosition() < STREAMMANAGER->getLength())
			return;
	}

	DTDMANAGER->beginDraw();
	//================제발 이 사이에 좀 그립시다==========================
	SCENEMANAGER->render();

	DTDMANAGER->endDraw();
	//==================================================================
	CAMERAMANAGER->render(3 * WINSIZEX / 16, 3 * WINSIZEY / 8);
}