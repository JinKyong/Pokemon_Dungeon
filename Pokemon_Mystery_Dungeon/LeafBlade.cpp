#include "stdafx.h"
#include "LeafBlade.h"

HRESULT LeafBlade::init()
{
	_name = L"리프블레이드";
	_skillNum = 6;
	_damage = 90;
	_accuracy = 1.f;
	_currentPP = _maxPP = 15;
	_atkType = PHYSICAL_ATTACK;
	_type = POKEMON_TYPE_GRASS;
	_scale = SS_FRONT;

	return S_OK;
}

void LeafBlade::release()
{
}

void LeafBlade::useSkill(float x, float y, int direct)
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

	_leafBladeEffect = new EF_LeafBlade;
	_leafBladeEffect->init(_x, _y);
	EFFECTMANAGER->addEffect(_leafBladeEffect);
}
