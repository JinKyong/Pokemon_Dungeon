#include "stdafx.h"
#include "EF_ThunderFang.h"

HRESULT EF_ThunderFang::init(float x, float y)
{
	_img = IMAGEMANAGER->addFrameDImage("ThunderFang", L"img/effect/ThunderFang.png", 1024, 132, 8, 1);
	_x = x;
	_y = y;
	_body = RectMakeCenter(_x, _y, TILEWIDTH, TILEHEIGHT);
	_img->setFrameX(0);
	_count = 0;
	_off = false;

	return S_OK;
}

void EF_ThunderFang::release()
{
}

void EF_ThunderFang::update()
{
}

void EF_ThunderFang::render()
{
	//DTDMANAGER->Rectangle(_body);
	_img->frameRender(_x - 40, _y - 80);
	controlFrame();
}

void EF_ThunderFang::controlFrame()
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
