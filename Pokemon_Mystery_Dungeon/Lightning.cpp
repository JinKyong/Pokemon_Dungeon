#include "stdafx.h"
#include "Lightning.h"

HRESULT Lightning::init()
{
	_name = L"전기충격";
	_skillNum = 3;
	_damage = 40;
	_accuracy = 1.f;
	_currentPP = _maxPP = 30;
	_atkType = SPECIAL_ATTACK;
	_type = POKEMON_TYPE_ELECTRIC;
	_scale = SS_FRONT;

	return S_OK;
}

void Lightning::release()
{
}

void Lightning::useSkill(float x, float y)
{
	Skill::useSkill(x, y);

	_lightningEffect = new EF_Lightning;
	_lightningEffect->init(x, y);
	EFFECTMANAGER->addEffect(_lightningEffect);
}
