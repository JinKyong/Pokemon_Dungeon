#include "stdafx.h"
#include "Hold.h"

HRESULT Hold::init(float x, float y)
{
	//홀드 아이템 8종류를 다 따로 해야하는지? 고민중입니다
	IMAGEMANAGER->addDImage("hold1", L"img/item/hold/hold1.png", ITEMSIZE, ITEMSIZE);
	IMAGEMANAGER->addDImage("hold2", L"img/item/hold/hold2.png", ITEMSIZE, ITEMSIZE);
	IMAGEMANAGER->addDImage("hold3", L"img/item/hold/hold3.png", ITEMSIZE, ITEMSIZE);
	
	IMAGEMANAGER->addDImage("rareHold1", L"img/item/hold/r_hold1.png", ITEMSIZE, ITEMSIZE);
	IMAGEMANAGER->addDImage("rareHold2", L"img/item/hold/r_hold2.png", ITEMSIZE, ITEMSIZE);
	IMAGEMANAGER->addDImage("rareHold3", L"img/item/hold/r_hold3.png", ITEMSIZE, ITEMSIZE);
	IMAGEMANAGER->addDImage("rareHold4", L"img/item/hold/r_hold4.png", ITEMSIZE, ITEMSIZE);
	IMAGEMANAGER->addDImage("rareHold5", L"img/item/hold/r_hold5.png", ITEMSIZE, ITEMSIZE);

	return S_OK;
}

void Hold::render(float x, float y)
{
}

void Hold::giveItem()
{
}

void Hold::throwItem(float x, float y, float angle)
{
}

void Hold::itemMove(float x, float y, float angle)
{
}
