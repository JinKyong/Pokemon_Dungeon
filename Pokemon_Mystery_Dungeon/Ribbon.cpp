#include "stdafx.h"
#include "Ribbon.h"

HRESULT Ribbon::init(float x, float y, float angle)
{
	_img = IMAGEMANAGER->addDImage("hold1", L"img/item/hold/hold1.png", ITEMSIZE, ITEMSIZE);
	_body = RectMakeCenter(x, y, ITEMSIZE, ITEMSIZE);

	_ribbonNum = RND->getInt(ENDRIBBONTYPE);

	_type = ITEM_HOLD;

	switch (_ribbonNum)
	{
	case RIBBONTYPE_POWERBAND:
		_name = L"파워밴드";
		_itemInfo = L"공격이 올라간다";
		_itemInfoLong = L"아이템 설명이 없습니다";

		_num = 20;

	case RIBBONTYPE_SHIELDSCARF:
		_name = L"방어스카프";
		_itemInfo = L"방어가 올라간다";
		_itemInfoLong = L"아이템 설명이 없습니다";

		_num = 21;

	//case RIBBONTYPE_SPECIALRIBBON:
	//	_name = L"스페셜리본";
	//	_itemInfo = L"특수공격이 올라간다";
	//	_itemInfoLong = L"아이템 설명이 없습니다";
	//
	//	_num = 22;
	//
	//case RIBBONTYPE_KETOACIDBAND:
	//	_name = L"키토산밴드";
	//	_itemInfo = L"특수방어가 올라간다";
	//	_itemInfoLong = L"아이템 설명이 없습니다";
	//
	//	_num = 23;
	}

	return S_OK;
}

void Ribbon::release()
{
}

void Ribbon::update()
{
}

void Ribbon::render(float x, float y)
{
}

void Ribbon::giveItem()
{
}
