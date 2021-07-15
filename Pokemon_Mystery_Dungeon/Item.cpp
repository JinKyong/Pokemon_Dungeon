#include "stdafx.h"
#include "Item.h"

/*
void Item::eatItem(float value)
{
	//¹ÝÈ¯
}

void Item::giveItem()
{
}
*/

void Item::render()
{
	_img->render(_x, _y);
}

void Item::throwItem(float x, float y, float angle)
{
	_x = _fireX = x;
	_y = _fireY = y;

	_angle = angle;
}

void Item::itemMove()
{
	_x += cosf(_angle);
	_y += -sinf(_angle);

	_body = RectMakeCenter(_x, _y, ITEMSIZE, ITEMSIZE);
}