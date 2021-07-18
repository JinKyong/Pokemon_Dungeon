#include "stdafx.h"
#include "StunSpore.h"

HRESULT StunSpore::init()
{
	_name = L"저리가루";
	_skillNum = 13;
	_damage = 0;
	_accuracy = 0.75f;
	_currentPP = _maxPP = 30;
	_atkType = TRANSFORM_STATE;
	_type = POKEMON_TYPE_GRASS;
	_scale = SS_FRONT;

	return S_OK;
}

void StunSpore::release()
{
}

void StunSpore::useSkill(float x, float y, int direct)
{
	Skill::useSkill(x, y, direct);

	_stunSporeEffect = new EF_StunSpore;
	_stunSporeEffect->init(_x, _y);
	EFFECTMANAGER->addEffect(_stunSporeEffect);
}
