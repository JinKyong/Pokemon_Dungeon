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

	_num = RND->getInt(10);

	_name = L"나뭇가지"; //ㅋ...
	
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
	_img->frameRender(_x * TILEWIDTH + TILEWIDTH / 2 - _img->getFrameWidth() / 2,
					  _y * TILEHEIGHT + TILEHEIGHT / 2 - _img->getFrameHeight() / 2, _num, 0);
	DTDMANAGER->Rectangle(_body);
}