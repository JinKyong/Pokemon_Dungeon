#include "stdafx.h"
#include "EF_StunSpore.h"

HRESULT EF_StunSpore::init(float x, float y)
{
	_img = IMAGEMANAGER->addFrameDImage("StunSpore", L"img/effect/StunSpore.png", 1496, 128, 22, 1);
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

void EF_StunSpore::release()
{
}

void EF_StunSpore::update()
{
}
