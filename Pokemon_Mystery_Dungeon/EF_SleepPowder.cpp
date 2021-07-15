#include "stdafx.h"
#include "EF_SleepPowder.h"

HRESULT EF_SleepPowder::init(float x, float y)
{
	_img = IMAGEMANAGER->addFrameDImage("SleepPowder", L"img/effect/SleepPowder.png", 1496, 128, 22, 1);
	_x = x;
	_y = y;
	_body = RectMakeCenter(_x, _y, 48, 48);
	_img->setFrameX(0);
	_count = 0;
	_off = false;

	return S_OK;
}

void EF_SleepPowder::release()
{
}

void EF_SleepPowder::update()
{
}

void EF_SleepPowder::render()
{
	//DTDMANAGER->Rectangle(_body);
	_img->frameRender(_x - 40, _y - 80);
	controlFrame();
}

void EF_SleepPowder::controlFrame()
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
