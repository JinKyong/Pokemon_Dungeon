#pragma once
#include "DownMenu.h"

#define INVENMENU_WIDTH		624
#define INVENMENU_HEIGHT	528

enum INVENMENU_OPTION{
	INVENMENU_OPTION_EACH,
	INVENMENU_OPTION_GIVE,
	INVENMENU_OPTION_DUMP,
	INVENMENU_OPTION_INFO,
	INVENMENU_OPTION_BACK,
	END_INVENMENU_OPTION
};

enum INVENMENU_GIVE_OPTION {
	INVENMENU_GIVE_OPTION_GIVE,
	INVENMENU_GIVE_OPTION_DUMP,
	INVENMENU_GIVE_OPTION_INFO,
	INVENMENU_GIVE_OPTION_BACK,
	END_INVENMENU_GIVE_OPTION
};

class InvenMenu : public DownMenu
{
private:
	vector<Item*>* _invItem;
	vector<Item*>::iterator _viInvItem;

	dImage* _back2;
	dImage* _border2;

	dImage* _back3;
	dImage* _border3;

	int _index2;
	bool _opacity;

public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void printTextLeft();
	void printTextRight();
	void printTextRight2();
	void printTextDown();

	void plusIndex();
	void minusIndex();
	void leftIndex();
	void rightIndex();
};