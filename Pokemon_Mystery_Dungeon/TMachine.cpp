#include "stdafx.h"
#include "TMachine.h"

HRESULT TMachine::init(float x, float y)
{
	//�ϴ� �� �� �ΰ�.. �������� �и��ҰԿ�
	_img = IMAGEMANAGER->addDImage("tm", L"img/item/thing/tm1.png", ITEMSIZE, ITEMSIZE);
	IMAGEMANAGER->addDImage("tm2", L"img/item/thing/tm2.png", ITEMSIZE, ITEMSIZE);

	_x = x;
	_y = y;
	_body = RectMakeCenter(x, y, ITEMSIZE, ITEMSIZE);

	_name = L"����ӽ�";

	return S_OK;
}

void TMachine::useItem()
{
}
