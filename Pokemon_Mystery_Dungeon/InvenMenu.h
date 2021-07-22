#pragma once
#include "DownMenu.h"

#define INVENMENU_WIDTH		624
#define INVENMENU_HEIGHT	528

enum INVENMENU_OPTION{
	INVENMENU_OPTION_DUMP,
	INVENMENU_OPTION_INFO,
	INVENMENU_OPTION_BACK,
	END_INVENMENU_OPTION
};

class InvenMenu : public DownMenu
{
private:
	vector<Item*>* _invItem;

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