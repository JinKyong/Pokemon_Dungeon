#include "stdafx.h"
#include "ThunderFang.h"

HRESULT ThunderFang::init()
{
	_name = L"��������";
	_skillNum = 7;
	_damage = 65;
	_accuracy = 0.95f;
	_currentPP = _maxPP = 15;
	_atkType = PHYSICAL_ATTACK;
	_type = POKEMON_TYPE_ELECTRIC;
	_scale = SS_FRONT;

	return S_OK;
}

void ThunderFang::release()
{
}

void ThunderFang::useSkill(float x, float y)
{
	_thunderFangEffect = new EF_ThunderFang;
	_thunderFangEffect->init(x, y);
	EFFECTMANAGER->addEffect(_thunderFangEffect);
}
