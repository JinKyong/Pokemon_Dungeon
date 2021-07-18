#include "stdafx.h"
#include "Effect.h"

void Effect::render()
{
	_img->frameRender(_x + _tuningX, _y + _tuningY);
	//DTDMANAGER->Rectangle(_body);
	controlFrame();
}

void Effect::controlFrame()
{
	_count += TIMEMANAGER->getElapsedTime();
	if (_count >= _renderCount)
	{
		if (_img->getFrameX() >= _img->getMaxFrameX())
		{
			COLLISIONMANAGER->effectWithEnemy(this);
			_off = true;
		}
		// + 이펙트 플레이어 충돌 collisionmanager->this
		else
			_img->setFrameX(_img->getFrameX() + 1);

		_count = 0;
	}
}
