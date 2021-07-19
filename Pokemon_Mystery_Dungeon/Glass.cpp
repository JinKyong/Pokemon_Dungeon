#include "stdafx.h"
#include "Glass.h"

HRESULT Glass::init(float x, float y, float angle)
{
	_img = IMAGEMANAGER->addDImage("hold2", L"img/item/hold/hold2.png", ITEMSIZE, ITEMSIZE);
	_body = RectMakeCenter(x, y, ITEMSIZE, ITEMSIZE);
	_name = L"록온안경"; //자신이 던진 도구가 상대방에게 더 잘 맞는다.
	_itemInfo = L"아이템 설명이 없습니다";
	_itemInfoLong = L"아이템 설명이 없습니다";
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
