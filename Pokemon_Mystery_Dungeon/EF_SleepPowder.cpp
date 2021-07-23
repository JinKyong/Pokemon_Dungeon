#include "stdafx.h"
#include "EF_SleepPowder.h"

HRESULT EF_SleepPowder::init(float x, float y, int damage, int skillScale, int atkType)
{
	Effect::init(x, y, damage, skillScale, atkType);

	_img = IMAGEMANAGER->addFrameDImage("SleepPowder", L"img/effect/SleepPowder.png", 1496, 128, 22, 1);
	_img->setFrameX(0);

	_tuningX = -(_img->getFrameWidth() / 2);
	_tuningY = -(_img->getFrameHeight() / 2);
	_renderCount = 0.05f;

	return S_OK;
}

void EF_SleepPowder::release()
{
}

void EF_SleepPowder::update()
{
}
