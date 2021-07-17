#include "stdafx.h"
#include "uiManager.h"

HRESULT uiManager::init()
{
	_back = IMAGEMANAGER->addDImage("black", L"img/fade_B.png", 800, 600);

	keySetting();
	status();

	//이미지 불러오고 
	_key = 0;
	_option = 0;
	return S_OK;
}

void uiManager::release()
{
}

void uiManager::update()
{
	if (KEYMANAGER->isOnceKeyDown(VK_F2))
	{
		_key++;
		if (_key > 1) _key = 0;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_F3))
	{					
		_option++;
		if (_option > 1) _option = 0;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_F4))
	{
		_isNull = !_isNull;
		if (_isNull) _testStat = IMAGEMANAGER->findDImage("statNull");
		else		 _testStat = IMAGEMANAGER->findDImage("stat");
	}
}

void uiManager::render()
{
	//테스트키 변수 하나줘서 바꿀수있게

	if (_option == 0)
	{
		DTDMANAGER->getRenderTarget()->DrawBitmap(_testKey[_key]->getBitmap(), _screen);
	}

	else if (_option == 1)
	{
		DTDMANAGER->getRenderTarget()->DrawBitmap(_back->getBitmap(), _screen);

		DTDMANAGER->getRenderTarget()->DrawBitmap(_testStat->getBitmap(), _status[0]);
		DTDMANAGER->getRenderTarget()->DrawBitmap(_testStat->getBitmap(), _status[1]);
		DTDMANAGER->getRenderTarget()->DrawBitmap(_testStat->getBitmap(), _status[2]);
		DTDMANAGER->getRenderTarget()->DrawBitmap(_testStat->getBitmap(), _status[3]);
		DTDMANAGER->getRenderTarget()->DrawBitmap(_pokeNum->getBitmap(), _pokeNumRC);
	}
	//이미지 비트맵 스크린 렉트에 그리기만 하면 끝
}

void uiManager::keySetting()
{
	_screen = dRectMake(5 * WINSIZEX / 16, 0, 3 * WINSIZEX / 8, 3 * WINSIZEY / 8);

	_testKey[0] = IMAGEMANAGER->addDImage("KeySetting_dungeon", L"img/ui/KeySetting_dungeon.png", 512, 384);
	_testKey[1] = IMAGEMANAGER->addDImage("KeySetting_town", L"img/ui/KeySetting_town.png", 512, 384);
}

void uiManager::status()
{
	_isNull = false;
	_screen = dRectMake(5 * WINSIZEX / 16, 0, 3 * WINSIZEX / 8, 3 * WINSIZEY / 8);
	_pokeNumRC = dRectMakeCenter(_screen.left + STATUSWIDTH, (_screen.top + _screen.bottom) / 2, 60, 50);

	_status[0] = dRectMake(_screen.left, _screen.top, STATUSWIDTH, (_screen.top + _screen.bottom) / 2);
	_status[1] = dRectMake(_status[0].right, _screen.top, STATUSWIDTH, (_screen.top + _screen.bottom) / 2);
	_status[2] = dRectMake(_screen.left, _status[0].bottom, STATUSWIDTH, (_screen.top + _screen.bottom) / 2);
	_status[3] = dRectMake(_status[2].right, _status[0].bottom, STATUSWIDTH, (_screen.top + _screen.bottom) / 2);

	IMAGEMANAGER->addDImage("statNull", L"img/ui/stat_nullBox.png", 248, 184);
	_testStat = IMAGEMANAGER->addDImage("stat", L"img/ui/stat_baseBox.png", 248, 184);
	_pokeNum = IMAGEMANAGER->addDImage("pokeNum", L"img/ui/stat_number.png", 60, 60);
}