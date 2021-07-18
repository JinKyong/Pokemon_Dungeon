#include "stdafx.h"
#include "Gummy.h"

HRESULT Gummy::init(float x, float y, float angle)
{
	_img = IMAGEMANAGER->addFrameDImage("gummy", L"img/item/food/gummy/0.png", 544, ITEMSIZE, 17, 1);
	_x = x;
	_y = y;
	_body = RectMakeCenter(x * TILEWIDTH + TILEWIDTH / 2, y * TILEHEIGHT + TILEHEIGHT / 2, ITEMSIZE, ITEMSIZE);

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
	if (PRINTMANAGER->isDebug())	DTDMANAGER->Rectangle(_body);
	_img->frameRender(_x * TILEWIDTH + TILEWIDTH / 2 - _img->getFrameWidth() / 2,
		_y * TILEHEIGHT + TILEHEIGHT / 2 - _img->getFrameHeight() / 2, _num, 0);
}

void Gummy::eatItem(float value)
{
}