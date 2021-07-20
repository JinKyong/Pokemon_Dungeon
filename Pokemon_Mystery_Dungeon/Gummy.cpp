#include "stdafx.h"
#include "Gummy.h"

HRESULT Gummy::init(float x, float y, float angle)
{
	_img = IMAGEMANAGER->addFrameDImage("gummy", L"img/item/food/gummy/0.png", 544, ITEMSIZE, 17, 1);
	_x = x;
	_y = y;
	_body = RectMakeCenter(x * TILEWIDTH + TILEWIDTH / 2, y * TILEHEIGHT + TILEHEIGHT / 2, ITEMSIZE, ITEMSIZE);

	_gummyNum = RND->getInt(END_POKEMON_TYPE);

	_itemInfo = L"������ �ö󰣴�";
	_type = ITEM_FOOD;

	switch (_gummyNum)
	{
	case POKEMON_TYPE_FIRE:
		_name = L"��������";
		_gummyType = POKEMON_TYPE_FIRE;

		_num = 2;

	case POKEMON_TYPE_FIGHTING:
		_name = L"��Ȳ����";
		_gummyType = POKEMON_TYPE_FIGHTING;

		_num = 3;

	case POKEMON_TYPE_ELECTRIC:
		_name = L"�������";
		_gummyType = POKEMON_TYPE_ELECTRIC;

		_num = 4;

	case POKEMON_TYPE_GRASS:
		_name = L"���ϱ���";
		_gummyType = POKEMON_TYPE_GRASS;

		_num = 5;

	case POKEMON_TYPE_BUG:
		_name = L"�ʷϱ���";
		_gummyType = POKEMON_TYPE_BUG;

		_num = 6;

	case POKEMON_TYPE_FLYING:
		_name = L"�ϴû�����";
		_gummyType = POKEMON_TYPE_FLYING;

		_num = 7;

	case POKEMON_TYPE_WATER:
		_name = L"�Ķ�����";
		_gummyType = POKEMON_TYPE_WATER;

		_num = 8;

	case POKEMON_TYPE_DRAGON:
		_name = L"��������";
		_gummyType = POKEMON_TYPE_DRAGON;

		_num = 9;

	case POKEMON_TYPE_GHOST:
		_name = L"���󱸹�";
		_gummyType = POKEMON_TYPE_GHOST;

		_num = 10;

	case POKEMON_TYPE_POISON:
		_name = L"��ȫ����";
		_gummyType = POKEMON_TYPE_POISON;

		_num = 11;

	case POKEMON_TYPE_DARK:
		_name = L"��������";
		_gummyType = POKEMON_TYPE_DARK;

		_num = 12;

	case POKEMON_TYPE_GROUND:
		_name = L"��������";
		_gummyType = POKEMON_TYPE_GROUND;

		_num = 13;

	case POKEMON_TYPE_NORMAL:
		_name = L"�Ͼᱸ��";
		_gummyType = POKEMON_TYPE_NORMAL;
		_itemInfoLong = L"������ ������� �ణ ȸ���ȴ�\n Ž����� ���ῡ�� �ָ�\n ������ �ö󰣴�\n �븻Ÿ�� ���ϸ���\n �����ϴ� �����̴�\n ���� �ȿ��� �Դ°���\n ���� �� �����ϴ�!";

		_num = 14;

	case POKEMON_TYPE_STEEL:
		_name = L"��������";
		_gummyType = POKEMON_TYPE_STEEL;

		_num = 15;

	case POKEMON_TYPE_ROCK:
		_name = L"ȸ������";
		_gummyType = POKEMON_TYPE_ROCK;

		_num = 16;

	case POKEMON_TYPE_ICE:
		_name = L"����(255.0.255)����";
		_gummyType = POKEMON_TYPE_ICE;

		_num = 17;

	case POKEMON_TYPE_PSYCHIC:
		_name = L"�ݻ�����";
		_gummyType = POKEMON_TYPE_PSYCHIC;

		_num = 18;
	}

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
	_y * TILEHEIGHT + TILEHEIGHT / 2 - _img->getFrameHeight() / 2, _gummyNum, 0);
}

void Gummy::eatItem(float value)
{
}