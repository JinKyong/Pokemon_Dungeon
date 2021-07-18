#include "stdafx.h"
#include "IceFang.h"

HRESULT IceFang::init()
{
	_name = L"얼음엄니";
	_skillNum = 8;
	_damage = 65;
	_accuracy = 0.95f;
	_currentPP = _maxPP = 15;
	_atkType = PHYSICAL_ATTACK;
	_type = POKEMON_TYPE_ICE;
	_scale = SS_FRONT;

	return S_OK;
}

void IceFang::release()
{
}

void IceFang::useSkill(float x, float y, int direct)
{
	Skill::useSkill(x, y, direct);

	_iceFangEffect = new EF_IceFang;
	_iceFangEffect->init(_x, _y);
	EFFECTMANAGER->addEffect(_iceFangEffect);
}
