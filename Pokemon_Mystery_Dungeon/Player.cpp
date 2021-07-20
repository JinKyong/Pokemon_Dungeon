#include "stdafx.h"
#include "Player.h"

HRESULT Player::init(int pokemonNum)
{
	//포켓몬
	_pokemon = POKEDEX->makePokemon(pokemonNum);
	_pokemon->init();

	return S_OK;
}

HRESULT Player::init(float x, float y)
{
	//좌표
	_x = x;
	_y = y;
	_destX = _x;
	_destY = _y;
	_body = RectMakeCenter(_x * TILEWIDTH + TILEWIDTH / 2, _y * TILEHEIGHT + TILEHEIGHT / 2,
		TILEWIDTH, TILEHEIGHT);

	return S_OK;
}

void Player::move()
{
	_pokemon->changeDirect(_direct);
	_pokemon->changeState(_playerState);

	if (_x != _destX)	_x += cosf(_pokemon->getAngle()) / 16;
	if (_y != _destY)	_y += -sinf(_pokemon->getAngle()) / 16;

	float limit = 1.4142;
	if (_direct == RIGHT || _direct == LEFT || _direct == UP || _direct == DOWN) limit = 1.0;

	//이동 시작지점과 현재 위치 거리가 타일 1칸이상이 되면 (== 이동거리가 타일 1칸이상되면) 이동 끝
	//이전에는 이동 목적지와 현재 위치 거리가 일정 거리만큼 가까워지면 이동 끝
	if (getDistance(_initX, _initY, _x, _y) >= limit) {
		_x = _destX;
		_y = _destY;

		//_pokemon->changeState(POKEMON_STATE_DEFAULT);
		_playerState = POKEMON_STATE_DEFAULT;
	}
}

void Player::attack()
{
	if (_pokemon->getState() == POKEMON_STATE_DEFAULT) {
		_playerState = _pokemon->getState();
		return;
	}

	_pokemon->changeState(_playerState);
}

void Player::sattack()
{
	_pokemon->changeState(_playerState);

	if (_selectedSkill) {
		_selectedSkill->useSkill(_x, _y, _pokemon->getDirect());
		DIALOGMANAGER->useSkillLog(this, _selectedSkill);
		_selectedSkill = nullptr;
	}
}

void Player::hitDamage(int num)
{
	_testHP -= num;
}
