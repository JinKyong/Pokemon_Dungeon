#include "stdafx.h"
#include "Apple.h"

HRESULT Apple::init(float x, float y, float angle)
{
	_img = IMAGEMANAGER->addDImage("apple", L"img/item/food/apple1.png", ITEMSIZE, ITEMSIZE);
	_x = x;
	_y = y;
	_body = RectMakeCenter(x, y, ITEMSIZE, ITEMSIZE);
	_name = L"���";

	//IMAGEMANAGER->addDImage("gold_apple", L"img/item/food/apple2.png", ITEMSIZE, ITEMSIZE);	//Ȳ�ݻ��
	//IMAGEMANAGER->addDImage("rot_apple", L"img/item/food/apple3.png", ITEMSIZE, ITEMSIZE);	//����

	//_img = IMAGEMANAGER->findDImage("apple");

	return S_OK;
}

void Apple::release()
{
}

void Apple::update()
{
}

void Apple::eatItem(float value)
{

}