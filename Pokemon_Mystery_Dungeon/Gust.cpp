#include "stdafx.h"
#include "Gust.h"
#include "EF_Gust.h"

HRESULT Gust::init()
{
	_name = L"바람일으키기";
	_skillNum = 2;
	_damage = 40;
	_accuracy = 1.f;
	_currentPP = _maxPP = 35;
	_atkType = SPECIAL_ATTACK;
	_type = POKEMON_TYPE_FLYING;
	_scale = SS_FRONT;

	return S_OK;
}

void Gust::release()
{
}

void Gust::useSkill(float x, float y, int direct)
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

	_gustEffect = new EF_Gust;
	_gustEffect->init(_x, _y);
	EFFECTMANAGER->addEffect(_gustEffect);
}
