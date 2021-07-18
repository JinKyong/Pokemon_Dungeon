#include "stdafx.h"
#include "DynamicPunch.h"

HRESULT DynamicPunch::init()
{
	_name = L"Æø¹ßÆÝÄ¡";
	_skillNum = 5;
	_damage = 100;
	_accuracy = 0.5f;
	_currentPP = _maxPP = 5;
	_atkType = PHYSICAL_ATTACK;
	_type = POKEMON_TYPE_FIGHTING;
	_scale = SS_FRONT;

	return S_OK;
}

void DynamicPunch::release()
{
}

void DynamicPunch::useSkill(float x, float y, int direct)
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

	_dynamicPunchEffect = new EF_DynamicPunch;
	_dynamicPunchEffect->init(_x, _y);
	EFFECTMANAGER->addEffect(_dynamicPunchEffect);
}
