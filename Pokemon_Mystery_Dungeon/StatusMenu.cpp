#include "stdafx.h"
#include "StatusMenu.h"

HRESULT StatusMenu::init()
{
	UpMenu::init();

	//��� �̹���
	_back = IMAGEMANAGER->addDImage(
		"statusMenu_back", L"img/UI/statusMenu/statusMenu_back.png", UPMENU_WIDTH, UPMENU_HEIGHT);
	_baseStatusBox = IMAGEMANAGER->addDImage(
		"statusMenu_baseBox", L"img/UI/statusMenu/statusMenu_baseBox.png", UPMENU_WIDTH / 2, UPMENU_HEIGHT / 2);
	_nullStatusBox = IMAGEMANAGER->addDImage(
		"statusMenu_nullBox", L"img/UI/statusMenu/statusMenu_nullBox.png", UPMENU_WIDTH / 2, UPMENU_HEIGHT / 2);
	_statusNumber = IMAGEMANAGER->addDImage(
		"statusMenu_number", L"img/UI/statusMenu/statusMenu_number.png", 60, 60);

	return S_OK;
}

void StatusMenu::release()
{
}

void StatusMenu::update()
{
}

void StatusMenu::render()
{
	UpMenu::render();

	float width = _screen.right - _screen.left;
	float height = _screen.bottom - _screen.top;

	vector<Player*>* _teamList = TURNMANAGER->getAllPlayer();
	vector<Player*>::iterator _teamIter = _teamList->begin();
		
	D2D1_RECT_F rc = dRectMake(_screen.left + 5, _screen.top + 5, width / 2 - 10, height / 2 - 10);
	D2D1_RECT_F port = dRectMake(rc.left + 12, rc.top + 15, 60, 65);
	if ((*_teamIter)->getPlayerType() <= PLAYER_TYPE_TEAM) {
		DTDMANAGER->getRenderTarget()->DrawBitmap(_baseStatusBox->getBitmap(), rc);
		DTDMANAGER->getRenderTarget()->DrawBitmap((*_teamIter)->getPokemon()->getPortrait()->getBitmap(), port);
	}
	else
		DTDMANAGER->getRenderTarget()->DrawBitmap(_nullStatusBox->getBitmap(), rc);
	_teamIter++;

	rc.left += width / 2;
	rc.right += width / 2;
	port = dRectMake(rc.left + 12, rc.top + 15, 60, 65);
	if ((*_teamIter)->getPlayerType() <= PLAYER_TYPE_TEAM) {
		DTDMANAGER->getRenderTarget()->DrawBitmap(_baseStatusBox->getBitmap(), rc);
		DTDMANAGER->getRenderTarget()->DrawBitmap((*_teamIter)->getPokemon()->getPortrait()->getBitmap(), port);
	}
	else
		DTDMANAGER->getRenderTarget()->DrawBitmap(_nullStatusBox->getBitmap(), rc);
	_teamIter++;

	rc.left -= width / 2;
	rc.right -= width / 2;
	rc.top += height / 2;
	rc.bottom += height / 2;
	port = dRectMake(rc.left + 12, rc.top + 15, 60, 65);
	if ((*_teamIter)->getPlayerType() <= PLAYER_TYPE_TEAM) {
		DTDMANAGER->getRenderTarget()->DrawBitmap(_baseStatusBox->getBitmap(), rc);
		DTDMANAGER->getRenderTarget()->DrawBitmap((*_teamIter)->getPokemon()->getPortrait()->getBitmap(), port);
	}
	else
		DTDMANAGER->getRenderTarget()->DrawBitmap(_nullStatusBox->getBitmap(), rc);
	_teamIter++;

	rc.left += width / 2;
	rc.right += width / 2;
	port = dRectMake(rc.left + 12, rc.top + 15, 60, 65);
	if ((*_teamIter)->getPlayerType() <= PLAYER_TYPE_TEAM) {
		DTDMANAGER->getRenderTarget()->DrawBitmap(_baseStatusBox->getBitmap(), rc);
		DTDMANAGER->getRenderTarget()->DrawBitmap((*_teamIter)->getPokemon()->getPortrait()->getBitmap(), port);
	}
	else
		DTDMANAGER->getRenderTarget()->DrawBitmap(_nullStatusBox->getBitmap(), rc);

	rc = dRectMakeCenter((_screen.left + _screen.right) / 2, (_screen.top + _screen.bottom) / 2, 60, 60);
	DTDMANAGER->getRenderTarget()->DrawBitmap(_statusNumber->getBitmap(), rc);
}