#include "stdafx.h"
#include "InvenMenu.h"
#include "Item.h"

HRESULT InvenMenu::init()
{
	_back = IMAGEMANAGER->addDImage(
		"mainMenu_back", L"img/UI/mainMenu/back.png", INVENMENU_WIDTH, INVENMENU_HEIGHT);
	_border = IMAGEMANAGER->addDImage(
		"mainMenu_border", L"img/UI/mainMenu/border.png", INVENMENU_WIDTH, INVENMENU_HEIGHT);
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
