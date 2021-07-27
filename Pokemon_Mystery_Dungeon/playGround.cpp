#include "stdafx.h"
#include "playGround.h"
#include "testScene.h"
#include "User.h"


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

	SCENEMANAGER->init(_player);

	SCENEMANAGER->changeScene("title");

	BATTLEMANAGER->init();
	DIALOGMANAGER->init();

	_debug = false;

	return S_OK;
}

//�޸� ������ ����� �ϼ��� ����
void playGround::release()
{
	gameNode::release();

	BATTLEMANAGER->release();
	BATTLEMANAGER->releaseSingleton();

	DIALOGMANAGER->release();
	DIALOGMANAGER->releaseSingleton();
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
	//================���� �� ���̿� �� �׸��ô�==========================
	SCENEMANAGER->render();

	DTDMANAGER->endDraw();
	//==================================================================
	CAMERAMANAGER->render(3 * WINSIZEX / 16, 3 * WINSIZEY / 8);
}