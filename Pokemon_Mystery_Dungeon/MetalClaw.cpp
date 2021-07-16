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

void MetalClaw::useSkill(float x, float y)
{
	Skill::useSkill(x, y);

	_metalClawEffect = new EF_MetalClaw;
	_metalClawEffect->init(x, y);
	EFFECTMANAGER->addEffect(_metalClawEffect);
}
