#include "stdafx.h"
#include "EF_PoisonPowder.h"

HRESULT EF_PoisonPowder::init(float x, float y, int damage, int skillScale, int atkType)
{
	Effect::init(x, y, damage, skillScale, atkType);

	_img = IMAGEMANAGER->addFrameDImage("PoisonPowder", L"img/effect/PoisonPowder.png", 1496, 128, 22, 1);
	_img->setFrameX(0);

	_tuningX = -(_img->getFrameWidth() / 2);
	_tuningY = -(_img->getFrameHeight() / 2);
	_renderCount = 0.05f;

	return S_OK;
}

void EF_PoisonPowder::release()
{
}

void EF_PoisonPowder::update()
{
}