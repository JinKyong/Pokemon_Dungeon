#pragma once
#include "DownMenu.h"
//#include "Item.h"

#define INVENMENU_WIDTH		624 * 2
#define INVENMENU_HEIGHT	528 * 2

class Item;

class InvenMenu : public DownMenu
{
private:
	//
	Item* _invenItem;

public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};