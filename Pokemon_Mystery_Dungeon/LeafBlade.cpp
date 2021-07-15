#include "stdafx.h"
#include "LeafBlade.h"

HRESULT LeafBlade::init()
{
	_name = L"리프블레이드";
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

void LeafBlade::useSkill(float x, float y)
{
	_leafBladeEffect = new EF_LeafBlade;
	_leafBladeEffect->init(x, y);
	EFFECTMANAGER->addEffect(_leafBladeEffect);
}
