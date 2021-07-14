#include "stdafx.h"
#include "EF_Lightning.h"

HRESULT EF_Lightning::init(float x, float y)
{
	_img = IMAGEMANAGER->addFrameDImage("Lightning", L"img/effect/Lightning.png", 816, 286, 12, 1);
	_x = x;
	_y = y;
	_body = RectMakeCenter(_x, _y, 48, 48);
	_img->setFrameX(0);
	_count = 0;
	_off = false;

	return S_OK;
}

void EF_Lightning::release()
{
}

void EF_Lightning::update()
{
}

void EF_Lightning::render()
{
	//DTDMANAGER->Rectangle(_body);
	_img->frameRender(_x - 30, _y - 270);
	controlFrame();
}

void EF_Lightning::controlFrame()
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
