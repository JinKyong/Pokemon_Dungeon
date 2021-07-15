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

void Gust::useSkill(float x, float y)
{
	_gustEffect = new EF_Gust;
	_gustEffect->init(x, y);
	EFFECTMANAGER->addEffect(_gustEffect);
}
