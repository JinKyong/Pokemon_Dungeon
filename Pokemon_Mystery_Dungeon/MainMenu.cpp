#include "stdafx.h"
#include "MainMenu.h"

HRESULT MainMenu::init()
{
	//��� �̹���
	_back = IMAGEMANAGER->addDImage(
		"mainMenu_back", L"img/UI/mainMenu/back.png", MAINMENU_WIDTH, MAINMENU_HEIGHT);
	_border = IMAGEMANAGER->addDImage(
		"mainMenu_border", L"img/UI/mainMenu/border.png", MAINMENU_WIDTH, MAINMENU_HEIGHT);

	//���� ȭ��ǥ
	_arrow = IMAGEMANAGER->addDImage("selectTri", L"img/UI/mainMenu/tri.png", 10, 22);

	_tuningX = 2 * TILEWIDTH / 3;
	_tuningY = TILEHEIGHT / 2;

	_index = 0;

	return S_OK;
}

void MainMenu::release()
{
}

void MainMenu::update()
{
	if (KEYMANAGER->isOnceKeyDown(KEY_DOWN)) {
		_index = (_index + 1) % END_MAINMENU_OPTION;
	}
	else if (KEYMANAGER->isOnceKeyDown(KEY_UP)) {
		_index = (_index - 1 + END_MAINMENU_OPTION) % END_MAINMENU_OPTION;
	}

	if (KEYMANAGER->isOnceKeyDown(KEY_A)) {
		if (_index == MAINMENU_OPTION_SKILL)
			UIMANAGER->changeDownMenu("SkillMenu");
		else if (_index == MAINMENU_OPTION_INVENTORY)
			UIMANAGER->changeDownMenu("invenMenu");
	}

	if (KEYMANAGER->isOnceKeyDown(KEY_B)) {
		UIMANAGER->changeDownMenu("logMenu");
		UIMANAGER->setOpen(false);
	}
}

void MainMenu::render()
{
	DownMenu::render();
	
	//LEFT(�޴� ���)
	printTextLeft();

	//RIGHT(���� �̸�)
	printTextRight();

	//DOWN(���� stat)
	printTextDown();
}

void MainMenu::printTextLeft()
{
	D2D1_RECT_F rc = CAMERAMANAGER->getScreen();

	D2D1_RECT_F dest = dRectMake(rc.left + _tuningX + TILEWIDTH, rc.top + _tuningY + TILEHEIGHT / 2,
		TILEWIDTH * 2, TILEHEIGHT);

	DTDMANAGER->printText(L"���", dest, 25);

	dest.top += TILEHEIGHT;
	dest.bottom += TILEHEIGHT;
	DTDMANAGER->printText(L"����", dest, 25);

	//ȭ��ǥ
	_arrow->render(dest.left - 20, dest.top - 40 + _index * TILEHEIGHT);
}

void MainMenu::printTextRight()
{

}

void MainMenu::printTextDown()
{
}
