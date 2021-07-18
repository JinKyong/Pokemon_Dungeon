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
	case 0: //�̵� �̳ѹ�����....
		_name = L"��������";
		_gummyType = POKEMON_TYPE_FIRE;

	case 1:
		_name = L"��Ȳ����";
		_gummyType = POKEMON_TYPE_FIGHTING;

	case 2:
		_name = L"�������";
		_gummyType = POKEMON_TYPE_ELECTRIC;

	case 3:
		_name = L"���ϱ���";
		_gummyType = POKEMON_TYPE_GRASS;

	case 4:
		_name = L"�ʷϱ���";
		_gummyType = POKEMON_TYPE_BUG;

	case 5:
		_name = L"�ϴû�����";
		_gummyType = POKEMON_TYPE_FLYING;

	case 6:
		_name = L"�Ķ�����";
		_gummyType = POKEMON_TYPE_WATER;

	case 7:
		_name = L"��������";
		_gummyType = POKEMON_TYPE_DRAGON;

	case 8:
		_name = L"���󱸹�";
		_gummyType = POKEMON_TYPE_GHOST;

	case 9:
		_name = L"��ȫ����";
		_gummyType = POKEMON_TYPE_POISON;

	case 10:
		_name = L"��������";
		_gummyType = POKEMON_TYPE_DARK;

	case 11:
		_name = L"��������";
		_gummyType = POKEMON_TYPE_GROUND;

	case 12:
		_name = L"�Ͼᱸ��";
		_gummyType = POKEMON_TYPE_NORMAL;

	case 13:
		_name = L"��������";
		_gummyType = POKEMON_TYPE_STEEL;

	case 14:
		_name = L"ȸ������";
		_gummyType = POKEMON_TYPE_ROCK;

	case 15:
		_name = L"����(255.0.255)����";
		_gummyType = POKEMON_TYPE_ICE;

	case 16:
		_name = L"�ݻ�����";
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