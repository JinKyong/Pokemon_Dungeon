#include "stdafx.h"
#include "EF_TriAttack.h"

HRESULT EF_TriAttack::init(float x, float y, int damage, int skillScale, int atkType, POKEMON_TYPE type)
{
	Effect::init(x, y, damage, skillScale, atkType, type);

	_img = IMAGEMANAGER->addFrameDImage("TriAttack", L"img/effect/TriAttack.png", 2800, 142, 20, 1);
	_img->setFrameX(0);

	_tuningX = -(_img->getFrameWidth() / 2);
	_tuningY = -(_img->getFrameHeight() / 2);
	_renderCount = 0.06f;

	_renderCount = 0.06f;

	SOUNDMANAGER->play("TriAttack");
	return S_OK;
}

void EF_TriAttack::release()
{
}

void EF_TriAttack::update()
{
}
