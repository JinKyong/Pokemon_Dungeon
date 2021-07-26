#include "stdafx.h"
#include "EF_StunSpore.h"

HRESULT EF_StunSpore::init(float x, float y, int damage, int skillScale, int atkType, POKEMON_TYPE type)
{
	Effect::init(x, y, damage, skillScale, atkType, type);

	_img = IMAGEMANAGER->addFrameDImage("StunSpore", L"img/effect/StunSpore.png", 1496, 128, 22, 1);
	_img->setFrameX(0);

	_tuningX = -(_img->getFrameWidth() / 2);
	_tuningY = -(_img->getFrameHeight() / 2 + 30);
	_renderCount = 0.03f;

	SOUNDMANAGER->play("Powder");
	return S_OK;
}

void EF_StunSpore::release()
{
}

void EF_StunSpore::update()
{
}
