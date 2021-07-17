#pragma once
#include "DownMenu.h"

#define SKILLMENU_WIDTH		624
#define SKILLMENU_HEIGHT	528

enum SKILLMENU_OPTION {
	SKILLMENU_OPTION_FIRST,
	SKILLMENU_OPTION_SECOND,
	SKILLMENU_OPTION_THIRD,
	SKILLMENU_OPTION_FOURTH,
	END_MAINMENU_OPTION
};

class SkillMenu : public DownMenu
{
private:

public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

