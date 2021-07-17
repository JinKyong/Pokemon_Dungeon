#include "stdafx.h"
#include "Player.h"

void Player::attack()
{
	if (_pokemon->getState() == POKEMON_STATE_DEFAULT) {
		_playerState = _pokemon->getState();
		return;
	}

	_pokemon->changeState(_playerState);

	//기술 썻을때만
	if (_playerState == POKEMON_STATE_SATTACK)
	{
		if (_selectedSkill) {
			float x = _x;
			float y = _y;
			int direct = _pokemon->getDirect();

			if ((direct & RIGHT) == RIGHT)
				x += TILEWIDTH;
			else if ((direct & LEFT) == LEFT)
				x -= TILEWIDTH;

			if ((direct & DOWN) == DOWN)
				y += TILEHEIGHT;
			else if ((direct & UP) == UP)
				y -= TILEHEIGHT;

			_selectedSkill->useSkill(x, y);
			_selectedSkill = nullptr;
		}
	}
}

void Player::move()
{
	_pokemon->changeDirect(_direct);
	_pokemon->changeState(_playerState);

	if (_x != _destX)	_x += cosf(_pokemon->getAngle()) * TILEWIDTH / 16;
	if (_y != _destY)	_y += -sinf(_pokemon->getAngle()) * TILEHEIGHT / 16;

	if (getDistance(_x, _y, _destX, _destY) <= TILEWIDTH / 16) {
		_x = _destX;
		_y = _destY;

		_pokemon->changeState(POKEMON_STATE_DEFAULT);
		_playerState = POKEMON_STATE_DEFAULT;
	}
}
