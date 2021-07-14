#include "stdafx.h"
#include "EF_FireBlast.h"

HRESULT EF_FireBlast::init(float x, float y)
{
	_img = IMAGEMANAGER->addFrameDImage("FireBlast", L"img/effect/FireBlast.png", 2816, 134, 22, 1);
	_x = x;
	_y = y;
	_body = RectMakeCenter(_x, _y, 48, 48);
	_img->setFrameX(0);
	_count = 0;
	_off = false;
	return S_OK;
}

void EF_FireBlast::release()
{
}

void EF_FireBlast::update()
{
}

void EF_FireBlast::render()
{
	//DTDMANAGER->Rectangle(_body);
	_img->frameRender(_x - 50, _y - 80);
	controlFrame();
}

void EF_FireBlast::controlFrame()
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
