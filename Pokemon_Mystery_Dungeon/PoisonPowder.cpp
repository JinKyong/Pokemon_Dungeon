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

	_poisonPowderEffect = new EF_PoisonPowder;
	_poisonPowderEffect->init(_x, _y);
	EFFECTMANAGER->addEffect(_poisonPowderEffect);
}
