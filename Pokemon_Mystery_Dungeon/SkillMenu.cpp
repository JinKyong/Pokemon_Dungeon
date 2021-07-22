#include "stdafx.h"
#include "SkillMenu.h"
#include "Skill.h"

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
	
	_skill = (*TURNMANAGER->getAllPlayer())[0]->getSkill();

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

	if(_hidden)	printTextRight();

	printTextDown();
}

void SkillMenu::printTextLeft()
{

	D2D1_RECT_F rc = CAMERAMANAGER->getScreen();

	D2D1_RECT_F dest = dRectMake(rc.left + _tuningX + TILEWIDTH, rc.top + _tuningY + TILEHEIGHT + TILEHEIGHT / 2,
		TILEWIDTH * 10, TILEHEIGHT);

	//화살표
	_arrow->render(dest.left - 20, dest.top + 8 + _index * TILEHEIGHT);

	//스킬이 있는지 검사->출력->검사->출력
	
	//왼쪽아닐까요?아니그게아니라 창 생긴 모양대로면요ㄱㅋㄱㅋㅋㅋㅋㅋㅋㅋㅋ 네왼쪽

	//사용하면...... 스킬이 써지겠죠.... 창이꺼지고.. useskill이 쓸 index..
	//헐... qwer이에요...? ㅇㅎ...
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
