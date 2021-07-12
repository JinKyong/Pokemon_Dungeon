#include "stdafx.h"
#include "Pokemon.h"

void Pokemon::controlFrame()
{
	_count += TIMEMANAGER->getElapsedTime();

	if (_count >= RENDERCOUNT2) {
		if (_frameX >= _currentImg->getMaxFrameX())
			_frameX = 0;
		else
			_frameX++;

		_count = 0;
	}
}
