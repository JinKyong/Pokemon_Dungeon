#include "stdafx.h"
#include "turnManager.h"

HRESULT turnManager::init()
{
	_order = 0;
	_input = true;

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

	_attackPlayerList.clear();
}

void turnManager::update()
{
	if (_input) {
		//인풋 받음
		int state = _allPlayerList[_order]->input();

		//이동 input
		if (state == POKEMON_STATE_MOVE) {
			addMovePlayer(_allPlayerList[_order]);
			_order++;
		}
		//공격(특수공격 포함) input
		else if (state == POKEMON_STATE_ATTACK || state == POKEMON_STATE_SATTACK) {
			addAttackPlayer(_allPlayerList[_order]);
			_order++;
		}

		//턴이 소모되는 입력을 받았으면 다음 입력 받음
		if (_order >= _allPlayerList.size())
			_input = false;
	}

	else {	//입력이 끝나면 진행

		playerIter player;

		//공격 
		if ((player = _attackPlayerList.begin()) != _attackPlayerList.end()) {
			if ((*player)->getPokemon()->getState() == POKEMON_STATE_DEFAULT) {
				(*player)->setPlayerState(POKEMON_STATE_DEFAULT);
				_attackPlayerList.erase(player);
			}
			else {
				(*player)->attack();
				(*player)->update();
			}
		}

		//이동
		else if ((player = _movePlayerList.begin()) != _movePlayerList.end()) {
			for (; player != _movePlayerList.end();) {
				if ((*player)->getPlayerState() == POKEMON_STATE_DEFAULT)
					player = _movePlayerList.erase(player);
				else {
					(*player)->move();
					(*player)->update();
					++player;
				}
			}
		}

		//공격, 이동이 모두 끝나면 다시 입력턴으로 돌아감
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

void turnManager::addAllPlayer(Player * player)
{
	_allPlayerList.push_back(player);
}

void turnManager::addAttackPlayer(Player * player)
{
	_attackPlayerList.push_back(player);
}

void turnManager::addMovePlayer(Player * player)
{
	_movePlayerList.push_back(player);
}
