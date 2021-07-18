#include "stdafx.h"
#include "EF_IceFang.h"

HRESULT EF_IceFang::init(float x, float y)
{
	_img = IMAGEMANAGER->addFrameDImage("IceFang", L"img/effect/IceFang.png", 1476, 114, 9, 1);
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

void EF_IceFang::release()
{
}

void EF_IceFang::update()
{
}
