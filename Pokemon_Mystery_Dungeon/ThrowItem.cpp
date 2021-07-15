#include "stdafx.h"
#include "ThrowItem.h"

HRESULT ThrowItem::init(float x, float y, float angle)
{
	_img = IMAGEMANAGER->addFrameDImage("branch", L"img/item/thihg/throw/0.png", 320, ITEMSIZE, 1, 10);
	_body = RectMakeCenter(x, y, ITEMSIZE, ITEMSIZE);
	_x = x;
	_y = y;
	_fireX = _x;
	_fireY = _y;
	_angle = angle;

	return S_OK;
}

void ThrowItem::update()
{
	//충돌검사만
}