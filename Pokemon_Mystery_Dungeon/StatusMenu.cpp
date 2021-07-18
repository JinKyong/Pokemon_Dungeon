#include "stdafx.h"
#include "StatusMenu.h"

HRESULT StatusMenu::init()
{
	UpMenu::init();

	//배경 이미지
	_back = IMAGEMANAGER->addDImage(
		"statusMenu_back", L"img/UI/statusMenu/back.png", UPMENU_WIDTH, UPMENU_HEIGHT);
	_baseStatusBox = IMAGEMANAGER->addDImage(
		"statusMenu_baseBox", L"img/UI/statusMenu/baseBox.png", UPMENU_WIDTH / 2, UPMENU_HEIGHT / 2);
	_nullStatusBox = IMAGEMANAGER->addDImage(
		"statusMenu_nullBox", L"img/UI/statusMenu/nullBox.png", UPMENU_WIDTH / 2, UPMENU_HEIGHT / 2);
	_statusNumber = IMAGEMANAGER->addDImage(
		"statusMenu_number", L"img/UI/statusMenu/number.png", 60, 60);

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
	int i = 0;

	D2D1_RECT_F rc = dRectMake(_screen.left + 5, _screen.top + 5, width / 2 - 10, height / 2 - 10);
	D2D1_RECT_F port = dRectMake(rc.left + 12, rc.top + 15, 60, 65);

	if(i >= _teamList->size())
		DTDMANAGER->getRenderTarget()->DrawBitmap(_nullStatusBox->getBitmap(), rc);
	else if((*_teamList)[i]->getPlayerType() <= PLAYER_TYPE_TEAM) {
		DTDMANAGER->getRenderTarget()->DrawBitmap(_baseStatusBox->getBitmap(), rc);
		DTDMANAGER->getRenderTarget()->DrawBitmap((*_teamList)[i]->getPokemon()->getPortrait()->getBitmap(), port);
	}
	else
		DTDMANAGER->getRenderTarget()->DrawBitmap(_nullStatusBox->getBitmap(), rc);
	i++;

	rc.left += width / 2;
	rc.right += width / 2;
	port = dRectMake(rc.left + 12, rc.top + 15, 60, 65);
	if (i >= _teamList->size())
		DTDMANAGER->getRenderTarget()->DrawBitmap(_nullStatusBox->getBitmap(), rc);
	else if ((*_teamList)[i]->getPlayerType() <= PLAYER_TYPE_TEAM) {
		DTDMANAGER->getRenderTarget()->DrawBitmap(_baseStatusBox->getBitmap(), rc);
		DTDMANAGER->getRenderTarget()->DrawBitmap((*_teamList)[i]->getPokemon()->getPortrait()->getBitmap(), port);
	}
	else
		DTDMANAGER->getRenderTarget()->DrawBitmap(_nullStatusBox->getBitmap(), rc);
	i++;

	rc.left -= width / 2;
	rc.right -= width / 2;
	rc.top += height / 2;
	rc.bottom += height / 2;
	port = dRectMake(rc.left + 12, rc.top + 15, 60, 65);
	if (i >= _teamList->size())
		DTDMANAGER->getRenderTarget()->DrawBitmap(_nullStatusBox->getBitmap(), rc);
	else if ((*_teamList)[i]->getPlayerType() <= PLAYER_TYPE_TEAM) {
		DTDMANAGER->getRenderTarget()->DrawBitmap(_baseStatusBox->getBitmap(), rc);
		DTDMANAGER->getRenderTarget()->DrawBitmap((*_teamList)[i]->getPokemon()->getPortrait()->getBitmap(), port);
	}
	else
		DTDMANAGER->getRenderTarget()->DrawBitmap(_nullStatusBox->getBitmap(), rc);
	i++;

	rc.left += width / 2;
	rc.right += width / 2;
	port = dRectMake(rc.left + 12, rc.top + 15, 60, 65);
	if (i >= _teamList->size())
		DTDMANAGER->getRenderTarget()->DrawBitmap(_nullStatusBox->getBitmap(), rc);
	else if ((*_teamList)[i]->getPlayerType() <= PLAYER_TYPE_TEAM) {
		DTDMANAGER->getRenderTarget()->DrawBitmap(_baseStatusBox->getBitmap(), rc);
		DTDMANAGER->getRenderTarget()->DrawBitmap((*_teamList)[i]->getPokemon()->getPortrait()->getBitmap(), port);
	}
	else
		DTDMANAGER->getRenderTarget()->DrawBitmap(_nullStatusBox->getBitmap(), rc);
	i++;

	rc = dRectMakeCenter((_screen.left + _screen.right) / 2, (_screen.top + _screen.bottom) / 2, 60, 60);
	DTDMANAGER->getRenderTarget()->DrawBitmap(_statusNumber->getBitmap(), rc);
}
