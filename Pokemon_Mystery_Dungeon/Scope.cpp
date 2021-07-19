#include "stdafx.h"
#include "Scope.h"

HRESULT Scope::init(float x, float y, float angle)
{
	_img = IMAGEMANAGER->addDImage("hold3", L"img/item/hold/hold3.png", ITEMSIZE, ITEMSIZE);
	_body = RectMakeCenter(x, y, ITEMSIZE, ITEMSIZE);
	_name = L"����Ұ�������"; //������ ������ ������ ������ �ȴ�.
	_itemInfo = L"������ ������ �����ϴ�";
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

void Scope::render(float x, float y)
{
}

void Scope::giveItem()
{
}