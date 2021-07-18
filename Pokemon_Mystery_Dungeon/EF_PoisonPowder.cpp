#include "stdafx.h"
#include "EF_PoisonPowder.h"

HRESULT EF_PoisonPowder::init(float x, float y)
{
	_img = IMAGEMANAGER->addFrameDImage("PoisonPowder", L"img/effect/PoisonPowder.png", 1496, 128, 22, 1);
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

void EF_PoisonPowder::release()
{
}

void EF_PoisonPowder::update()
{
}