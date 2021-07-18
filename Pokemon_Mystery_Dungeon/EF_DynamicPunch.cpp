#include "stdafx.h"
#include "EF_DynamicPunch.h"

HRESULT EF_DynamicPunch::init(float x, float y)
{
	_img = IMAGEMANAGER->addFrameDImage("DynamicPunch", L"img/effect/DynamicPunch.png", 2714, 112, 23, 1);
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

void EF_DynamicPunch::release()
{
}

void EF_DynamicPunch::update()
{
}
