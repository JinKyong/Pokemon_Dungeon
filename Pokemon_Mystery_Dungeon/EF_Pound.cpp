#include "stdafx.h"
#include "EF_Pound.h"

HRESULT EF_Pound::init(float x, float y)
{
	_img = IMAGEMANAGER->addFrameDImage("Pound", L"img/effect/Pound.png", 2268, 116, 21, 1);
	_x = x;
	_y = y;
	_body = RectMakeCenter(_x, _y, TILEWIDTH, TILEHEIGHT);
	_img->setFrameX(0);
	_count = 0;
	_off = false;

	return S_OK;
}

void EF_Pound::release()
{
}

void EF_Pound::update()
{
}

void EF_Pound::render()
{
	//DTDMANAGER->Rectangle(_body);
	_img->frameRender(_x - 30, _y - 70);
	controlFrame();
}

void EF_Pound::controlFrame()
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
