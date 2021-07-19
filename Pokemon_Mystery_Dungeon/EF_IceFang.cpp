#include "stdafx.h"
#include "EF_IceFang.h"

HRESULT EF_IceFang::init(float x, float y)
{
	Effect::init(x, y);

	_img = IMAGEMANAGER->addFrameDImage("IceFang", L"img/effect/IceFang.png", 1476, 114, 9, 1);
	_img->setFrameX(0);

	_tuningX = -(_img->getFrameWidth() / 2);
	_tuningY = -(_img->getFrameHeight() / 2);
	_renderCount = 0.05f;
	return S_OK;
}

void EF_IceFang::release()
{
}

void EF_IceFang::update()
{
}
