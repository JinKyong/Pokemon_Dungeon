#include "stdafx.h"
#include "FireFang.h"

HRESULT FireFang::init()
{
	_name = L"�Ҳɾ���";
	_skillNum = 8;
	_damage = 65;
	_accuracy = 0.95f;
	_currentPP = _maxPP = 15;
	_atkType = PHYSICAL_ATTACK;
	_type = POKEMON_TYPE_FIRE;
	_scale = SS_FRONT;

	return S_OK;
}

void FireFang::release()
{
}

void FireFang::useSkill(float x, float y)
{
	Skill::useSkill(x, y);

	_fireFangEffect = new EF_FireFang;
	_fireFangEffect->init(x, y);
	EFFECTMANAGER->addEffect(_fireFangEffect);
}
