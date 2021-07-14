#include "stdafx.h"
#include "FireBlast.h"

HRESULT FireBlast::init(float x, float y)
{
	_name = L"불대문자";
	_skillNum = 0;
	_damage = 120;
	_accuracy = 0.85f;
	_currentPP = _maxPP = 5;
	_skType = SPECIAL_ATTACK;
	//_att = T_FIRE
	_scale = SS_FRONT;
	useSkill(x, y);

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
