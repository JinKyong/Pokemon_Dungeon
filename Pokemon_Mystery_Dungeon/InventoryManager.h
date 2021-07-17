#pragma once

class item;

class InventoryManager
{
private:
	typedef vector<item*>			itemList;
	typedef vector<item*>::iterator	itemListIter;

private:
	itemList		_vItem;
	itemListIter	_viItem;

public:
	InventoryManager() {};
	~InventoryManager() {};

	virtual HRESULT init();
	virtual void render();

	void addItem(item* itemName);
	void removeItem();

	void controlKey();
};

