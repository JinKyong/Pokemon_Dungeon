#include "stdafx.h"
#include "Hold.h"

HRESULT Hold::init(float x, float y)
{
	IMAGEMANAGER->addDImage("hold1", L"img/item/hold/hold1.png", ITEMSIZE, ITEMSIZE);
	IMAGEMANAGER->addDImage("hold2", L"img/item/hold/hold2.png", ITEMSIZE, ITEMSIZE);
	IMAGEMANAGER->addDImage("hold3", L"img/item/hold/hold3.png", ITEMSIZE, ITEMSIZE);

	return S_OK;
}

void Hold::render(float x, float y)
{
}

void Hold::giveItem()
{
}