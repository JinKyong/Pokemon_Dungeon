#include "stdafx.h"
#include "Ribbon.h"

HRESULT Ribbon::init(float x, float y, float angle)
{
	//파워밴드(공1), 스페셜리본(특공1), 방어스카프(방1), 키토산밴드(특방1)
	_img = IMAGEMANAGER->addDImage("hold1", L"img/item/hold/hold1.png", ITEMSIZE, ITEMSIZE);
	_body = RectMakeCenter(x, y, ITEMSIZE, ITEMSIZE);

	return S_OK;
}

void Ribbon::giveItem()
{
}
