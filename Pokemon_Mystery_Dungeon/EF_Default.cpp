#include "stdafx.h"
#include "EF_Default.h"

HRESULT EF_Default::init(float x, float y, int damage, int skillScale, int atkType, POKEMON_TYPE type)
{
	Effect::init(x, y, damage, skillScale, atkType, type);

	_img = IMAGEMANAGER->addFrameDImage("DefaultAttack", L"img/effect/Default.png", 864, 48, 18, 1);
	_img->setFrameX(0);

	_tuningX = -(_img->getFrameWidth() / 2);
	_tuningY = -(_img->getFrameHeight() / 2);
	_renderCount = 0.05f;
	return S_OK;
}

void EF_Default::release()
{
}

void EF_Default::update()
{
}
