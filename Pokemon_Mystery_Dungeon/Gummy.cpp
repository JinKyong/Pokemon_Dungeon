#include "stdafx.h"
#include "Gummy.h"

HRESULT Gummy::init(float x, float y)
{
	IMAGEMANAGER->addFrameDImage("gummy", L"img/item/food/gummy/1.png", 1, 17, ITEMSIZE, ITEMSIZE);
	//아직 안이어붙였어요ㅎ;

	return S_OK;
}

void Gummy::render(float x, float y)
{
}

void Gummy::eatItem()
{
}

void Gummy::throwItem(float x, float y, float angle)
{
}

void Gummy::itemMove(float x, float y, float angle)
{
}
