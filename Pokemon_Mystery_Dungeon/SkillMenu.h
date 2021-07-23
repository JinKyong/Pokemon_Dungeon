#pragma once
#include "DownMenu.h"

#define SKILLMENU_WIDTH		624
#define SKILLMENU_HEIGHT	528

enum SKILLMENU_OPTION {
	SKILLMENU_OPTION_FIRST,
	SKILLMENU_OPTION_SECOND,
	SKILLMENU_OPTION_THIRD,
	//SKILLMENU_OPTION_FOURTH,
	END_SKILLMENU_OPTION
};

class SkillMenu : public DownMenu
{
private:
	Skill** _skill;

	dImage* _back2;
	dImage* _border2;

	int _index2;

public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void printTextLeft();
	void printTextRight();
	void printTextDown();

	void plusIndex();
	void minusIndex();
};

