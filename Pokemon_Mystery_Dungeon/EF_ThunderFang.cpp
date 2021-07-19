#include "stdafx.h"
#include "EF_ThunderFang.h"

HRESULT EF_ThunderFang::init(float x, float y)
{
	Effect::init(x, y);

	_img = IMAGEMANAGER->addFrameDImage("ThunderFang", L"img/effect/ThunderFang.png", 1024, 132, 8, 1);
	_img->setFrameX(0);

	_tuningX = -(_img->getFrameWidth() / 2);
	_tuningY = -(_img->getFrameHeight() / 2);
	_renderCount = 0.05f;

	return S_OK;
}

void EF_ThunderFang::release()
{
}

void EF_ThunderFang::update()
{
}
