#include "stdafx.h"
#include "Item.h"

void Item::eatItem()
{
}

void Item::giveItem()
{
}

void Item::throwItem(float x, float y, float angle)
{
	if (!_isThrow)
	{
		_x = _fireX = x;
		_y = _fireY = y;

		_angle = angle;
		_isThrow = true;
	}
}

void Item::itemMove(float x, float y, float angle)
{
	if (_isThrow)
	{
		_isThrow = false;

		_x += cosf(_angle);
		_y += -sinf(_angle);

		_body = RectMakeCenter(_x, _y, ITEMSIZE, ITEMSIZE);
	}
}
