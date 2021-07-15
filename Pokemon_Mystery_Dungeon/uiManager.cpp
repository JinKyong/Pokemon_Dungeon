#include "stdafx.h"
#include "uiManager.h"

HRESULT uiManager::init()
{
	_screen = dRectMake(5 * WINSIZEX / 16, 0, 3 *  WINSIZEX / 8, 3 * WINSIZEY / 8);

	_testImage = IMAGEMANAGER->addDImage("testUPScreen", L"img/fade_B.png", 
		800, 600);
	//이미지 불러오고

	return S_OK;
}

void uiManager::release()
{
}

void uiManager::update()
{
}

void uiManager::render()
{
	DTDMANAGER->getRenderTarget()->DrawBitmap(_testImage->getBitmap(), _screen);
	//이미지 비트맵 스크린 렉트에 그리기만 하면 끝
}
