#include "stdafx.h"
#include "turnManager.h"

HRESULT turnManager::init()
{
	_order = 0;
	_input = true;

	_currentProgressTurn = POKEMON_STATE_DEFAULT;

	return S_OK;
}

void turnManager::release()
{
	playerIter _playerIter = _allPlayerList.begin();

	for (; _playerIter != _allPlayerList.end();)
	{
		if ((*_playerIter)->getPlayerType() == PLAYER_TYPE_ENEMY) {
			(*_playerIter)->release();
			SAFE_DELETE((*_playerIter));
			_playerIter = _allPlayerList.erase(_playerIter);
		}
		else
			++_playerIter;
	}

	_allPlayerList.clear();
}

void turnManager::update()
{
	if (_input)
		inputFromPlayer();

	else {	//입력이 끝나면 진행

		playerIter player;

		//앞에서부터 차례대로
		if ((player = _inputPlayerList.begin()) != _inputPlayerList.end()) {
			_currentProgressTurn = (*player)->getPlayerState();

			for (; player != _inputPlayerList.end();) {
				if ((*player)->getPlayerState() != _currentProgressTurn) break;

				switch ((*player)->getPlayerState()) {
				case POKEMON_STATE_MOVE:
					(*player)->move();
					(*player)->update();
					++player;
					break;
				case POKEMON_STATE_ATTACK:
				case POKEMON_STATE_SATTACK:
					(*player)->attack();
					(*player)->update();
					//++player;
					return;
				case POKEMON_STATE_DEFAULT:
					player = _inputPlayerList.erase(player);
					break;
				}
			}
		}
		else {
			_order = 0;
			_input = true;
		}
	}
}

void turnManager::render()
{
	//모든 플레이어 render
	playerIter player = _allPlayerList.end() - 1;
	for (; player != _allPlayerList.begin(); --player)
		(*player)->render();
	(*player)->render();
}

void turnManager::inputFromPlayer()
{
	//input 받음
	int state = _allPlayerList[_order]->input();

	//(턴이 소모되는)input이 있으면 order++
	if (state != POKEMON_STATE_DEFAULT) {
		addInputPlayer(_allPlayerList[_order]);
		_order++;
	}

	//모든 Player input을 받으면 진행 턴으로
	if (_order >= _allPlayerList.size())
		_input = false;
}

void turnManager::addAllPlayer(Player * player)
{
	_allPlayerList.push_back(player);
}

void turnManager::addInputPlayer(Player * player)
{
	_inputPlayerList.push_back(player);
}
