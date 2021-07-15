#include "stdafx.h"
#include "RockSlide.h"

HRESULT RockSlide::init()
{
	_name = L"�������";
	_skillNum = 4;
	_damage = 75;
	_accuracy = 0.9f;
	_currentPP = _maxPP = 10;
	_atkType = PHYSICAL_ATTACK;
	_type = POKEMON_TYPE_ROCK;
	_scale = SS_FRONT;

	return S_OK;
}

void RockSlide::release()
{
}

void RockSlide::useSkill(float x, float y)
{
	_rockSlideEffect = new EF_RockSlide;
	_rockSlideEffect->init(x, y);
	EFFECTMANAGER->addEffect(_rockSlideEffect);
}
