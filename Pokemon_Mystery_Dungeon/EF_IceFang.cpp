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

	return S_OK;
}

void EF_IceFang::release()
{
}

void EF_IceFang::update()
{
}

void EF_IceFang::render()
{
	//DTDMANAGER->Rectangle(_body);
	_img->frameRender(_x - 70, _y - 70);
	controlFrame();
}

void EF_IceFang::controlFrame()
{
	_count += TIMEMANAGER->getElapsedTime();
	if (_count >= 0.05)
	{
		if (_img->getFrameX() >= _img->getMaxFrameX())
			_off = true;
		else
			_img->setFrameX(_img->getFrameX() + 1);

		_count = 0;
	}
}
