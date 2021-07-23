#include "stdafx.h"
#include "EF_MetalClaw.h"

HRESULT EF_MetalClaw::init(float x, float y, int damage, int skillScale, int atkType)
{
	Effect::init(x, y, damage, skillScale, atkType);

	_img = IMAGEMANAGER->addFrameDImage("MetalClaw", L"img/effect/MetalClaw.png", 968, 78, 11, 1);
	_img->setFrameX(0);

	_tuningX = -(_img->getFrameWidth() / 2);
	_tuningY = -(_img->getFrameHeight() / 2);
	_renderCount = 0.06f;

	return S_OK;
}

void EF_MetalClaw::release()
{
}

void EF_MetalClaw::update()
{
}
