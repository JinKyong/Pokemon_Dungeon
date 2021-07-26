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
		_name = L"�������";
		_itemInfo = L"������ ������ �����ϴ�";
		_itemInfoLong = L"������ ������ �����ϴ�";

		_num = 25;
	case 1:
		_name = L"�ڻ�ȣ����";
		_itemInfo = L"��뿡�� ��Ƽ� ����";
		_itemInfoLong = L"��� ���� ���ư��� ���� ���ϸ󿡰� �������� �ش�";
		
		_num = 26;
	case 2:
		_name = L"Ȳ�ݰ���";
		_itemInfo = L"������ ������ �����ϴ�";
		_itemInfoLong = L"������ ������ �����ϴ�";

		_num = 27;
	case 3:
		_name = L"ö����";
		_itemInfo = L"������ ������ �����ϴ�";
		_itemInfoLong = L"������ ������ �����ϴ�";

		_num = 28;
	case 4:
		_name = L"������";
		_itemInfo = L"������ ������ �����ϴ�";
		_itemInfoLong = L"������ ������ �����ϴ�";

		_num = 29;
	case 5:
		_name = L"��������";
		_itemInfo = L"��뿡�� ��Ƽ� ����";
		_itemInfoLong = L"��� ���� ���ư��� ���� ���ϸ󿡰� �������� �ش�";

		_num = 30;
	case 6:
		_name = L"���ݰ���";
		_itemInfo = L"����ü �̰� ���� ���̿���";
		_itemInfoLong = L"������ ������ �����ϴ�";

		_num = 27;

	case 7:
		_name = L"�°�ȭ��";
		_itemInfo = L"������ ������ �����ϴ�";
		_itemInfoLong = L"������ ������ �����ϴ�";

		_num = 32;
	case 8:
		_name = L"������";
		_itemInfo = L"������ ������ �����ϴ�";
		_itemInfoLong = L"������ ������ �����ϴ�";

		_num = 33;
	case 9:
		_name = L"��������";
		_itemInfo = L"������ ������ �����ϴ�";
		_itemInfoLong = L"������ ������ �����ϴ�";

		_num = 34;
	}

	
	return S_OK;
}

//ȣ���� �κ��丮����

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