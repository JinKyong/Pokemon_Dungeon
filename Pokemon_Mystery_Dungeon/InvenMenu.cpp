#include "stdafx.h"
#include "InvenMenu.h"
#include "Item.h"

HRESULT InvenMenu::init()
{
	_back = IMAGEMANAGER->addDImage(
		"invenMenu_back", L"img/UI/invenMenu/back1.png", INVENMENU_WIDTH, INVENMENU_HEIGHT);
	_back2 = IMAGEMANAGER->addDImage(
		"invenMenu_back2", L"img/UI/invenMenu/back2.png", INVENMENU_WIDTH, INVENMENU_HEIGHT);
	_border = IMAGEMANAGER->addDImage(
		"invenMenu_border", L"img/UI/invenMenu/border1.png", INVENMENU_WIDTH, INVENMENU_HEIGHT);
	_border2 = IMAGEMANAGER->addDImage(
		"invenMenu_border2", L"img/UI/invenMenu/border2.png", INVENMENU_WIDTH, INVENMENU_HEIGHT);
	_arrow = IMAGEMANAGER->findDImage("selectTri");

	_invItem = INVENTORYMANAGER->getVItem();

	_tuningX = 2 * TILEWIDTH / 3;
	_tuningY = TILEHEIGHT / 2;

	_index = 0;
	_index2 = 0;

	//위아래로 갈때마다 인덱스 +- (사이즈보다 커져도X 0보다 작아도 X)
	//옆으로 넘기면 +- 8 (*예외처리 필수)
	// if 인벤토리아이템 벡터사이즈 < 8이면 키 안먹게

	return S_OK;
}

void InvenMenu::release()
{
}

void InvenMenu::update()
{
	if (KEYMANAGER->isOnceKeyDown(KEY_UP)) minusIndex();
	if (KEYMANAGER->isOnceKeyDown(KEY_DOWN)) plusIndex();

	if (KEYMANAGER->isOnceKeyDown(KEY_B))
	{
		UIMANAGER->changeDownMenu("logMenu");
		UIMANAGER->setOpen(false);
	}

	if (KEYMANAGER->isOnceKeyDown(KEY_A))
	{
		_hidden = true;
	}
}

void InvenMenu::render()
{
	DownMenu::render();

	//LEFT(메뉴 목록)
	if((*_invItem).size() > 0) printTextLeft();

	if (_hidden) printTextRight();

	printTextDown();
}

void InvenMenu::printTextLeft()
{
	D2D1_RECT_F rc = CAMERAMANAGER->getScreen();

	D2D1_RECT_F dest = dRectMake(rc.left + _tuningX + TILEWIDTH, rc.top + _tuningY + TILEHEIGHT + TILEHEIGHT / 2,
		TILEWIDTH * 10, TILEHEIGHT);

	//DTDMANAGER->printText(L"트레저백", dest, 25);

	//화살표
	if(!_hidden) _arrow->render(dest.left - 20, dest.top + 8 + _index * TILEHEIGHT);

	vector<Item*>::iterator viInvItem;
	for (viInvItem = _invItem->begin(); viInvItem != _invItem->end(); ++viInvItem)
	{
		(*viInvItem)->getName();
											//string은 c_str
		DTDMANAGER->printText((*viInvItem)->getName().c_str(), dest, 25);

		dest.top += TILEHEIGHT;
		dest.bottom += TILEHEIGHT;
	}
}

void InvenMenu::printTextRight()
{
	D2D1_RECT_F rc = CAMERAMANAGER->getScreen();

	_back2->render(rc.left + _tuningX, rc.top + _tuningY, 0.5);
	_border2->render(rc.left + _tuningX, rc.top + _tuningY);

	D2D1_RECT_F dest3 = dRectMake(rc.left + _tuningX + TILEWIDTH * 9 + 10, rc.top + _tuningY + 12,
		TILEWIDTH * 10, TILEHEIGHT);

	DTDMANAGER->printText(L"버린다", dest3, 25);

	dest3.top += 36;
	dest3.bottom += 36;
	DTDMANAGER->printText(L"설명", dest3, 25);

	dest3.top += 36;
	dest3.bottom += 36;
	DTDMANAGER->printText(L"돌아간다", dest3, 25);

	if (_hidden) _arrow->render(dest3.left - 20, dest3.top + _index2 * 36);
}

void InvenMenu::printTextDown()
{
	D2D1_RECT_F rc = CAMERAMANAGER->getScreen();
	D2D1_RECT_F dest2 = dRectMake(rc.left + _tuningX + TILEWIDTH / 2, rc.top + _tuningY + TILEHEIGHT * 9,
		TILEWIDTH * 10, TILEHEIGHT);

	//아이템설명
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
		_index2 = (_index2 + 1) % END_INVENMENU_OPTION;
	}
}

void InvenMenu::minusIndex()
{
	if (_invItem->size() > 0 && (!_hidden))
	{
		_index = (_index - 1 + _invItem->size()) % _invItem->size();
	}

	if (_hidden)
	{
		_index2 = (_index2 - 1 + END_INVENMENU_OPTION) % END_INVENMENU_OPTION;
	}
}
