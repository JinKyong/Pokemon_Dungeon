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

	_inDungeon = false;

	return S_OK;
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
