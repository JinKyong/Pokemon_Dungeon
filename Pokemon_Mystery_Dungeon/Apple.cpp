#include "stdafx.h"
#include "Apple.h"

HRESULT Apple::init(float x, float y)
{
	_img = IMAGEMANAGER->addDImage("apple", L"img/item/food/apple1.png", ITEMSIZE, ITEMSIZE);
	_body = RectMakeCenter(x, y, ITEMSIZE, ITEMSIZE);

	//IMAGEMANAGER->addDImage("gold_apple", L"img/item/food/apple2.png", ITEMSIZE, ITEMSIZE);	//Ȳ�ݻ��
	//IMAGEMANAGER->addDImage("rot_apple", L"img/item/food/apple3.png", ITEMSIZE, ITEMSIZE);	//����

	//_img = IMAGEMANAGER->findDImage("apple");

	return S_OK;
}

void Apple::render(float x, float y)
{

}

void Apple::eatItem()
{

}