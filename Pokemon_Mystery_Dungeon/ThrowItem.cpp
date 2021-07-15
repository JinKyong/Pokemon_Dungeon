#include "stdafx.h"
#include "ThrowItem.h"

HRESULT ThrowItem::init(float x, float y)
{
	_img = IMAGEMANAGER->addDImage("branch", L"img/item/thihg/throw/1.png", ITEMSIZE, ITEMSIZE);
	_body = RectMakeCenter(x, y, ITEMSIZE, ITEMSIZE);

	return S_OK;
}

void ThrowItem::render(float x, float y)
{

}