#include "stdafx.h"
#include "User.h"

HRESULT User::init(int pokemonNum)
{
	Player::init(pokemonNum);

	//플레이어 타입
	_playerType = PLAYER_TYPE_USER;
	_playerState = POKEMON_STATE_DEFAULT;
	//패턴 없음
	for (int i = 0; i < END_PLAYER_PATTERN; i++)
		_pattern[i] = nullptr;
	_currentPattern = END_PLAYER_PATTERN;


	//기술
	_selectedSkill = nullptr;
	_skill[0] = SKILLDEX->makeSkill(1);
	_skill[0]->init(this);
	_skill[1] = SKILLDEX->makeSkill(6);
	_skill[1]->init(this);
	_skill[2] = SKILLDEX->makeSkill(3);
	_skill[2]->init(this);
	_skill[3] = SKILLDEX->makeSkill(4);
	_skill[3]->init(this);

	//_inDungeon = false;

	_num = POKEDEX->getIndex();

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
		swprintf_s(str, L"x : %f", _x);
		DTDMANAGER->printText(str, dRectMake(_body.left, _body.top - 60, 100, 20));
		swprintf_s(str, L"y : %f", _y);
		DTDMANAGER->printText(str, dRectMake(_body.left, _body.top - 40, 100, 20));
		swprintf_s(str, L"name : %s", _pokemon->getName().c_str());
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

	//방향전환
	if (KEYMANAGER->isStayKeyDown(KEY_RIGHT)) {
		_direct |= RIGHT;
		_pokemon->changeDirect(_direct);
	}
	else if (KEYMANAGER->isStayKeyDown(KEY_LEFT)) {
		_direct |= LEFT;
		_pokemon->changeDirect(_direct);
	}
	if (KEYMANAGER->isStayKeyDown(KEY_UP)) {
		_direct |= UP;
		_pokemon->changeDirect(_direct);
	}
	else if (KEYMANAGER->isStayKeyDown(KEY_DOWN)) {
		_direct |= DOWN;
		_pokemon->changeDirect(_direct);
	}

	//방향 입력이 있을 시 (_direct != 0)
	if (!KEYMANAGER->isStayKeyDown(KEY_L1)) {
		if (_direct && COLLISIONMANAGER->collisionInputPlayer(this))
		{
			if ((_direct & RIGHT) == RIGHT) _destX++;
			else if ((_direct & LEFT) == LEFT) _destX--;

			if ((_direct & UP) == UP) _destY--;
			else if ((_direct & DOWN) == DOWN) _destY++;

			_playerState = POKEMON_STATE_MOVE;
		}
	}

	if (KEYMANAGER->isOnceKeyDown(KEY_A)) {
		//_pokemon->changeState(POKEMON_STATE_ATTACK);
		_playerState = POKEMON_STATE_ATTACK;
		_pokemon->setAttack(true);
	}
	if (KEYMANAGER->isOnceKeyDown('Q')) {
		//_pokemon->changeState(POKEMON_STATE_SATTACK);
		if (_selectedSkill = _skill[0]) {
			_playerState = POKEMON_STATE_SATTACK;
			_pokemon->setSattack(true);
		}
	}
	if (KEYMANAGER->isOnceKeyDown('W')) {
		//_pokemon->changeState(POKEMON_STATE_SATTACK);
		if (_selectedSkill = _skill[1]) {
			_playerState = POKEMON_STATE_SATTACK;
			_pokemon->setSattack(true);
		}
	}
	if (KEYMANAGER->isOnceKeyDown('E')) {
		//_pokemon->changeState(POKEMON_STATE_SATTACK);
		if (_selectedSkill = _skill[2]) {
			_playerState = POKEMON_STATE_SATTACK;
			_pokemon->setSattack(true);
		}
	}
	if (KEYMANAGER->isOnceKeyDown('R')) {
		//_pokemon->changeState(POKEMON_STATE_SATTACK);
		if (_selectedSkill = _skill[3]) {
			_playerState = POKEMON_STATE_SATTACK;
			_pokemon->setSattack(true);
		}
	}

	if (KEYMANAGER->isOnceKeyDown(KEY_Y)) {
		UIMANAGER->changeDownMenu("mainMenu");
		UIMANAGER->setOpen(true);
	}
	if (KEYMANAGER->isOnceKeyDown('S')) {
		_pokemon->changeState(POKEMON_STATE_SLEEP);
	}
	if (KEYMANAGER->isOnceKeyDown('A')) {
		_pokemon->changeState(POKEMON_STATE_HURT);
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
