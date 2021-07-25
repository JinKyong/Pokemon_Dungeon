#include "stdafx.h"
#include "RockSmash.h"

HRESULT RockSmash::init(Player* player)
{
	Skill::init(player);
	_name = L"¹ÙÀ§±ú±â";
	_skillNum = 18;
	_damage = 40;
	_accuracy = 1.f;
	_currentPP = _maxPP = 15;
	_atkType = PHYSICAL_ATTACK;
	_type = POKEMON_TYPE_FIGHTING;
	_scale = SS_FRONT;

	return S_OK;
}

void RockSmash::release()
{
}

void RockSmash::useSkill()
{
	Skill::useSkill();

	_rockSmashEffect = new EF_RockSmash;
	_rockSmashEffect->init(_x, _y, _damage, _scale, _atkType);
	EFFECTMANAGER->addEffect(_rockSmashEffect);
}
