#include "stdafx.h"
#include "uiManager.h"

HRESULT uiManager::init()
{
	_screen = dRectMake(5 * WINSIZEX / 16, 0, 3 * WINSIZEX / 8, 3 * WINSIZEY / 8);

	_testImage[0] = IMAGEMANAGER->addDImage("KeySetting_dungeon", L"img/ui/KeySetting_dungeon.png", 512, 384);
	_testImage[1] = IMAGEMANAGER->addDImage("KeySetting_town", L"img/ui/KeySetting_town.png", 512, 384);
	//이미지 불러오고
	_testKey = 0;
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
	for (int i = 0; i < 2; i++)
	{
		DTDMANAGER->getRenderTarget()->DrawBitmap(_testImage[_testKey]->getBitmap(), _screen);
	}
	if (KEYMANAGER->isOnceKeyDown(VK_F2)) _testKey++;
	if (_testKey > 1) _testKey = 0;
	//이미지 비트맵 스크린 렉트에 그리기만 하면 끝
}
