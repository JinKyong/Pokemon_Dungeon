#include "stdafx.h"
#include "turnManager.h"

HRESULT turnManager::init()
{


	return S_OK;
}

void turnManager::release()
{
	playerIter _playerIter = _playerList.begin();

	for (; _playerIter != _playerList.end();)
	{
		if ((*_playerIter))
		{
			(*_playerIter)->release();
			SAFE_DELETE((*_playerIter));
			_playerIter = _playerList.erase(_playerIter);
		}
		else ++_playerIter;
	}

	_playerList.clear();
}

void turnManager::update()
{
}

void turnManager::render()
{
}
