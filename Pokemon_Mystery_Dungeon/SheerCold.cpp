#include "stdafx.h"
#include "SheerCold.h"

HRESULT SheerCold::init(Player * player)
{
	Skill::init(player);
	_name = L"���뿵��";
	_skillNum = 25;
	_damage = 110;
	_accuracy = 0.85f;
	_currentPP = _maxPP = 5;
	_atkType = SPECIAL_ATTACK;
	_type = POKEMON_TYPE_ICE;
	_scale = SS_FRONT;

	return S_OK;
}

void SheerCold::release()
{
}

void SheerCold::useSkill()
{
	Skill::useSkill();

	_sheerColdEffect = new EF_SheerCold;
	_sheerColdEffect->init(_x, _y, _damage, _scale, _atkType);
	EFFECTMANAGER->addEffect(_sheerColdEffect);
}
