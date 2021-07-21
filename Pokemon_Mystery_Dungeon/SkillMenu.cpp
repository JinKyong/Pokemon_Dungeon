#include "stdafx.h"
#include "SkillMenu.h"

HRESULT SkillMenu::init()
{
	_back = IMAGEMANAGER->addDImage(
		"skillMenu_back", L"img/UI/skillMenu/back1.png", SKILLMENU_WIDTH, SKILLMENU_HEIGHT);
	_back2 = IMAGEMANAGER->addDImage(
		"skillMenu_back2", L"img/UI/skillMenu/back2.png", SKILLMENU_WIDTH, SKILLMENU_HEIGHT);
	_border = IMAGEMANAGER->addDImage(
		"skillMenu_border", L"img/UI/skillMenu/border1.png", SKILLMENU_WIDTH, SKILLMENU_HEIGHT);
	_border2 = IMAGEMANAGER->addDImage(
		"skillMenu_border2", L"img/UI/skillMenu/border2.png", SKILLMENU_WIDTH, SKILLMENU_HEIGHT);
	_arrow = IMAGEMANAGER->findDImage("selectTri");

	_tuningX = 2 * TILEWIDTH / 3;
	_tuningY = TILEHEIGHT / 2;

	_index = 0;

	return S_OK;
}

void SkillMenu::release()
{
}

void SkillMenu::update()
{
	//if (KEYMANAGER->isOnceKeyDown(KEY_UP)) minusIndex();
	//if (KEYMANAGER->isOnceKeyDown(KEY_DOWN)) plusIndex();

	if (KEYMANAGER->isOnceKeyDown(KEY_B))
	{
		UIMANAGER->changeDownMenu("logMenu");
		UIMANAGER->setOpen(false);
	}
}

void SkillMenu::render()
{
	DownMenu::render();

	printTextLeft();

	printTextRight();

	printTextDown();
}

void SkillMenu::printTextLeft()
{

	D2D1_RECT_F rc = CAMERAMANAGER->getScreen();

	D2D1_RECT_F dest = dRectMake(rc.left + _tuningX + TILEWIDTH, rc.top + _tuningY + TILEHEIGHT + TILEHEIGHT / 2,
		TILEWIDTH * 10, TILEHEIGHT);

	//È­»ìÇ¥
	_arrow->render(dest.left - 20, dest.top + 8 + _index * TILEHEIGHT);

}

void SkillMenu::printTextRight()
{
	D2D1_RECT_F screen = CAMERAMANAGER->getScreen();

	_back2->render(screen.left + _tuningX, screen.top + _tuningY, 0.5);
	_border2->render(screen.left + _tuningX, screen.top + _tuningY);
}

void SkillMenu::printTextDown()
{
}

void SkillMenu::plusIndex()
{
}

void SkillMenu::minusIndex()
{
}
