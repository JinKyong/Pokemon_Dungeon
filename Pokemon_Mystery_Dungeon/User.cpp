#include "stdafx.h"
#include "User.h"

HRESULT User::init(int pokemonNum)
{
	//플레이어 타입
	_playerType = PLAYER_TYPE_USER;
	_playerState = POKEMON_STATE_DEFAULT;

	//포켓몬
	_num = pokemonNum;
	_pokemon = POKEDEX->makePokemon(_num);
	_pokemon->init();

	//좌표
	_x = 25;
	_y = 17;
	_destX = _x;
	_destY = _y;
	_body = RectMakeCenter(_x * TILEWIDTH + TILEWIDTH / 2, _y * TILEHEIGHT + TILEHEIGHT / 2,
		TILEWIDTH, TILEHEIGHT);

	//스탯
	//계산해서 넣음 포켓몬 꺼
	_testHP = 200;

	_selectedSkill = nullptr;
	_skill[0] = SKILLDEX->makeSkill(1);
	_skill[0]->init();
	_skill[1] = SKILLDEX->makeSkill(6);
	_skill[1]->init();
	_skill[2] = SKILLDEX->makeSkill(3);
	_skill[2]->init();
	_skill[3] = SKILLDEX->makeSkill(4);
	_skill[3]->init();

	_inDungeon = false;

	return S_OK;
}

void User::release()
{
}

void User::update()
{
	_body = RectMakeCenter(_x * TILEWIDTH + TILEWIDTH / 2, _y * TILEHEIGHT + TILEHEIGHT / 2,
		TILEWIDTH, TILEHEIGHT);
}

void User::render()
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
}

int User::input()
{
	controlKey();
	testKey();

	return _playerState;
}

void User::controlKey()
{
	_direct = 0;
	_destX = _x;
	_destY = _y;

	if (KEYMANAGER->isStayKeyDown(KEY_RIGHT)) {
		_direct |= RIGHT;
		if (COLLISIONMANAGER->collisionInputPlayer(this))			//2. 저 불값을 어떻게 키 전부 적용해서 사용할지..?
		{
			_destX++;

			if (KEYMANAGER->isStayKeyDown(KEY_L1))
				_pokemon->changeDirect(_direct);
			else
				_playerState = POKEMON_STATE_MOVE;
		}
	}
	else if (KEYMANAGER->isStayKeyDown(KEY_LEFT)) {
		_direct |= LEFT;
		_destX--;

		if (KEYMANAGER->isStayKeyDown(KEY_L1))
			_pokemon->changeDirect(_direct);
		else
			_playerState = POKEMON_STATE_MOVE;
	}
	if (KEYMANAGER->isStayKeyDown(KEY_UP)) {
		_direct |= UP;
		_destY--;

		if (KEYMANAGER->isStayKeyDown(KEY_L1))
			_pokemon->changeDirect(_direct);
		else
			_playerState = POKEMON_STATE_MOVE;
	}
	else if (KEYMANAGER->isStayKeyDown(KEY_DOWN)) {
		_direct |= DOWN;
		_destY++;

		if (KEYMANAGER->isStayKeyDown(KEY_L1))
			_pokemon->changeDirect(_direct);
		else
			_playerState = POKEMON_STATE_MOVE;
	}

	if (KEYMANAGER->isOnceKeyDown('X')) {
		//_pokemon->changeState(POKEMON_STATE_ATTACK);
		_playerState = POKEMON_STATE_ATTACK;
	}
	if (KEYMANAGER->isOnceKeyDown('Q')) {
		//_pokemon->changeState(POKEMON_STATE_SATTACK);
		if (_selectedSkill = _skill[0])
			_playerState = POKEMON_STATE_SATTACK;
	}
	if (KEYMANAGER->isOnceKeyDown('W')) {
		//_pokemon->changeState(POKEMON_STATE_SATTACK);
		if (_selectedSkill = _skill[1])
			_playerState = POKEMON_STATE_SATTACK;
	}
	if (KEYMANAGER->isOnceKeyDown('E')) {
		//_pokemon->changeState(POKEMON_STATE_SATTACK);
		if (_selectedSkill = _skill[2])
			_playerState = POKEMON_STATE_SATTACK;
	}
	if (KEYMANAGER->isOnceKeyDown('R')) {
		//_pokemon->changeState(POKEMON_STATE_SATTACK);
		if (_selectedSkill = _skill[3])
			_playerState = POKEMON_STATE_SATTACK;
	}

	if (KEYMANAGER->isOnceKeyDown(KEY_Y)) {
		UIMANAGER->changeDownMenu("mainMenu");
		UIMANAGER->setOpen(true);
	}
	if (KEYMANAGER->isOnceKeyDown('S')) {
		_pokemon->changeState(POKEMON_STATE_SLEEP);
	}
}

void User::testKey()
{
	if (KEYMANAGER->isOnceKeyDown('1')) {
		if (_num >= POKEDEX->getIndex()) return;

		SAFE_DELETE(_pokemon);
		_num++;
		_pokemon = POKEDEX->makePokemon(_num);
		_pokemon->init();
	}
	if (KEYMANAGER->isOnceKeyDown('2')) {
		if (_num <= 1)	return;

		SAFE_DELETE(_pokemon);
		_num--;
		_pokemon = POKEDEX->makePokemon(_num);
		_pokemon->init();
	}
}
