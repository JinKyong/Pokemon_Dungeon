#include "stdafx.h"
#include "EF_Lightning.h"

HRESULT EF_Lightning::init(float x, float y)
{
	_img = IMAGEMANAGER->addFrameDImage("Lightning", L"img/effect/Lightning.png", 816, 286, 12, 1);
	_x = x;
	_y = y;
	_body = RectMakeCenter(_x, _y, TILEWIDTH, TILEHEIGHT);
	_img->setFrameX(0);
	_count = 0;
	_off = false;

	_tuningX = -(_img->getFrameWidth() / 2);
	_tuningY = -(_img->getFrameHeight() / 2 + 130);
	_renderCount = 0.05f;
	return S_OK;
}

void EF_Lightning::release()
{
}

void EF_Lightning::update()
{
}
