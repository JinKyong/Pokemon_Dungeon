#include "stdafx.h"
#include "Scope.h"

HRESULT Scope::init(float x, float y, float angle)
{
	//����Ұ��������� �Ҹ齺������ ���
	_img = IMAGEMANAGER->addDImage("hold3", L"img/item/hold/hold3.png", ITEMSIZE, ITEMSIZE);
	_body = RectMakeCenter(x, y, ITEMSIZE, ITEMSIZE);

	return S_OK;
}

void Scope::giveItem()
{
}