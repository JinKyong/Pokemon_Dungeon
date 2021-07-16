#include "stdafx.h"
#include "Player.h"

void Player::attack()
{
	_pokemon->changeState(_playerState);

	//��� ��������
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

	if (_x != _destX)	_x += cosf(_pokemon->getAngle()) * 2;
	if (_y != _destY)	_y += -sinf(_pokemon->getAngle()) * 2;

	if (getDistance(_x, _y, _destX, _destY) <= TILEWIDTH / 16) {
		_x = _destX;
		_y = _destY;

		_playerState = POKEMON_STATE_DEFAULT;
	}
}
