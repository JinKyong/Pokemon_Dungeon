#include "stdafx.h"
#include "User.h"

HRESULT User::init(int pokemonNum)
{
	//플레이어 타입
	_playerType = PLAYER_TYPE_USER;
	_playerState = POKEMON_STATE_DEFAULT;

	//포켓몬
	_pokemon = POKEDEX->makePokemon(pokemonNum);
	_pokemon->init();

	//좌표
	_x = 25 * TILEWIDTH + TILEWIDTH / 2;
	_y = 25 * TILEHEIGHT + TILEHEIGHT / 2;
	_destX = _x;
	_destY = _y;
	_body = RectMakeCenter(_x, _y, TILEWIDTH, TILEHEIGHT);

	//스탯
	//계산해서 넣음 포켓몬 꺼

	_skill[0] = SKILLDEX->makeSkill(1);

	_inDungeon = false;

	return S_OK;
}

void User::release()
{
}

void User::update()
{
	_body = RectMakeCenter(_x, _y, TILEWIDTH, TILEHEIGHT);
	_pokemon->update();
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

	if (KEYMANAGER->isStayKeyDown(VK_RIGHT)) {
		_direct |= RIGHT;
		_destX = _x + TILEWIDTH;
		//이동벡터에 추가
		//이동벡터는 ->move()
		_playerState = POKEMON_STATE_MOVE;
	}
	else if (KEYMANAGER->isStayKeyDown(VK_LEFT)) {
		_direct |= LEFT;
		_destX = _x - TILEWIDTH;
		_playerState = POKEMON_STATE_MOVE;
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP)) {
		_direct |= UP;
		_destY = _y - TILEHEIGHT;
		_playerState = POKEMON_STATE_MOVE;
	}
	else if (KEYMANAGER->isStayKeyDown(VK_DOWN)) {
		_direct |= DOWN;
		_destY = _y + TILEHEIGHT;
		_playerState = POKEMON_STATE_MOVE;
	}

	if (KEYMANAGER->isOnceKeyDown('X')) {
		//_pokemon->changeState(POKEMON_STATE_ATTACK);
		//공격벡터에 추가 ->attack()
		_playerState = POKEMON_STATE_ATTACK;
	}
	if (KEYMANAGER->isOnceKeyDown('C')) {
		//_pokemon->changeState(POKEMON_STATE_SATTACK);
		//스페셜공격벡터?
		_playerState = POKEMON_STATE_SATTACK;
	}

	if (KEYMANAGER->isOnceKeyDown('D')) {
		//_pokemon->changeState(POKEMON_STATE_HURT);
	}
	if (KEYMANAGER->isOnceKeyDown('S')) {
		//_pokemon->changeState(POKEMON_STATE_SLEEP);
	}
}

void User::testKey()
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
