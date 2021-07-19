#include "stdafx.h"
#include "EF_DynamicPunch.h"

HRESULT EF_DynamicPunch::init(float x, float y)
{
	Effect::init(x, y);

	_img = IMAGEMANAGER->addFrameDImage("DynamicPunch", L"img/effect/DynamicPunch.png", 2714, 112, 23, 1);
	_img->setFrameX(0);

	_tuningX = -(_img->getFrameWidth() / 2);
	_tuningY = -(_img->getFrameHeight() / 2);
	_renderCount = 0.05f;
	return S_OK;
}

void EF_DynamicPunch::release()
{
}

void EF_DynamicPunch::update()
{
}
