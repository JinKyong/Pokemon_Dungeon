#include "stdafx.h"
#include "EF_LeafBlade.h"

HRESULT EF_LeafBlade::init(float x, float y)
{
	_img = IMAGEMANAGER->addFrameDImage("LeafBlade", L"img/effect/LeafBlade.png", 4774, 162, 31, 1);
	_x = x;
	_y = y;
	_body = RectMakeCenter(_x, _y, 48, 48);
	_img->setFrameX(0);
	_count = 0;
	_off = false;

	return S_OK;
}

void EF_LeafBlade::release()
{
}

void EF_LeafBlade::update()
{
}

void EF_LeafBlade::render()
{
	DTDMANAGER->Rectangle(_body);
	_img->frameRender(_x - 70, _y - 80);
	controlFrame();
}

void EF_LeafBlade::controlFrame()
{
	_count += TIMEMANAGER->getElapsedTime();
	if (_count >= 0.03)
	{
		if (_img->getFrameX() >= _img->getMaxFrameX())
			_off = true;
		else
			_img->setFrameX(_img->getFrameX() + 1);

		_count = 0;
	}
}
