#include "stdafx.h"
#include "EF_FireBlast.h"

HRESULT EF_FireBlast::init(float x, float y)
{
	Effect::init(x, y);

	_img = IMAGEMANAGER->addFrameDImage("FireBlast", L"img/effect/FireBlast.png", 2640, 120, 22, 1);
	_img->setFrameX(0);

	_tuningX = -(_img->getFrameWidth() / 2);
	_tuningY = -(_img->getFrameHeight() / 2);
	_renderCount = 0.05f;
	return S_OK;
}

void EF_FireBlast::release()
{
}

void EF_FireBlast::update()
{
}
