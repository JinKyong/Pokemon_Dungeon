#include "stdafx.h"
#include "Player.h"

void Player::move()
{
	_pokemon->changeDirect(_direct);
	_pokemon->changeState(_playerState);

	if (_x != _destX)	_x += cosf(_pokemon->getAngle()) / 16;
	if (_y != _destY)	_y += -sinf(_pokemon->getAngle()) / 16;

	if (getDistance(_x, _y, _destX, _destY) <= 1 / 8) {
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
