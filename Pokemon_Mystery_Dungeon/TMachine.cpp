#include "stdafx.h"
#include "TMachine.h"

HRESULT TMachine::init(float x, float y)
{
	IMAGEMANAGER->addDImage("tm", L"img/item/thing/tm1.png", ITEMSIZE, ITEMSIZE);
	IMAGEMANAGER->addDImage("tm2", L"img/item/thing/tm2.png", ITEMSIZE, ITEMSIZE);
	IMAGEMANAGER->addDImage("used_tm", L"img/item/thing/tm3.png", ITEMSIZE, ITEMSIZE);

	return S_OK;
}

void TMachine::useItem()
{
}
