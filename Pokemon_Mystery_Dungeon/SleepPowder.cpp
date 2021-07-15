#include "stdafx.h"
#include "SleepPowder.h"

HRESULT SleepPowder::init()
{
	_name = L"수면가루";
	_skillNum = 12;
	_damage = 0;
	_accuracy = 0.75f;
	_currentPP = _maxPP = 15;
	_atkType = TRANSFORM_STATE;
	_type = POKEMON_TYPE_GRASS;
	_scale = SS_FRONT;

	return S_OK;
}

void SleepPowder::release()
{
}

void SleepPowder::useSkill(float x, float y)
{
}
