#include "stdafx.h"
#include "EF_MetalClaw.h"

HRESULT EF_MetalClaw::init(float x, float y)
{
	_img = IMAGEMANAGER->addFrameDImage("MetalClaw", L"img/effect/MetalClaw.png", 968, 78, 11, 1);
	_x = x;
	_y = y;
	_body = RectMakeCenter(_x, _y, 48, 48);
	_img->setFrameX(0);
	_count = 0;
	_off = false;

	return S_OK;
}

void EF_MetalClaw::release()
{
}

void EF_MetalClaw::update()
{
}

void EF_MetalClaw::render()
{
	//DTDMANAGER->Rectangle(_body);
	_img->frameRender(_x - 40, _y - 80);
	controlFrame();
}

void EF_MetalClaw::controlFrame()
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
