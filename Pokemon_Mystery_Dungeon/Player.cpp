#include "stdafx.h"
#include "Player.h"

HRESULT Player::init()
{
	//포켓몬
	_pokemon = POKEDEX->makePokemon(1);
	_pokemon->init();

	//턴
	_turn = true;

	//좌표
	_x = 25 * TILEWIDTH + TILEWIDTH / 2;
	_y = 25 * TILEHEIGHT + TILEHEIGHT / 2;
	_destX = _x;
	_destY = _y;
	_body = RectMakeCenter(_x, _y, TILEWIDTH, TILEHEIGHT);

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
	if (_turn) {
		controlKey();
		testKey();
	}

	if (_x != _destX) {
		_x += cosf(_pokemon->getAngle()) * 2;
	}
	if (_y != _destY) {
		_y += -sinf(_pokemon->getAngle()) * 2;
		if (_y == _destY) {
			_turn = true;
		}
	}
	if (getDistance(_x, _y, _destX, _destY) <= TILEWIDTH / 16) {
		_x = _destX;
		_y = _destY;
		_turn = true;
	}

	_body = RectMakeCenter(_x, _y, TILEWIDTH, TILEHEIGHT);
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
		direct |= RIGHT;
		_destX = _x + TILEWIDTH;

		_pokemon->changeDirect(direct);
		_pokemon->changeState(POKEMON_STATE_MOVE);
		_turn = false;
	}
	else if (KEYMANAGER->isStayKeyDown(VK_LEFT)) {
		direct |= LEFT;
		_destX = _x - TILEWIDTH;

		_pokemon->changeDirect(direct);
		_pokemon->changeState(POKEMON_STATE_MOVE);
		_turn = false;
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP)) {
		direct |= UP;
		_destY = _y - TILEHEIGHT;

		_pokemon->changeDirect(direct);
		_pokemon->changeState(POKEMON_STATE_MOVE);
		_turn = false;
	}
	else if (KEYMANAGER->isStayKeyDown(VK_DOWN)) {
		direct |= DOWN;
		_destY = _y + TILEHEIGHT;

		_pokemon->changeDirect(direct);
		_pokemon->changeState(POKEMON_STATE_MOVE);
		_turn = false;
	}

	if (KEYMANAGER->isOnceKeyDown('X')) {
		_pokemon->changeState(POKEMON_STATE_ATTACK);
		_turn = false;
	}
	if (KEYMANAGER->isOnceKeyDown('C')) {
		_pokemon->changeState(POKEMON_STATE_SATTACK);
		_turn = false;
	}

	if (KEYMANAGER->isOnceKeyDown('D')) {
		_pokemon->changeState(POKEMON_STATE_HURT);
		_turn = false;
	}
	if (KEYMANAGER->isOnceKeyDown('S')) {
		_pokemon->changeState(POKEMON_STATE_SLEEP);
		_turn = false;
	}

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