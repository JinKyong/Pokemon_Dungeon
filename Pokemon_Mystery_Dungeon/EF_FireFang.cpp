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

	return S_OK;
}

void EF_FireFang::release()
{
}

void EF_FireFang::update()
{
}

void EF_FireFang::render()
{
	//DTDMANAGER->Rectangle(_body);
	_img->frameRender(_x - 50, _y - 70);
	controlFrame();
}

void EF_FireFang::controlFrame()
{
	_count += TIMEMANAGER->getElapsedTime();
	if (_count >= 0.05f)
	{
		if (_img->getFrameX() >= _img->getMaxFrameX())
			_off = true;
		else
			_img->setFrameX(_img->getFrameX() + 1);

		_count = 0;
	}
}
