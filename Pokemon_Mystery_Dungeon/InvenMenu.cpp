#include "stdafx.h"
#include "InvenMenu.h"
#include "Item.h"

HRESULT InvenMenu::init()
{
	_back = IMAGEMANAGER->addDImage("invenMenu_back", L"img/UI/invenMenu/back1.png", INVENMENU_WIDTH, INVENMENU_HEIGHT);
	_back2 = IMAGEMANAGER->addDImage("invenMenu_back2", L"img/UI/invenMenu/back2.png", INVENMENU_WIDTH, INVENMENU_HEIGHT);
	_back3 = IMAGEMANAGER->addDImage("invenMenu_back3", L"img/UI/invenMenu/back3.png", INVENMENU_WIDTH, INVENMENU_HEIGHT);

	_border = IMAGEMANAGER->addDImage("invenMenu_border", L"img/UI/invenMenu/border1.png", INVENMENU_WIDTH, INVENMENU_HEIGHT);
	_border2 = IMAGEMANAGER->addDImage("invenMenu_border2", L"img/UI/invenMenu/border2.png", INVENMENU_WIDTH, INVENMENU_HEIGHT);
	_border3 = IMAGEMANAGER->addDImage("invenMenu_border3", L"img/UI/invenMenu/border3.png", INVENMENU_WIDTH, INVENMENU_HEIGHT);

	_arrow = IMAGEMANAGER->findDImage("selectTri");

	_invItem = INVENTORYMANAGER->getVItem();

	_tuningX = 2 * TILEWIDTH / 3;
	_tuningY = TILEHEIGHT / 2;

	_index = 0;
	_index2 = 0;

	_count = 0;

	return S_OK;
}

void InvenMenu::release()
{
}

void InvenMenu::update()
{
	if (KEYMANAGER->isOnceKeyDown(KEY_UP)) minusIndex();
	if (KEYMANAGER->isOnceKeyDown(KEY_DOWN)) plusIndex();
	//if (KEYMANAGER->isOnceKeyDown(KEY_LEFT)) leftIndex();
	//if (KEYMANAGER->isOnceKeyDown(KEY_RIGHT)) rightIndex();

	if (KEYMANAGER->isOnceKeyDown(KEY_B))
	{
		if (_hidden) _hidden = false;
		else
		{
			UIMANAGER->changeDownMenu("logMenu");
			UIMANAGER->setOpen(false);
		}
	}

	if (KEYMANAGER->isOnceKeyDown(KEY_A))
	{
		if (_hidden)
		{
			if ((*_invItem)[_index]->getType() == ITEM_HOLD)
			{
				if (_index2 == INVENMENU_GIVE_OPTION_BACK) _hidden = false;
			}
			else
			{
				if (_index2 == INVENMENU_OPTION_BACK) _hidden = false;
			}
		}

		else _hidden = true;
	}

	_count++;
	if (_count > 20) {
		_opacity = !_opacity;
		_count = 0;
	}
}

void InvenMenu::render()
{
	DownMenu::render();

	if((*_invItem).size() > 0) printTextLeft();

	if (_hidden)
	{
		if ((*_invItem)[_index]->getType() == ITEM_HOLD)
		{
			printTextRight2();
			if (_index2 == INVENMENU_GIVE_OPTION_INFO) printTextDown();
		}

		else
		{
			printTextRight();
			if (_index2 == INVENMENU_OPTION_INFO) printTextDown();
		}
	}
}

void InvenMenu::printTextLeft()
{
	D2D1_RECT_F rc = CAMERAMANAGER->getScreen();
	D2D1_RECT_F dest = dRectMake(rc.left + _tuningX + TILEWIDTH, rc.top + _tuningY + TILEHEIGHT + TILEHEIGHT / 2,
		TILEWIDTH * 10, TILEHEIGHT);

	//ȭ��ǥ
	if(!_hidden) _arrow->render(dest.left - 20, dest.top + _index * TILEHEIGHT, _opacity);

	for (_viInvItem = _invItem->begin(); _viInvItem != _invItem->end(); ++_viInvItem)
	{
		(*_viInvItem)->getName();
											//string�� c_str
		DTDMANAGER->printText((*_viInvItem)->getName().c_str(), dest, 25);

		dest.top += TILEHEIGHT;
		dest.bottom += TILEHEIGHT;

		//if (_invItem->size() % 7 == 0) DTDMANAGER->printText((*_viInvItem)->getName().c_str(), dest, 25);
	}
}

void InvenMenu::printTextRight()
{
	D2D1_RECT_F rc = CAMERAMANAGER->getScreen();
	D2D1_RECT_F dest3 = dRectMake(rc.left + _tuningX + TILEWIDTH * 9 + 25, rc.top + _tuningY + 12,
		TILEWIDTH * 10, TILEHEIGHT);

	_back2->render(rc.left + _tuningX, rc.top + _tuningY, 0.5);
	_border2->render(rc.left + _tuningX, rc.top + _tuningY);

	if ((*_invItem)[_index]->getType() == ITEM_FOOD) DTDMANAGER->printText(L"�Դ´�", dest3, 25);
	else if ((*_invItem)[_index]->getType() == ITEM_THROW) DTDMANAGER->printText(L"���", dest3, 25);

	dest3.top += 36;
	dest3.bottom += 36;

	DTDMANAGER->printText(L"�ǳ��ش�", dest3, 25);

	dest3.top += 36;
	dest3.bottom += 36;

	DTDMANAGER->printText(L"������", dest3, 25);

	dest3.top += 36;
	dest3.bottom += 36;
	DTDMANAGER->printText(L"����", dest3, 25);

	dest3.top += 36;
	dest3.bottom += 36;
	DTDMANAGER->printText(L"���ư���", dest3, 25);

	if (_hidden) _arrow->render(dest3.left - 20, (dest3.top - TILEHEIGHT * 3) + _index2 * 36);
}

void InvenMenu::printTextRight2()
{
	D2D1_RECT_F rc = CAMERAMANAGER->getScreen();
	D2D1_RECT_F dest3 = dRectMake(rc.left + _tuningX + TILEWIDTH * 9 + 25, rc.top + _tuningY + 12,
		TILEWIDTH * 10, TILEHEIGHT);

	_back3->render(rc.left + _tuningX, rc.top + _tuningY, 0.5);
	_border3->render(rc.left + _tuningX, rc.top + _tuningY);	

	DTDMANAGER->printText(L"�ǳ��ش�", dest3, 25);

	dest3.top += 36;
	dest3.bottom += 36;
	DTDMANAGER->printText(L"������", dest3, 25);

	dest3.top += 36;
	dest3.bottom += 36;
	DTDMANAGER->printText(L"����", dest3, 25);

	dest3.top += 36;
	dest3.bottom += 36;
	DTDMANAGER->printText(L"���ư���", dest3, 25);

	if (_hidden) _arrow->render(dest3.left - 20, (dest3.top - 10 - TILEHEIGHT * 2) + _index2 * 36);
}

void InvenMenu::printTextDown()
{
	D2D1_RECT_F rc = CAMERAMANAGER->getScreen();
	D2D1_RECT_F dest2 = dRectMake(rc.left + _tuningX + TILEWIDTH / 2, rc.top + _tuningY + TILEHEIGHT * 9,
		TILEWIDTH * 10, TILEHEIGHT);

	//�����ۼ���
	DTDMANAGER->printText((*_invItem)[_index]->getItemInfo().c_str(), dest2, 25);
}

void InvenMenu::plusIndex()
{
	if (_invItem->size() > 0 && (!_hidden))
	{
		_index = (_index + 1) % _invItem->size();
	}

	if (_hidden)
	{
		if ((*_invItem)[_index]->getType() == ITEM_HOLD) _index2 = (_index2 + 1) % END_INVENMENU_GIVE_OPTION;
		else _index2 = (_index2 + 1) % END_INVENMENU_OPTION;
	}
	else _index2 = 0;
}

void InvenMenu::minusIndex()
{
	if (_invItem->size() > 0 && (!_hidden))
	{
		_index = (_index - 1 + _invItem->size()) % _invItem->size();
	}

	if (_hidden)
	{
		if ((*_invItem)[_index]->getType() == ITEM_HOLD) _index2 = (_index2 - 1 + END_INVENMENU_GIVE_OPTION) % END_INVENMENU_GIVE_OPTION;
		else _index2 = (_index2 - 1 + END_INVENMENU_OPTION) % END_INVENMENU_OPTION;
	}
	else _index2 = 0;
}

void InvenMenu::leftIndex()
{
	if (_invItem->size() > 0 && (!_hidden))
	{
		//_index = (_index - 7 + _invItem->size()) % _invItem->size();
		_index -= 7;

		if (_index < 0) _index = 0;
	}
}

void InvenMenu::rightIndex()
{
	if (_invItem->size() > 0 && (!_hidden))
	{
		//_index = (_index + 7) % _invItem->size();
		_index += 7;

		if (_invItem->size() < _index) _index = 0;
	}
}
