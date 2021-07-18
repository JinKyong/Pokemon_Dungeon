#include "stdafx.h"
#include "EF_Gust.h"

HRESULT EF_Gust::init(float x, float y)
{
	_img = IMAGEMANAGER->addFrameDImage("Gust", L"img/effect/Gust.png", 5824, 160, 52, 1);
	_x = x;
	_y = y;
	_body = RectMakeCenter(_x, _y, TILEWIDTH, TILEHEIGHT);
	_img->setFrameX(0);
	_count = 0;
	_off = false;

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
