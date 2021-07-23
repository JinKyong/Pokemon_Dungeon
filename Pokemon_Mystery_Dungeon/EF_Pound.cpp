#include "stdafx.h"
#include "EF_Pound.h"

HRESULT EF_Pound::init(float x, float y, int damage, int skillScale, int atkType)
{
	Effect::init(x, y, damage, skillScale, atkType);

	_img = IMAGEMANAGER->addFrameDImage("Pound", L"img/effect/Pound.png", 2268, 116, 21, 1);
	_img->setFrameX(0);

	_tuningX = -(_img->getFrameWidth() / 2);
	_tuningY = -(_img->getFrameHeight() / 2);
	_renderCount = 0.05f;

	return S_OK;
}

void EF_Pound::release()
{
}

void EF_Pound::update()
{
}
