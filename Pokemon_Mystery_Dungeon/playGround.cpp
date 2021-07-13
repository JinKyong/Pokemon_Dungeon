#include "stdafx.h"
#include "playGround.h"
#include "testScene.h"

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

	_player = new Player;
	_player->init();

	SCENEMANAGER->init(_player);

	SCENEMANAGER->addScene("test", new testScene);
	SCENEMANAGER->changeScene("test");

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
	/*if (STREAMMANAGER->getPosition("title") < STREAMMANAGER->getLenthEnd("title"))
		return;*/

	DTDMANAGER->beginDraw();
	//PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, BLACKNESS);
	//================제발 이 사이에 좀 그립시다==========================

	////글자 배경색 모드
	//SetBkMode(getMemDC(), TRANSPARENT);
	//SetTextColor(getMemDC(), RGB(255, 255, 255));
	////투명 브러쉬
	//HBRUSH myBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
	//HBRUSH oldBrush = (HBRUSH)SelectObject(getMemDC(), myBrush);


	//HPEN myPen = (HPEN)CreatePen(1, 2, RGB(255, 0, 0));
	//SelectObject(getMemDC(), myPen);

	////_player->render();
	//SCENEMANAGER->render();

	//SelectObject(getMemDC(), oldBrush);
	//DeleteObject(myPen);
	//DeleteObject(myBrush);


	SCENEMANAGER->render();

	DTDMANAGER->endDraw();
	//==================================================s
	//this->getBackBuffer()->render(getHDC(), 0, 0);
	CAMERAMANAGER->render(3 * WINSIZEX / 16, 3 * WINSIZEY / 8);
}