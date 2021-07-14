#include "stdafx.h"
#include "ThrowItem.h"

HRESULT ThrowItem::init(float x, float y)
{

	return S_OK;
}

void ThrowItem::render(float x, float y)
{
	
}

void ThrowItem::throwItem(float x, float y, float angle)
{
	if(!_isThrow)
	{
		_x = _fireX = x;
		_y = _fireY = y;

		//_speed = 7.f;
		_angle = angle;
		_isThrow = true;
	}
}

void ThrowItem::itemMove(float x, float y, float angle)
{
	if (_isThrow)
	{
		_isThrow = false;

		_x += cosf(_angle);
		_y += -sinf(_angle);

		_body = RectMakeCenter(_x, _y, ITEMSIZE, ITEMSIZE);
	}
}
