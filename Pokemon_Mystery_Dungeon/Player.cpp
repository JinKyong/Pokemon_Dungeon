#include "stdafx.h"
#include "Player.h"

void Player::attack()
{
	_pokemon->changeState(_playerState);
	if (_playerState == POKEMON_STATE_SATTACK)
	{
		if (_selectedSkill) {
			_selectedSkill->useSkill(_x, _y);
			_selectedSkill = nullptr;
		}
	}
}

void Player::move()
{
	_pokemon->changeDirect(_direct);
	_pokemon->changeState(_playerState);

	if (_x != _destX)	_x += cosf(_pokemon->getAngle()) * 2;
	if (_y != _destY)	_y += -sinf(_pokemon->getAngle()) * 2;

	if (getDistance(_x, _y, _destX, _destY) <= TILEWIDTH / 16) {
		_x = _destX;
		_y = _destY;

		_playerState = POKEMON_STATE_DEFAULT;
	}
}
