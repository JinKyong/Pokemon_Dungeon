#include "stdafx.h"
#include "Glass.h"

HRESULT Glass::init(float x, float y, float angle)
{
	_img = IMAGEMANAGER->addDImage("hold2", L"img/item/hold/hold2.png", ITEMSIZE, ITEMSIZE);
	_x = x;
	_y = y;
	_body = RectMakeCenter(x * TILEWIDTH + TILEWIDTH / 2, y * TILEHEIGHT + TILEHEIGHT / 2, ITEMSIZE, ITEMSIZE);
	_name = L"�Ͽ¾Ȱ�";
	_itemInfo = L"�ڽ��� ���� ������ ���濡�� �� �� �´´�";
	_itemInfoLong = L"������ ������ �����ϴ�";
	_type = ITEM_HOLD;
	_num = 19;

	return S_OK;
}

void Glass::release()
{
}

void Glass::update()
{
}

void Glass::giveItem()
{
}
