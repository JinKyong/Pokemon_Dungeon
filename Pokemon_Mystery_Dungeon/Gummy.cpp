#include "stdafx.h"
#include "Gummy.h"

HRESULT Gummy::init(float x, float y, float angle)
{
	_img = IMAGEMANAGER->addFrameDImage("gummy", L"img/item/food/gummy/0.png", 544, ITEMSIZE, 17, 1);
	_x = x;
	_y = y;
	_body = RectMakeCenter(x * TILEWIDTH + TILEWIDTH / 2, y * TILEHEIGHT + TILEHEIGHT / 2, ITEMSIZE, ITEMSIZE);

	_num = RND->getInt(END_POKEMON_TYPE);
	_type = ITEM_FOOD;

	switch (_num)
	{
	case 0: //이따 이넘문으로....
		_name = L"빨간구미";
		_gummyType = POKEMON_TYPE_FIRE;

	case 1:
		_name = L"주황구미";
		_gummyType = POKEMON_TYPE_FIGHTING;

	case 2:
		_name = L"노란구미";
		_gummyType = POKEMON_TYPE_ELECTRIC;

	case 3:
		_name = L"새싹구미";
		_gummyType = POKEMON_TYPE_GRASS;

	case 4:
		_name = L"초록구미";
		_gummyType = POKEMON_TYPE_BUG;

	case 5:
		_name = L"하늘색구미";
		_gummyType = POKEMON_TYPE_FLYING;

	case 6:
		_name = L"파란구미";
		_gummyType = POKEMON_TYPE_WATER;

	case 7:
		_name = L"감색구미";
		_gummyType = POKEMON_TYPE_DRAGON;

	case 8:
		_name = L"보라구미";
		_gummyType = POKEMON_TYPE_GHOST;

	case 9:
		_name = L"분홍구미";
		_gummyType = POKEMON_TYPE_POISON;

	case 10:
		_name = L"검정구미";
		_gummyType = POKEMON_TYPE_DARK;

	case 11:
		_name = L"갈색구미";
		_gummyType = POKEMON_TYPE_GROUND;

	case 12:
		_name = L"하얀구미";
		_gummyType = POKEMON_TYPE_NORMAL;

	case 13:
		_name = L"은색구미";
		_gummyType = POKEMON_TYPE_STEEL;

	case 14:
		_name = L"회색구미";
		_gummyType = POKEMON_TYPE_ROCK;

	case 15:
		_name = L"투명(255.0.255)구미";
		_gummyType = POKEMON_TYPE_ICE;

	case 16:
		_name = L"금색구미";
		_gummyType = POKEMON_TYPE_PSYCHIC;
	}

	//char key[128];
	//WCHAR str[128];
	//
	//for (int i = 0; i < GUMMY_MAX; i++)
	//{
	//	sprintf_s(key, "gummy%d", i);
	//	swprintf_s(str, L"img/item/food/gummy/%d.png", i);
	//	_imGummy[i] = IMAGEMANAGER->addDImage(key, str, ITEMSIZE, ITEMSIZE);
	//}

	return S_OK;
}

void Gummy::release()
{
}

void Gummy::update()
{
}

void Gummy::render()
{
	if (PRINTMANAGER->isDebug())	DTDMANAGER->Rectangle(_body);
	_img->frameRender(_x * TILEWIDTH + TILEWIDTH / 2 - _img->getFrameWidth() / 2,
	_y * TILEHEIGHT + TILEHEIGHT / 2 - _img->getFrameHeight() / 2, _num, 0);
}

void Gummy::eatItem(float value)
{
}