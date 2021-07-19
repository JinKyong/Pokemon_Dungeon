#include "stdafx.h"
#include "EF_StunSpore.h"

HRESULT EF_StunSpore::init(float x, float y)
{
	Effect::init(x, y);

	_img = IMAGEMANAGER->addFrameDImage("StunSpore", L"img/effect/StunSpore.png", 1496, 128, 22, 1);
	_img->setFrameX(0);

	_tuningX = -(_img->getFrameWidth() / 2);
	_tuningY = -(_img->getFrameHeight() / 2);
	_renderCount = 0.05f;

	return S_OK;
}

void EF_StunSpore::release()
{
}

void EF_StunSpore::update()
{
}
