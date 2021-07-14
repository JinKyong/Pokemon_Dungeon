#include "stdafx.h"
#include "EF_Gust.h"

HRESULT EF_Gust::init(float x, float y)
{
	_img = IMAGEMANAGER->addFrameDImage("Gust", L"img/effect/Gust.png", 5824, 160, 52, 1);
	_x = x;
	_y = y;
	_body = RectMakeCenter(_x, _y, 48, 48);
	_img->setFrameX(0);
	_count = 0;
	_off = false;
	return S_OK;
}

void EF_Gust::release()
{
}

void EF_Gust::update()
{
}

void EF_Gust::render()
{
	//DTDMANAGER->Rectangle(_body);
	_img->frameRender(_x - 50, _y - 120);
	controlFrame();
}

void EF_Gust::controlFrame()
{
	_count += TIMEMANAGER->getElapsedTime();
	if (_count >= 0.02f)
	{
		if (_img->getFrameX() >= _img->getMaxFrameX())
			_off = true;
		else
			_img->setFrameX(_img->getFrameX() + 1);

		_count = 0;
	}
}
