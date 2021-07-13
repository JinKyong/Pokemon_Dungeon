#include "stdafx.h"
#include "food.h"

HRESULT Food::init(float x, float y)
{
	IMAGEMANAGER->addDImage("apple", L"img/item/food/apple1.png", ITEMSIZE, ITEMSIZE);
	IMAGEMANAGER->addDImage("gold_apple", L"img/item/food/apple2.png", ITEMSIZE, ITEMSIZE); //황금사과
	IMAGEMANAGER->addDImage("rot_apple", L"img/item/food/apple3.png", ITEMSIZE, ITEMSIZE);	//썩은

	if(_concType == APPLE) _img = IMAGEMANAGER->findDImage("apple");
	

	//if (_concType == GUMMY)
	//{
	//	char key[128];
	//	WCHAR str[128];
	//
	//	for (int i = 0; i < GUMMY_MAX; i++)
	//	{
	//		sprintf_s(key, "gummy%d", i);
	//		swprintf_s(str, L"img/item/food/gummy/%d.png", i);
	//		_imGummy[i] = IMAGEMANAGER->addDImage(key, str, ITEMSIZE, ITEMSIZE);
	//	}
	//}
	

	return S_OK;
}
