#include "stdafx.h"
#include "Gummy.h"

HRESULT Gummy::init(float x, float y)
{
	IMAGEMANAGER->addFrameDImage("gummy", L"img/item/food/gummy/1.png", 1, 17, ITEMSIZE, ITEMSIZE);

	//char key[128];
	//WCHAR str[128];
	//
	//for (int i = 0; i < GUMMY_MAX; i++)
	//{
	//	sprintf_s(key, "gummy%d", i);
	//	swprintf_s(str, L"img/item/food/gummy/%d.png", i);
	//	_imGummy[i] = IMAGEMANAGER->addDImage(key, str, ITEMSIZE, ITEMSIZE);
	//}

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