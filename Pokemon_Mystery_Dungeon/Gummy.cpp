#include "stdafx.h"
#include "Gummy.h"

HRESULT Gummy::init(float x, float y, float angle)
{
	_img = IMAGEMANAGER->addFrameDImage("gummy", L"img/item/food/gummy/0.png", 544, ITEMSIZE, 17, 1);
	_x = x;
	_y = y;
	_body = RectMakeCenter(x, y, ITEMSIZE, ITEMSIZE);
	_num = RND->getInt(17);

	_name = L"±¸¹Ì";

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

void Gummy::release()
{
}

void Gummy::update()
{
}

void Gummy::render()
{
	_img->frameRender(_x, _y, _num, 0);
}

void Gummy::eatItem(float value)
{
}