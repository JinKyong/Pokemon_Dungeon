#include "stdafx.h"
#include "Lightning.h"

HRESULT Lightning::init(float x, float y)
{
	_name = L"전기충격";
	_skillNum = 84;
	_damage = 40;
	_accuracy = 1.f;
	_currentPP = _maxPP = 30;
	_skType = SPECIAL_ATTACK;
	//_att = T_ELECTRIC;
	_scale = SS_FRONT;
	useSkill(x, y);

	return S_OK;
}

void Lightning::release()
{
}

void Lightning::useSkill(float x, float y)
{
	EFFECTMANAGER->addEffect(x, y, 2);
}
