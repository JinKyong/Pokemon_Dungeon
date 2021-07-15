#include "stdafx.h"
#include "FireBlast.h"

HRESULT FireBlast::init()
{
	_name = L"불대문자";
	_skillNum = 1;
	_damage = 120;
	_accuracy = 0.85f;
	_currentPP = _maxPP = 5;
	_atkType = SPECIAL_ATTACK;
	_type = POKEMON_TYPE_FIRE;
	_scale = SS_FRONT;

	return S_OK;
}

void FireBlast::release()
{
}

void FireBlast::useSkill(float x, float y)
{
	_fireBlastEffect = new EF_FireBlast;
	_fireBlastEffect->init(x, y);
	EFFECTMANAGER->addEffect(_fireBlastEffect);
}
