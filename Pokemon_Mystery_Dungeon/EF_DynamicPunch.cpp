#include "stdafx.h"
#include "EF_DynamicPunch.h"

HRESULT EF_DynamicPunch::init(float x, float y)
{
	_img = IMAGEMANAGER->addFrameDImage("DynamicPunch", L"img/effect/DynamicPunch.png", 2714, 112, 23, 1);
	_x = x;
	_y = y;
	_body = RectMakeCenter(_x, _y, 48, 48);
	_img->setFrameX(0);
	_count = 0;
	_off = false;
	return S_OK;
}

void EF_DynamicPunch::release()
{
}

void EF_DynamicPunch::update()
{
}

void EF_DynamicPunch::render()
{
	//DTDMANAGER->Rectangle(_body);
	_img->frameRender(_x - 50, _y - 80);
	controlFrame();
}

void EF_DynamicPunch::controlFrame()
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
