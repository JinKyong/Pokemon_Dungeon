#include "stdafx.h"
#include "EF_RockSlide.h"

HRESULT EF_RockSlide::init(float x, float y)
{
	Effect::init(x, y);

	_img = IMAGEMANAGER->addFrameDImage("RockSlide", L"img/effect/RockSlide.png", 4224, 448, 24, 1);
	_img->setFrameX(0);

	_tuningX = -(_img->getFrameWidth() / 2);
	_tuningY = -(_img->getFrameHeight() / 2 + 150);
	_renderCount = 0.05f;

	return S_OK;
}

void EF_RockSlide::release()
{
}

void EF_RockSlide::update()
{
}
