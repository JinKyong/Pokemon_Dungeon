#include "stdafx.h"
#include "ItemManager.h"

HRESULT ItemManager::init()
{
	return S_OK;
}

void ItemManager::release()
{
}

void ItemManager::update()
{																//�׻�������ʴ´�
//	for (_viItemAdd = _vItemAdd.begin(); _viItemAdd != _vItemAdd.end();)
//	{
//		//if ((*_viItemAdd)->/*�浹�浹*/)
//		//{
//		//	SAFE_DELETE(*_viItemAdd);
//		//	_viItemAdd = _vItemAdd.erase(_viItemAdd);
//		//}
//		//
//		//else ++_viItemAdd;
//	}
}

void ItemManager::render()
{
	for (_viItemAdd = _vItemAdd.begin(); _viItemAdd != _vItemAdd.end(); ++_viItemAdd)
	{
		(*_viItemAdd)->render();
	}
}

void ItemManager::addItem(Item * item)
{
	_vItemAdd.push_back(item);
}

void ItemManager::removeItem(int num)
{
	_vItemAdd[num]->getImage()->release();
	_vItemAdd.erase(_vItemAdd.begin() + num);
}

