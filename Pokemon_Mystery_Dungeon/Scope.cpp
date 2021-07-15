#include "stdafx.h"
#include "Scope.h"

HRESULT Scope::init(float x, float y, float angle)
{
	//제어불가스코프랑 불면스코프중 고민
	_img = IMAGEMANAGER->addDImage("hold3", L"img/item/hold/hold3.png", ITEMSIZE, ITEMSIZE);
	_body = RectMakeCenter(x, y, ITEMSIZE, ITEMSIZE);

	return S_OK;
}

void Scope::giveItem()
{
}