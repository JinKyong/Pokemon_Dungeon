#include "stdafx.h"
#include "food.h"

HRESULT Food::init(float x, float y)
{
	IMAGEMANAGER->addDImage("apple", L"img/item/food/apple1.png", ITEMSIZE, ITEMSIZE);
	IMAGEMANAGER->addDImage("gold_apple", L"img/item/food/apple2.png", ITEMSIZE, ITEMSIZE); //황금사과
	IMAGEMANAGER->addDImage("rot_apple", L"img/item/food/apple3.png", ITEMSIZE, ITEMSIZE);	//썩은

	if(_concType == APPLE) _img = IMAGEMANAGER->findDImage("apple");
	
	/*
	//score에 이미지 입힐때처럼 해보고 싶었는데 실패한 결과물이라고 하는데요
	if (_concType == GUMMY)
	{
		WCHAR key[128], str[128];

		for (int i = 0; i < GUMMY_MAX; i++)
		{
			swprintf_s(key, L"gummy%d", i);
			swprintf_s(str, L"img/item/food/gummy/%d.png", i);
			_imGummy[i] = IMAGEMANAGER->addDImage(key, str, ITEMSIZE, ITEMSIZE); //왜깨지지?
		}
	}
	*/

	return S_OK;
}

void Food::useItem()
{
}
