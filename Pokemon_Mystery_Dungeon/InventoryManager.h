#pragma once
#include "singletonBase.h"

class item;

class InventoryManager : public singletonBase<InventoryManager>
{
private:
	typedef vector<item*>			itemList;
	typedef vector<item*>::iterator	itemListIter; 

private:
	itemList		_vItem;
	itemList		_vItemStorage;

public:
	InventoryManager() {};
	~InventoryManager() {};

	virtual HRESULT init();
	void release();

	void useItem(int num);

	void addItem(item* itemName);
	void removeItem(int arrNum);

	void addItemStorage(item* itemName);
	void removeItemStorage(int arrNum);

	//get
	//*인벤토리 벡터 겟함수 추가하기
};