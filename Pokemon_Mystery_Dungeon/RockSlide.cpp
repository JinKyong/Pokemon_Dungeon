#include "stdafx.h"
#include "RockSlide.h"

HRESULT RockSlide::init()
{
	_name = L"½ºÅæ»þ¿ö";
	_skillNum = 4;
	_damage = 75;
	_accuracy = 0.9f;
	_currentPP = _maxPP = 10;
	_atkType = PHYSICAL_ATTACK;
	_type = POKEMON_TYPE_ROCK;
	_scale = SS_FRONT;

	return S_OK;
}

void RockSlide::release()
{
}

void RockSlide::useSkill(float x, float y, int direct)
{
	Skill::useSkill(x, y, direct);

	switch (direct)
	{
	case 1:					//RIGHT
		_x = x + TILEWIDTH;
		_y = y;
		break;

	case 2:					//LEFT
		_x = x - TILEWIDTH;
		_y = y;
		break;

	case 4:					//UP
		_x = x;
		_y = y - TILEHEIGHT;
		break;

	case 8:					//DOWN
		_x = x;
		_y = y + TILEHEIGHT;
		break;

	case 5:					//UP_RIGHT
		_x = x + TILEWIDTH;
		_y = y - TILEHEIGHT;
		break;

	case 6:					//UP_LEFT
		_x = x - TILEWIDTH;
		_y = y - TILEHEIGHT;
		break;

	case 9:					//DOWN_RIGHT
		_x = x + TILEWIDTH;
		_y = y + TILEHEIGHT;
		break;

	case 10:					//DOWN_LEFT
		_x = x - TILEWIDTH;
		_y = y + TILEHEIGHT;
		break;
	}

	_rockSlideEffect = new EF_RockSlide;
	_rockSlideEffect->init(_x, _y);
	EFFECTMANAGER->addEffect(_rockSlideEffect);
}
