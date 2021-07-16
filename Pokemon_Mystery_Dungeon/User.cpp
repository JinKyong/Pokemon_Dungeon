#include "stdafx.h"
#include "User.h"

HRESULT User::init(int pokemonNum)
{
	//�÷��̾� Ÿ��
	_playerType = PLAYER_TYPE_USER;
	_playerState = POKEMON_STATE_DEFAULT;

	//���ϸ�
	_num = pokemonNum;
	_pokemon = POKEDEX->makePokemon(_num);
	_pokemon->init();

	//��ǥ
	_x = 25 * TILEWIDTH + TILEWIDTH / 2;
	_y = 25 * TILEHEIGHT + TILEHEIGHT / 2;
	_destX = _x;
	_destY = _y;
	_body = RectMakeCenter(_x, _y, TILEWIDTH, TILEHEIGHT);

	//����
	//����ؼ� ���� ���ϸ� ��

	_selectedSkill = nullptr;
	_skill[0] = SKILLDEX->makeSkill(1);
	_skill[1] = SKILLDEX->makeSkill(2);
	_skill[2] = SKILLDEX->makeSkill(3);
	_skill[3] = SKILLDEX->makeSkill(4);

	_inDungeon = false;

	return S_OK;
}

void User::release()
{
}

void User::update()
{
	_body = RectMakeCenter(_x, _y, TILEWIDTH, TILEHEIGHT);
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
		//�̵����Ϳ� �߰�
		//�̵����ʹ� ->move()
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

	if (KEYMANAGER->isOnceKeyDown('D')) {
		_pokemon->changeState(POKEMON_STATE_HURT);
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