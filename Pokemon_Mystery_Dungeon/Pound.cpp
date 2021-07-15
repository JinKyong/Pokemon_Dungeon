#include "stdafx.h"
#include "Pound.h"

HRESULT Pound::init()
{
	_name = L"¸·Ä¡±â";
	_skillNum = 10;
	_damage = 40;
	_accuracy = 1.f;
	_currentPP = _maxPP = 35;
	_atkType = PHYSICAL_ATTACK;
	_type = POKEMON_TYPE_NORMAL;
	_scale = SS_FRONT;

	return S_OK;
}

void Pound::release()
{
}

void Pound::useSkill(float x, float y)
{
	_poundEffect = new EF_Pound;
	_poundEffect->init(x, y);
	EFFECTMANAGER->addEffect(_poundEffect);
}
