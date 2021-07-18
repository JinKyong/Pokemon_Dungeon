#include "stdafx.h"
#include "EF_FireFang.h"

HRESULT EF_FireFang::init(float x, float y)
{
	_img = IMAGEMANAGER->addFrameDImage("FireFang", L"img/effect/FireFang.png", 1440, 112, 10, 1);
	_x = x;
	_y = y;
	_body = RectMakeCenter(_x, _y, TILEWIDTH, TILEHEIGHT);
	_img->setFrameX(0);
	_count = 0;
	_off = false;

	_tuningX = -(_img->getFrameWidth() / 2);
	_tuningY = -(_img->getFrameHeight() / 2);
	_renderCount = 0.05f;
	return S_OK;
}

void EF_FireFang::release()
{
}

void EF_FireFang::update()
{
}
