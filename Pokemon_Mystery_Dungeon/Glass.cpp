#include "stdafx.h"
#include "Glass.h"

HRESULT Glass::init(float x, float y, float angle)
{
	_img = IMAGEMANAGER->addDImage("hold2", L"img/item/hold/hold2.png", ITEMSIZE, ITEMSIZE);
	_body = RectMakeCenter(x, y, ITEMSIZE, ITEMSIZE);
	_name = L"�Ͽ¾Ȱ�"; //�ڽ��� ���� ������ ���濡�� �� �� �´´�.
	_itemInfo = L"������ ������ �����ϴ�";
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

void Glass::render(float x, float y)
{
}

void Glass::giveItem()
{
}
