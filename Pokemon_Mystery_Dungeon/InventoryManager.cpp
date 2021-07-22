#include "stdafx.h"
#include "InventoryManager.h"

HRESULT InventoryManager::init()
{
	return S_OK;
}

void InventoryManager::release()	//sceneManager ☆ 참고
{
	itemListIter viItem = _vItem.begin();

	for (; viItem != _vItem.end();)
	{
		viItem = _vItem.erase(viItem);
	}

	_vItem.clear();
}

void InventoryManager::useItem(int index)
{
	//210717 보류
	//아 매니저에요? 네네

	//eat throw 뭐 이런걸 인벤매니저에 하고
	//검사후에 쓰는건 ui쪽에서 하라는거죠? :0
	//o.o)b
	//네 누구거라고 뜨던데
	//근데그거 상세설명에 뜨는거 아니었어요?
	//상세는 안한다시지 않았나
	//ㅇㅎ...... *아이템 bool값
}

void InventoryManager::addItem(Item* itemName)
{
	_vItem.push_back(itemName);
}

void InventoryManager::removeItem(int arrNum)
{
	_vItem.erase(_vItem.begin() + arrNum);
}

void InventoryManager::addItemStorage(Item* itemName)
{
	_vItemStorage.push_back(itemName);
}

void InventoryManager::removeItemStorage(int arrNum)
{
	_vItemStorage.erase(_vItemStorage.begin() + arrNum);
}
