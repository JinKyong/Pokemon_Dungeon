#include "stdafx.h"
#include "ThrowItem.h"

HRESULT ThrowItem::init(float x, float y, float angle)
{
	_img = IMAGEMANAGER->addFrameDImage("branch", L"img/item/thing/throw/0.png", 320, ITEMSIZE, 10, 1);
	_x = x;
	_y = y;
	_body = RectMakeCenter(x * TILEWIDTH + TILEWIDTH / 2, y * TILEHEIGHT + TILEHEIGHT / 2, ITEMSIZE, ITEMSIZE);
	//_fireX = _x;
	//_fireY = _y;
	//_angle = angle;

	_throwNum = RND->getInt(10);
	_type = ITEM_THROW;

	
	switch (_throwNum)
	{
	case 0:
		_name = L"녹색가시";
		_itemInfo = L"아이템 설명이 없습니다";
		_itemInfoLong = L"아이템 설명이 없습니다";

		_num = 25;
	case 1:
		_name = L"코산호가시";
		_itemInfo = L"상대에게 쏘아서 공격";
		_itemInfoLong = L"쏘면 곧장 날아가서 맞은 포켓몬에게 데미지를 준다";
		
		_num = 26;
	case 2:
		_name = L"황금가시";
		_itemInfo = L"아이템 설명이 없습니다";
		_itemInfoLong = L"아이템 설명이 없습니다";

		_num = 27;
	case 3:
		_name = L"철가시";
		_itemInfo = L"아이템 설명이 없습니다";
		_itemInfoLong = L"아이템 설명이 없습니다";

		_num = 28;
	case 4:
		_name = L"은가시";
		_itemInfo = L"아이템 설명이 없습니다";
		_itemInfoLong = L"아이템 설명이 없습니다";

		_num = 29;
	case 5:
		_name = L"나뭇가지";
		_itemInfo = L"상대에게 쏘아서 공격";
		_itemInfoLong = L"쏘면 곧장 날아가서 맞은 포켓몬에게 데미지를 준다";

		_num = 30;
	case 6:
		_name = L"순금가시";
		_itemInfo = L"도대체 이게 무슨 템이에요";
		_itemInfoLong = L"아이템 설명이 없습니다";

		_num = 27;

	case 7:
		_name = L"태고화석";
		_itemInfo = L"아이템 설명이 없습니다";
		_itemInfoLong = L"아이템 설명이 없습니다";

		_num = 32;
	case 8:
		_name = L"돌멩이";
		_itemInfo = L"아이템 설명이 없습니다";
		_itemInfoLong = L"아이템 설명이 없습니다";

		_num = 33;
	case 9:
		_name = L"데구리돌";
		_itemInfo = L"아이템 설명이 없습니다";
		_itemInfoLong = L"아이템 설명이 없습니다";

		_num = 34;
	}

	
	return S_OK;
}

//호출은 인벤토리에서

void ThrowItem::release()
{
}

void ThrowItem::update()
{

}

void ThrowItem::render()
{
	DTDMANAGER->Rectangle(_body);
	_img->frameRender(_x * TILEWIDTH + TILEWIDTH / 2 - _img->getFrameWidth() / 2,
					  _y * TILEHEIGHT + TILEHEIGHT / 2 - _img->getFrameHeight() / 2, _throwNum, 0);
}