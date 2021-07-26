#include "stdafx.h"
#include "Scope.h"

HRESULT Scope::init(float x, float y, float angle)
{
	_img = IMAGEMANAGER->addDImage("hold3", L"img/item/hold/hold3.png", ITEMSIZE, ITEMSIZE);
	_x = x;
	_y = y;
	_body = RectMakeCenter(x * TILEWIDTH + TILEWIDTH / 2, y * TILEHEIGHT + TILEHEIGHT / 2, ITEMSIZE, ITEMSIZE);

	_name = L"����Ұ�������";
	_itemInfo = L"������ ������ ������ ������ �ȴ�";
	_itemInfoLong = L"������ ������ �����ϴ�";
	_type = ITEM_HOLD;
	_num = 24;

	return S_OK;
}

void Scope::release()
{
}

void Scope::update()
{
}

void Scope::giveItem()
{
}