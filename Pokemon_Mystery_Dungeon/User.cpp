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
	_default = SKILLDEX->makeSkill(0);
	_default->init(this);
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

	if (KEYMANAGER->isOnceKeyDown(KEY_A))
		useSkill(-1);

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
