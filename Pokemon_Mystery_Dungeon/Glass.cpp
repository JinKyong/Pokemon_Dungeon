#include "stdafx.h"
#include "Glass.h"

HRESULT Glass::init(float x, float y)
{
	//�Ȱ� ���� �ǰ� ���׿� �Ͽ¾Ȱ�?
	_img = IMAGEMANAGER->addDImage("hold2", L"img/item/hold/hold2.png", ITEMSIZE, ITEMSIZE);
	_body = RectMakeCenter(x, y, ITEMSIZE, ITEMSIZE);

	return S_OK;
}

void Glass::render(float x, float y)
{
}

void Glass::giveItem()
{
}
