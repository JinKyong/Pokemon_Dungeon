#include "stdafx.h"
#include "Ribbon.h"

HRESULT Ribbon::init(float x, float y, float angle)
{
	_img = IMAGEMANAGER->addDImage("hold1", L"img/item/hold/hold1.png", ITEMSIZE, ITEMSIZE);
	_x = x;
	_y = y;
	_body = RectMakeCenter(x * TILEWIDTH + TILEWIDTH / 2, y * TILEHEIGHT + TILEHEIGHT / 2, ITEMSIZE, ITEMSIZE);

	_ribbonNum = RND->getInt(ENDRIBBONTYPE);

	_type = ITEM_HOLD;

	switch (_ribbonNum)
	{
	case RIBBONTYPE_POWERBAND:
		_name = L"�Ŀ����";
		_itemInfo = L"������ �ö󰣴�";
		_itemInfoLong = L"������ ������ �����ϴ�";

		_num = 20;

	case RIBBONTYPE_SHIELDSCARF:
		_name = L"��ī��";
		_itemInfo = L"�� �ö󰣴�";
		_itemInfoLong = L"������ ������ �����ϴ�";

		_num = 21;

	//case RIBBONTYPE_SPECIALRIBBON:
	//	_name = L"����ȸ���";
	//	_itemInfo = L"Ư�������� �ö󰣴�";
	//	_itemInfoLong = L"���ϰ� �ִ� ���ϸ��� Ư�������� �ö󰣴�";
	//
	//	_num = 22;
	//
	//case RIBBONTYPE_KETOACIDBAND:
	//	_name = L"Ű�����";
	//	_itemInfo = L"Ư���� �ö󰣴�";
	//	_itemInfoLong = L"������ ������ �����ϴ�";
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

void Ribbon::giveItem()
{
}
