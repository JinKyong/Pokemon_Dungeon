#include "stdafx.h"
#include "Player.h"

HRESULT Player::init()
{
	_pokemon = POKEDEX->makePokemon(1);
	_pokemon->init();

	_x = WINSIZEX / 2;
	_y = WINSIZEY / 2;
	_body = RectMakeCenter(_x, _y, PSIZEX, PSIZEY);

	//스탯
	//계산해서 넣음 포켓몬 꺼

	_inDungeon = false;

	_sm = new SkillManager;	// 스킬매니저 등록
	_sm->init();

	_effectX = _effectY = _skillNum = 0;

	return S_OK;
}

void Player::release()
{
}

void Player::update()
{
	controlKey();
	testKey();

	_body = RectMakeCenter(_x, _y, PSIZEX, PSIZEY);

	_pokemon->update();
	EFFECTMANAGER->update();
}

void Player::render()
{
	if (PRINTMANAGER->isDebug()) {
		WCHAR str[128];
		swprintf_s(str, L"direct : %d", _pokemon->getDirect());
		DTDMANAGER->printText(str, dRectMake(_body.left, _body.top - 60, 100, 20));
		swprintf_s(str, L"name : %s", _pokemon->getName().c_str());
		DTDMANAGER->printText(str, dRectMake(_body.left, _body.top - 40, 100, 20));
		swprintf_s(str, L"state : %d", _pokemon->getState());
		DTDMANAGER->printText(str, dRectMake(_body.left, _body.top - 20, 100, 20));

		DTDMANAGER->Rectangle(_body);
	}

	_pokemon->render(_x, _y);
	EFFECTMANAGER->render();
}

void Player::controlKey()
{
	int direct = 0;

	if (KEYMANAGER->isStayKeyDown(VK_RIGHT)) {
		_x += 5;
		direct |= RIGHT;

		_pokemon->changeDirect(direct);
		_pokemon->changeState(P_MOVE);
	}
	else if (KEYMANAGER->isStayKeyDown(VK_LEFT)) {
		_x -= 5;
		direct |= LEFT;

		_pokemon->changeDirect(direct);
		_pokemon->changeState(P_MOVE);
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP)) {
		_y -= 5;
		direct |= UP;

		_pokemon->changeDirect(direct);
		_pokemon->changeState(P_MOVE);
	}
	else if (KEYMANAGER->isStayKeyDown(VK_DOWN)) {
		_y += 5;
		direct |= DOWN;

		_pokemon->changeDirect(direct);
		_pokemon->changeState(P_MOVE);
	}

	if (KEYMANAGER->isOnceKeyUp(VK_RIGHT)) { _pokemon->changeState(P_IDLE); }
	if (KEYMANAGER->isOnceKeyUp(VK_LEFT)) { _pokemon->changeState(P_IDLE); }
	if (KEYMANAGER->isOnceKeyUp(VK_DOWN)) { _pokemon->changeState(P_IDLE); }
	if (KEYMANAGER->isOnceKeyUp(VK_UP)) { _pokemon->changeState(P_IDLE); }

	if (KEYMANAGER->isOnceKeyDown('X')) { _pokemon->changeState(P_ATTACK); }
	if (KEYMANAGER->isOnceKeyDown('C')) { _pokemon->changeState(P_SATTACK); }

	if (KEYMANAGER->isOnceKeyDown('D')) { _pokemon->changeState(P_HURT); }
	if (KEYMANAGER->isOnceKeyDown('S')) { _pokemon->changeState(P_SLEEP); }

	// ==================스킬테스트================== //
	switch (direct)
	{
	case RIGHT:
		_effectX = 48; _effectY = 0;
		break;
	case LEFT:
		_effectX = -48; _effectY = 0;
		break;
	case UP:
		_effectX = 0; _effectY = -48;
		break;
	case DOWN:
		_effectX = 0; _effectY = 48;
		break;
	}
	if (KEYMANAGER->isOnceKeyDown('Q'))
	{
		_sm->addSkill(_x + _effectX, _y + _effectY, _skillNum);
	}
	if (KEYMANAGER->isOnceKeyDown('W'))
	{
		_skillNum++;
		if (_skillNum > 6) _skillNum = 0;
	}
}

void Player::testKey()
{
	if (KEYMANAGER->isOnceKeyDown('1')) {
		SAFE_DELETE(_pokemon);
		_pokemon = POKEDEX->makePokemon(1);
		_pokemon->init();
	}
	if (KEYMANAGER->isOnceKeyDown('2')) {
		SAFE_DELETE(_pokemon);
		_pokemon = POKEDEX->makePokemon(2);
		_pokemon->init();
	}
	if (KEYMANAGER->isOnceKeyDown('3')) {
		SAFE_DELETE(_pokemon);
		_pokemon = POKEDEX->makePokemon(3);
		_pokemon->init();
	}
	if (KEYMANAGER->isOnceKeyDown('4')) {
		SAFE_DELETE(_pokemon);
		_pokemon = POKEDEX->makePokemon(4);
		_pokemon->init();
	}
	if (KEYMANAGER->isOnceKeyDown('5')) {
		SAFE_DELETE(_pokemon);
		_pokemon = POKEDEX->makePokemon(5);
		_pokemon->init();
	}
	if (KEYMANAGER->isOnceKeyDown('6')) {
		SAFE_DELETE(_pokemon);
		_pokemon = POKEDEX->makePokemon(6);
		_pokemon->init();
	}
}
