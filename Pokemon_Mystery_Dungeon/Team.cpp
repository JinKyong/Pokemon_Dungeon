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
	_x = 25 * TILEWIDTH + TILEWIDTH / 2;
	_y = 13 * TILEHEIGHT + TILEHEIGHT / 2;
	_destX = _x;
	_destY = _y;
	_body = RectMakeCenter(_x, _y, TILEWIDTH, TILEHEIGHT);

	//����
	//����ؼ� ���� ���ϸ� ��

	_inDungeon = false;

	return S_OK;
}

void Team::release()
{
}

void Team::update()
{
	_body = RectMakeCenter(_x, _y, TILEWIDTH, TILEHEIGHT);
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