#include "stdafx.h"
#include "EF_LeafBlade.h"

HRESULT EF_LeafBlade::init(float x, float y, int damage, int skillScale, int atkType)
{
	Effect::init(x, y, damage, skillScale, atkType);

	_img = IMAGEMANAGER->addFrameDImage("LeafBlade", L"img/effect/LeafBlade.png", 4774, 162, 31, 1);
	_img->setFrameX(0);

	_tuningX = -(_img->getFrameWidth() / 2);
	_tuningY = -(_img->getFrameHeight() / 2);
	_renderCount = 0.05f;
	return S_OK;
}

void EF_LeafBlade::release()
{
}

void EF_LeafBlade::update()
{
}
