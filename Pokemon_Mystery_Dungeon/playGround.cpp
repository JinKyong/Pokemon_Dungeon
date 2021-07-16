#include "stdafx.h"
#include "playGround.h"
#include "testScene.h"
#include "User.h"
#include "mapToolScene.h"
#include "testMapScene.h"

playGround::playGround()
{
}


playGround::~playGround()
{
}

//�ʱ�ȭ�� ����� �ϼ��� ����
HRESULT playGround::init()
{
	gameNode::init(true);

	_player = new User;
	_player->init(1);

	SCENEMANAGER->init(_player);

	SCENEMANAGER->addScene("tool", new mapToolScene);
	SCENEMANAGER->addScene("test", new testScene);
	SCENEMANAGER->addScene("map", new testMapScene);
	SCENEMANAGER->changeScene("map");

	_debug = false;

	return S_OK;
}

//�޸� ������ ����� �ϼ��� ����
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
	UIMANAGER->update();
}


void playGround::render()
{
	/*if (STREAMMANAGER->getPosition("title") < STREAMMANAGER->getLenthEnd("title"))
		return;*/

	DTDMANAGER->beginDraw();
	//================���� �� ���̿� �� �׸��ô�==========================
	SCENEMANAGER->render();

	DTDMANAGER->endDraw();
	//==================================================================
	CAMERAMANAGER->render(3 * WINSIZEX / 16, 3 * WINSIZEY / 8);
}