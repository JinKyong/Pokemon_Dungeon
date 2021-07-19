#include "stdafx.h"
#include "Team.h"

HRESULT Team::init(int pokemonNum)
{
	//플레이어 타입
	_playerType = PLAYER_TYPE_TEAM;
	_playerState = POKEMON_STATE_DEFAULT;

	//포켓몬
	_pokemon = POKEDEX->makePokemon(pokemonNum);
	_pokemon->init();

	//좌표
	_x = 25;
	_y = 13;
	_destX = _x;
	_destY = _y;
	_body = RectMakeCenter(_x * TILEWIDTH + TILEWIDTH / 2, _y * TILEHEIGHT + TILEHEIGHT / 2,
		TILEWIDTH, TILEHEIGHT);

	//스탯
	//계산해서 넣음 포켓몬 꺼
	_testHP = 200;

	_inDungeon = false;

	return S_OK;
}

void Team::release()
{
}

void Team::update()
{
	_body = RectMakeCenter(_x * TILEWIDTH + TILEWIDTH / 2, _y * TILEHEIGHT + TILEHEIGHT / 2,
		TILEWIDTH, TILEHEIGHT);
}

void Team::render()
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

int Team::input()
{
	_direct = RND->getFromIntTo(RIGHT, DOWN + 1);
	_destX = _x;
	_destY = _y;

	_playerState = POKEMON_STATE_MOVE;
	if (_direct == RIGHT)
		_destX++;
	else if (_direct == LEFT)
		_destX--;
	else if (_direct == UP)
		_destY--;
	else if (_direct == DOWN)
		_destY++;
	else
		_playerState = POKEMON_STATE_ATTACK;


	return _playerState;
}
