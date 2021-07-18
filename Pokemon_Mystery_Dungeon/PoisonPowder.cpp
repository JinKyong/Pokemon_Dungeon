#include "stdafx.h"
#include "PoisonPowder.h"

HRESULT PoisonPowder::init()
{
	_name = L"µ¶°¡·ç";
	_skillNum = 11;
	_damage = 0;
	_accuracy = 0.75f;
	_currentPP = _maxPP = 35;
	_atkType = TRANSFORM_STATE;
	_type = POKEMON_TYPE_POISON;
	_scale = SS_FRONT;

	return S_OK;
}

void PoisonPowder::release()
{
}

void PoisonPowder::useSkill(float x, float y, int direct)
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

	_poisonPowderEffect = new EF_PoisonPowder;
	_poisonPowderEffect->init(_x, _y);
	EFFECTMANAGER->addEffect(_poisonPowderEffect);
}
