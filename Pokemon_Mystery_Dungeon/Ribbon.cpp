#include "stdafx.h"
#include "Ribbon.h"

HRESULT Ribbon::init(float x, float y, float angle)
{
	//�Ŀ����(��1), ����ȸ���(Ư��1), ��ī��(��1), Ű�����(Ư��1)
	_img = IMAGEMANAGER->addDImage("hold1", L"img/item/hold/hold1.png", ITEMSIZE, ITEMSIZE);
	_body = RectMakeCenter(x, y, ITEMSIZE, ITEMSIZE);

	return S_OK;
}

void Ribbon::giveItem()
{
}
