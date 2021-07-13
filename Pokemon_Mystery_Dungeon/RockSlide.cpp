#include "stdafx.h"
#include "RockSlide.h"

HRESULT RockSlide::init(float x, float y)
{
	_name = L"½ºÅæ»þ¿ö";
	_skillNum = 84;
	_damage = 75;
	_accuracy = 0.9f;
	_currentPP = _maxPP = 10;
	_skType = PHYSICAL_ATTACK;
	//_att = T_ROCK;
	_scale = SS_FRONT;
	useSkill(x, y);

	return S_OK;
}

void RockSlide::release()
{
}

void RockSlide::useSkill(float x, float y)
{
	EFFECTMANAGER->addEffect(x, y, 3);
}
