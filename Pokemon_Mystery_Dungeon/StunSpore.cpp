#include "stdafx.h"
#include "StunSpore.h"

HRESULT StunSpore::init()
{
	_name = L"저리가루";
	_skillNum = 13;
	_damage = 0;
	_accuracy = 0.75f;
	_currentPP = _maxPP = 30;
	_atkType = TRANSFORM_STATE;
	_type = POKEMON_TYPE_GRASS;
	_scale = SS_FRONT;

	return S_OK;
}

void StunSpore::release()
{
}

void StunSpore::useSkill(float x, float y, int direct)
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

	_stunSporeEffect = new EF_StunSpore;
	_stunSporeEffect->init(_x, _y);
	EFFECTMANAGER->addEffect(_stunSporeEffect);
}
