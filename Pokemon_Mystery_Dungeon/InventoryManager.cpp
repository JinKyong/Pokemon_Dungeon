#include "stdafx.h"
#include "InventoryManager.h"

HRESULT InventoryManager::init()
{
	return S_OK;
}

void InventoryManager::addItem(item* itemName)
{
	_vItem.push_back(itemName);
}

void InventoryManager::controlKey()
{
}
