#include "stdafx.h"
#include "Skill.h"

void Skill::useSkill(float x, float y, int direct)
{
	if (_currentPP <= 0) return;

	_currentPP--;

	_x = x;
	_y = y;

	if ((direct & RIGHT) == RIGHT)
		_x++;
	else if ((direct & LEFT) == LEFT)
		_x--;

	if ((direct & DOWN) == DOWN)
		_y++;
	else if ((direct & UP) == UP)
		_y--;
}
