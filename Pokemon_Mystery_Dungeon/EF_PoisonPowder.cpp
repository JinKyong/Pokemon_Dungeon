#include "stdafx.h"
#include "EF_PoisonPowder.h"

HRESULT EF_PoisonPowder::init(float x, float y)
{
	_img = IMAGEMANAGER->addFrameDImage("PoisonPowder", L"img/effect/PoisonPowder.png", 1496, 128, 22, 1);
	_x = x;
	_y = y;
	_body = RectMakeCenter(_x, _y, 48, 48);
	_img->setFrameX(0);
	_count = 0;
	_off = false;

	return S_OK;
}

void EF_PoisonPowder::release()
{
}

void EF_PoisonPowder::update()
{
}

void EF_PoisonPowder::render()
{
	//DTDMANAGER->Rectangle(_body);
	_img->frameRender(_x - 40, _y - 80);
	controlFrame();
}

void EF_PoisonPowder::controlFrame()
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
