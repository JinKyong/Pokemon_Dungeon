#pragma once
#include "DownMenu.h"

#define MAINMENU_WIDTH	624
#define MAINMENU_HEIGHT	528

enum MAINMENU_OPTION {
	MAINMENU_OPTION_SKILL,
	MAINMENU_OPTION_INVENTORY,
	END_MAINMENU_OPTION
};

class MainMenu : public DownMenu
{
private:

public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void printTextLeft();
	void printTextRight();
	void printTextDown();
};
