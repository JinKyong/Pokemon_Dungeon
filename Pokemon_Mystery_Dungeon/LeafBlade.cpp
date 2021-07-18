#include "stdafx.h"
#include "LeafBlade.h"

HRESULT LeafBlade::init()
{
	_name = L"�������̵�";
	_skillNum = 6;
	_damage = 90;
	_accuracy = 1.f;
	_currentPP = _maxPP = 15;
	_atkType = PHYSICAL_ATTACK;
	_type = POKEMON_TYPE_GRASS;
	_scale = SS_FRONT;

	return S_OK;
}

void LeafBlade::release()
{
}

void LeafBlade::useSkill(float x, float y, int direct)
{
	Skill::useSkill(x, y, direct);

	_leafBladeEffect = new EF_LeafBlade;
	_leafBladeEffect->init(_x, _y);
	EFFECTMANAGER->addEffect(_leafBladeEffect);
}
