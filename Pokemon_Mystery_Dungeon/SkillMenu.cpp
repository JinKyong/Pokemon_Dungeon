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
	_index2 = 0;
	
	_skill = (*TURNMANAGER->getAllPlayer())[0]->getSkill();

	return S_OK;
}

void SkillMenu::release()
{
}

void SkillMenu::update()
{
	if (KEYMANAGER->isOnceKeyDown(KEY_UP)) minusIndex();
	if (KEYMANAGER->isOnceKeyDown(KEY_DOWN)) plusIndex();

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
			if (_index2 == SKILL_SELECTMENU_OPTION_USE)
			{
				_hidden = false;
				
				if (_index == SKILLMENU_OPTION_FIRST)
				{
					_skill[0]->useSkill();
				}
				else if(_index == SKILLMENU_OPTION_SECOND)
				{
					_skill[1]->useSkill();
				}
				else if(_index == SKILLMENU_OPTION_THIRD)
				{
					_skill[2]->useSkill();
				}
				else if(_index == SKILLMENU_OPTION_FOURTH)
				{
					_skill[3]->useSkill();
				}
			}

			else if (_index2 == SKILL_SELECTMENU_OPTION_INFO) _hidden = false;
			else if (_index2 == SKILL_SELECTMENU_OPTION_BACK) _hidden = false;
		}

		else _hidden = true;
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

	WCHAR str[128];
	swprintf_s(str, L"index : %d", _index);
	DTDMANAGER->printText(str, dRectMake(dest.left, dest.top, 100, 20));
	swprintf_s(str, L"index2 : %d", _index2);
	DTDMANAGER->printText(str, dRectMake(dest.left, dest.top + 40, 100, 20));


	DTDMANAGER->printText((*TURNMANAGER->getAllPlayer())[0]->getPokemon()->getName().c_str(),
		rc.left + _tuningX + TILEWIDTH * 3 + TILEWIDTH / 2 + 15, rc.top + _tuningY + 20 + TILEHEIGHT, 200, 100, 25);

	//화살표
	if (!_hidden) _arrow->render(dest.left - 20, dest.top + _index * TILEHEIGHT);

	DTDMANAGER->printText(_skill[0]->getName().c_str(), dest, 25);

	dest.top += TILEHEIGHT;
	dest.bottom += TILEHEIGHT;

	DTDMANAGER->printText(_skill[1]->getName().c_str(), dest, 25);

	dest.top += TILEHEIGHT;
	dest.bottom += TILEHEIGHT;

	DTDMANAGER->printText(_skill[2]->getName().c_str(), dest, 25);

	dest.top += TILEHEIGHT;
	dest.bottom += TILEHEIGHT;

	DTDMANAGER->printText(_skill[3]->getName().c_str(), dest, 25);

	//스킬이 있는지 검사->출력->검사->출력
}

void SkillMenu::printTextRight()
{
	D2D1_RECT_F rc = CAMERAMANAGER->getScreen();

	_back2->render(rc.left + _tuningX, rc.top + _tuningY, 0.5);
	_border2->render(rc.left + _tuningX, rc.top + _tuningY);
	
	D2D1_RECT_F dest3 = dRectMake(rc.left + _tuningX + TILEWIDTH * 9 + 25, rc.top + _tuningY + 12, TILEWIDTH * 10, TILEHEIGHT);

	DTDMANAGER->printText(L"쓴다", dest3, 25);
	
	dest3.top += 36;
	dest3.bottom += 36;

	DTDMANAGER->printText(L"설명", dest3, 25);

	dest3.top += 36;
	dest3.bottom += 36;

	DTDMANAGER->printText(L"돌아간다", dest3, 25);

	if (_hidden) _arrow->render(dest3.left - 20, (dest3.top + TILEHEIGHT / 2 - TILEHEIGHT * 2) + _index2 * 36);
}

void SkillMenu::printTextDown()
{
}

void SkillMenu::plusIndex()
{
	if (!_hidden)
	{
		_index += 1;
		if (_index > 3) _index = 0;
	}

	if (_hidden)
	{
		_index2 = (_index2 + 1) % END_SKILL_SELECTMENU_OPTION;
	}
	else _index2 = 0;
}

void SkillMenu::minusIndex()
{
	if (!_hidden)
	{
		_index -= 1;
		if (_index < 0) _index = 3;
	}

	if (_hidden)
	{
		_index2 = (_index2 - 1 + END_SKILL_SELECTMENU_OPTION) % END_SKILL_SELECTMENU_OPTION;
	}
	else _index2 = 0;
}
