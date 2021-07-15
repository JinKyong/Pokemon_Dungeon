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

void DynamicPunch::useSkill(float x, float y)
{
	_dynamicPunchEffect = new EF_DynamicPunch;
	_dynamicPunchEffect->init(x, y);
	EFFECTMANAGER->addEffect(_dynamicPunchEffect);
}
