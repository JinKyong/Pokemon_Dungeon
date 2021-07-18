#include "stdafx.h"
#include "EF_RockSlide.h"

HRESULT EF_RockSlide::init(float x, float y)
{
	_img = IMAGEMANAGER->addFrameDImage("RockSlide", L"img/effect/RockSlide.png", 4224, 448, 24, 1);
	_x = x;
	_y = y;
	_body = RectMakeCenter(_x, _y, TILEWIDTH, TILEHEIGHT);
	_img->setFrameX(0);
	_count = 0;
	_off = false;

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
