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
		"invenMenu_border", L"img/UI/invenMenu/border2.png", INVENMENU_WIDTH, INVENMENU_HEIGHT);
	_arrow = IMAGEMANAGER->findDImage("selectTri");

	_invItem = INVENTORYMANAGER->getVItem();

	_index = 0;

	//���Ʒ��� �������� �ε��� +- (������� Ŀ����X 0���� �۾Ƶ� X)
	//������ �ѱ�� +- 8 (*����ó�� �ʼ�)

	return S_OK;
}

void InvenMenu::release()
{
}

void InvenMenu::update()
{
	if (KEYMANAGER->isOnceKeyDown(KEY_B))
	{
		UIMANAGER->changeDownMenu("logMenu");
		UIMANAGER->setOpen(false);
	}
}

void InvenMenu::render()
{
	DownMenu::render();

	vector<Item*>::iterator viInvItem;

	for (viInvItem = (*_invItem).begin(); viInvItem != (*_invItem).end(); ++viInvItem)
	{
		(*viInvItem)->getName();					//string�� c_str
		DTDMANAGER->printText((*viInvItem)->getName().c_str(), CAMERAMANAGER->getScreen());
		//�ڿ���ó��: 
	}
}
