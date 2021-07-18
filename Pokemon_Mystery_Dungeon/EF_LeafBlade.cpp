#include "stdafx.h"
#include "EF_LeafBlade.h"

HRESULT EF_LeafBlade::init(float x, float y)
{
	_img = IMAGEMANAGER->addFrameDImage("LeafBlade", L"img/effect/LeafBlade.png", 4774, 162, 31, 1);
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

void EF_LeafBlade::release()
{
}

void EF_LeafBlade::update()
{
}
