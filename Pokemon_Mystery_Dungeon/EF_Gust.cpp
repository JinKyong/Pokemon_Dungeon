#include "stdafx.h"
#include "EF_Gust.h"

HRESULT EF_Gust::init(float x, float y)
{
	Effect::init(x, y);

	_img = IMAGEMANAGER->addFrameDImage("Gust", L"img/effect/Gust.png", 5824, 160, 52, 1);
	_img->setFrameX(0);

	_tuningX = -(_img->getFrameWidth() / 2);
	_tuningY = -(_img->getFrameHeight() / 2 + 40);
	_renderCount = 0.02f;
	return S_OK;
}

void EF_Gust::release()
{
}

void EF_Gust::update()
{
}
