#include "stdafx.h"
#include "EF_ThunderFang.h"

HRESULT EF_ThunderFang::init(float x, float y)
{
	_img = IMAGEMANAGER->addFrameDImage("ThunderFang", L"img/effect/ThunderFang.png", 1024, 132, 8, 1);
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

void EF_ThunderFang::release()
{
}

void EF_ThunderFang::update()
{
}
