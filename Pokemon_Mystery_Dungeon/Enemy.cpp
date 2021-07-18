#include "stdafx.h"
#include "Enemy.h"

HRESULT Enemy::init(int pokemonNum)
{
	//플레이어 타입
	_playerType = PLAYER_TYPE_ENEMY;
	_playerState = POKEMON_STATE_DEFAULT;

	//포켓몬
	_pokemon = POKEDEX->makePokemon(pokemonNum);
	_pokemon->init();

	//좌표
	_x = 25 * TILEWIDTH + TILEWIDTH / 2;
	_y = 15 * TILEHEIGHT + TILEHEIGHT / 2;
	_destX = _x;
	_destY = _y;
	_body = RectMakeCenter(_x, _y, TILEWIDTH, TILEHEIGHT);

	//스탯
	//계산해서 넣음 포켓몬 꺼
	_testHP = 200;

	_inDungeon = false;

	return S_OK;
}

void Enemy::release()
{
}

void Enemy::update()
{
	_body = RectMakeCenter(_x, _y, TILEWIDTH, TILEHEIGHT);
}

void Enemy::render()
{
	if (PRINTMANAGER->isDebug()) {
		WCHAR str[128];
		swprintf_s(str, L"HP : %d", _testHP);
		DTDMANAGER->printText(str, dRectMake(_body.left, _body.top - 80, 100, 20));
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

int Enemy::input()
{
	_direct = RND->getFromIntTo(RIGHT, LEFT + 2);

	_playerState = POKEMON_STATE_MOVE;
	if (_direct == RIGHT)
		_destX = _x + TILEWIDTH;
	else if (_direct == LEFT)
		_destX = _x - TILEWIDTH;
	else
		_playerState = POKEMON_STATE_ATTACK;


	return _playerState;
}
