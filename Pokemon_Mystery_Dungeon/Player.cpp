#include "stdafx.h"
#include "Player.h"
#include "Charmander.h"

HRESULT Player::init()
{
	_pokemon = new Charmander;
	_pokemon->init();

	return S_OK;
}

void Player::release()
{
}

void Player::update()
{
	int direct = 0;

	if (KEYMANAGER->isStayKeyDown(VK_RIGHT)) {
		_pokemon->setX(_pokemon->getX() + 5);
		direct |= RIGHT;

		_pokemon->changeDirect(direct);
		_pokemon->changeState(P_MOVE);
	}
	else if (KEYMANAGER->isStayKeyDown(VK_LEFT)) {
		_pokemon->setX(_pokemon->getX() - 5);
		direct |= LEFT;

		_pokemon->changeDirect(direct);
		_pokemon->changeState(P_MOVE);
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN)) {
		_pokemon->setY(_pokemon->getY() + 5);
		direct |= DOWN;

		_pokemon->changeDirect(direct);
		_pokemon->changeState(P_MOVE);
	}
	else if (KEYMANAGER->isStayKeyDown(VK_UP)) {
		_pokemon->setY(_pokemon->getY() - 5);
		direct |= UP;

		_pokemon->changeDirect(direct);
		_pokemon->changeState(P_MOVE);
	}

	if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))	{ _pokemon->changeState(P_IDLE); }
	if (KEYMANAGER->isOnceKeyUp(VK_LEFT))	{ _pokemon->changeState(P_IDLE); }
	if (KEYMANAGER->isOnceKeyUp(VK_DOWN))	{ _pokemon->changeState(P_IDLE); }
	if (KEYMANAGER->isOnceKeyUp(VK_UP))		{ _pokemon->changeState(P_IDLE); }

	if (KEYMANAGER->isOnceKeyDown('X')) { _pokemon->changeState(P_ATTACK); }

	_pokemon->update();
}

void Player::render()
{
	_pokemon->render();

	if (PRINTMANAGER->isDebug()) {
		WCHAR str[128];
		swprintf_s(str, L"direct : %d", _pokemon->getDirect());
		RECT tmp = _pokemon->getBody();
		DTDMANAGER->printText(str, dRectMake(tmp.left, tmp.top - 20, 100, 20));
	}
}
