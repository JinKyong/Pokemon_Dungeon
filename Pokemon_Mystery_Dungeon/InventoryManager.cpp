#include "stdafx.h"
#include "InventoryManager.h"

HRESULT InventoryManager::init()
{
	return S_OK;
}

void InventoryManager::release()
{
	//sceneManager ☆ 참고
}

void InventoryManager::useItem(int num)
{
	//210717 보류
}

void InventoryManager::addItem(item* itemName)
{
	_vItem.push_back(itemName);
}

void InventoryManager::removeItem(int arrNum)
{
	_vItem.erase(_vItem.begin() + arrNum);
}

void InventoryManager::addItemStorage(item * itemName)
{
	_vItemStorage.push_back(itemName);
}

void InventoryManager::removeItemStorage(int arrNum)
{
	_vItemStorage.erase(_vItemStorage.begin() + arrNum);
}
