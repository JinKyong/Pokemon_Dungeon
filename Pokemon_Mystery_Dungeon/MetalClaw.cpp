#include "stdafx.h"
#include "MetalClaw.h"

HRESULT MetalClaw::init()
{
	_name = L"¸ÞÅ»Å©·Î¿ì";
	_skillNum = 14;
	_damage = 50;
	_accuracy = 0.95f;
	_currentPP = _maxPP = 35;
	_atkType = PHYSICAL_ATTACK;
	_type = POKEMON_TYPE_STEEL;
	_scale = SS_FRONT;

	return S_OK;
}

void MetalClaw::release()
{
}

void MetalClaw::useSkill(float x, float y, int direct)
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

	_metalClawEffect = new EF_MetalClaw;
	_metalClawEffect->init(_x, _y);
	EFFECTMANAGER->addEffect(_metalClawEffect);
}
