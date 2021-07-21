#pragma once
#include "DownMenu.h"

#define INVENMENU_WIDTH		624
#define INVENMENU_HEIGHT	528

class InvenMenu : public DownMenu
{
private:
	vector<Item*>* _invItem;

public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};