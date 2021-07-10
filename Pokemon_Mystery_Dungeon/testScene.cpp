#include "stdafx.h"
#include "testScene.h"

HRESULT testScene::init()
{
	CAMERAMANAGER->setBackScreenSize(3840, 2160);

	_back = IMAGEMANAGER->addDImage("back", L"img/sample1.jpg", 3840, 2160);
	_moveImg = IMAGEMANAGER->addFrameDImage("booster", L"img/idle1.png", 156, 54, 3, 1);

	_x = WINSIZEX / 2;
	_y = WINSIZEY / 2;

	_frameX = 0;
	_frameY = 0;

	_angle = 0;
	_rotate = false;

	return S_OK;
}

void testScene::release()
{
}

void testScene::update()
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
		_x -= 5;
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
		_x += 5;
	if (KEYMANAGER->isStayKeyDown(VK_UP))
		_y -= 5;
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
		_y += 5;

	if (KEYMANAGER->isStayKeyDown(VK_SPACE)) {
		_angle+= 25;
		if (_angle >= 360)
			_angle -= 360;
	}

	_rc = RectMakeCenter(_x, _y, 100, 100);

	CAMERAMANAGER->updateScreen(_x, _y);
}

void testScene::render()
{
	controlFrame();

	D2D1_RECT_F rc = CAMERAMANAGER->getScreen();
	_back->render(rc.left, rc.top, rc.left, rc.top,
		rc.right - rc.left, rc.bottom - rc.top);

	DTDMANAGER->setRotate(_angle, _x, _y);
	_moveImg->frameRender(_x - _moveImg->getFrameWidth() / 2, _y - _moveImg->getFrameHeight() / 2, _frameX, _frameY);
	DTDMANAGER->Rectangle(_rc);
	DTDMANAGER->resetTransform();
}

void testScene::changeScene()
{
}

void testScene::controlFrame()
{
	_count++;

	if (_count > 5) {
		if (_frameX >= _moveImg->getMaxFrameX())
			_frameX = 0;
		else
			_frameX++;

		_count = 0;
	}
}
