#include "stdafx.h"
#include "EF_RockSlide.h"

HRESULT EF_RockSlide::init(float x, float y)
{
	_img = IMAGEMANAGER->addFrameDImage("RockSlide", L"img/RockSlide.png", 4224, 448, 24, 1);
	_x = x;
	_y = y;
	_body = RectMakeCenter(_x, _y, 48, 48);
	_img->setFrameX(0);
	_count = 0;
	_off = false;

	return S_OK;
}

void EF_RockSlide::release()
{
}

void EF_RockSlide::update()
{
}

void EF_RockSlide::render()
{
	DTDMANAGER->Rectangle(_body);
	_img->frameRender(_x - 70, _y - 370);
	controlFrame();
}

void EF_RockSlide::controlFrame()
{
	_count += TIMEMANAGER->getElapsedTime();
	if (_count >= RENDERCOUNT)
	{
		if (_img->getFrameX() >= _img->getMaxFrameX())
			_off = true;
		else
			_img->setFrameX(_img->getFrameX() + 1);

		_count = 0;
	}
}
