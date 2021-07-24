#include "stdafx.h"
#include "Team.h"

HRESULT Team::init(int pokemonNum)
{
	//�÷��̾� Ÿ��
	_playerType = PLAYER_TYPE_TEAM;
	_playerState = POKEMON_STATE_DEFAULT;

	//���ϸ�
	_pokemon = POKEDEX->makePokemon(pokemonNum);
	_pokemon->init();

	//��ǥ
	_x = 25;
	_y = 13;
	_destX = _x;
	_destY = _y;
	_body = RectMakeCenter(_x * TILEWIDTH + TILEWIDTH / 2, _y * TILEHEIGHT + TILEHEIGHT / 2,
		TILEWIDTH, TILEHEIGHT);

	//����
	//����ؼ� ���� ���ϸ� ��

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
