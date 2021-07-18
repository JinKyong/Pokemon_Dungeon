#include "stdafx.h"
#include "EF_MetalClaw.h"

HRESULT EF_MetalClaw::init(float x, float y)
{
	_img = IMAGEMANAGER->addFrameDImage("MetalClaw", L"img/effect/MetalClaw.png", 968, 78, 11, 1);
	_x = x;
	_y = y;
	_body = RectMakeCenter(_x, _y, TILEWIDTH, TILEHEIGHT);
	_img->setFrameX(0);
	_count = 0;
	_off = false;

	_tuningX = -(_img->getFrameWidth() / 2);
	_tuningY = -(_img->getFrameHeight() / 2);
	_renderCount = 0.06f;
	return S_OK;
}

void EF_MetalClaw::release()
{
}

void EF_MetalClaw::update()
{
}
