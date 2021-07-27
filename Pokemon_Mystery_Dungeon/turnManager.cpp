#include "stdafx.h"
#include "turnManager.h"
#include "Enemy.h"

HRESULT turnManager::init()
{
	_order = 0;
	_input = true;

	_currentProgressTurn = POKEMON_STATE_DEFAULT;
	_pause = false;

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

		//턴 일시정지
		if (_pause) return;

		playerIter player;

		//죽으면 삭제
		player = _allPlayerList.begin();
		for (; player != _allPlayerList.end(); ++player) {
			if ((*player)->getPokemon()->getDeath()) {
				//경험치 획득
				if ((*player)->getPlayerType() == PLAYER_TYPE_ENEMY) {
					int exp = BATTLEMANAGER->EXPCalculation(*player);
					DIALOGMANAGER->addExpLog(_allPlayerList[0], exp);
					_allPlayerList[0]->addEXP(exp);
				}

				_allPlayerList.erase(player);
				break;
			}
		}
		player = _inputPlayerList.begin();
		for (; player != _inputPlayerList.end(); ++player) {
			if ((*player)->getPokemon()->getDeath()) {
				_inputPlayerList.erase(player);
				break;
			}
		}

		//앞에서부터 차례대로
		if ((player = _inputPlayerList.begin()) != _inputPlayerList.end()) {
			_currentProgressTurn = (*player)->getPlayerState();

			for (; player != _inputPlayerList.end();) {
				if ((*player)->getPlayerState() != _currentProgressTurn) break;

				(*player)->update();

				if (_currentProgressTurn == POKEMON_STATE_ATTACK ||
					_currentProgressTurn == POKEMON_STATE_SATTACK)
					break;

				else if (_currentProgressTurn == POKEMON_STATE_DEFAULT) {
					COLLISIONMANAGER->collisionEndTurnPlayer((*player));
					//(*player)->getPokemon()->changeState(POKEMON_STATE_DEFAULT);
					(*player)->resetXY();
					player = _inputPlayerList.erase(player);
				}

				else
					++player;
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

void turnManager::randomSetting()
{
	//에너미 추가
	vector<int> enemyList = TILEMANAGER->getEnemyList();
	int number = RND->getFromIntTo(3, 6);
	int minLevel = TILEMANAGER->getMinLevel();
	int maxLevel = TILEMANAGER->getMaxLevel();

	for (int i = 0; i < number; i++) {
		Player* enemy = new Enemy;
		enemy->init(enemyList[RND->getInt(enemyList.size())], RND->getFromIntTo(minLevel, maxLevel));
		addAllPlayer(enemy);
	}




	//랜덤 배치
	vector<RECT>* room = TILEMANAGER->getvRoom();

	playerIter player = _allPlayerList.begin();

	for (; player != _allPlayerList.end();) {
		int index = RND->getInt(room->size());

		float x = RND->getFromIntTo((*room)[index].left, (*room)[index].right);
		float y = RND->getFromIntTo((*room)[index].top, (*room)[index].bottom);

		(*player)->initXY(x, y);
		++player;
	}

}

void turnManager::inputFromPlayer()
{
	//(턴이 소모되는)input이 있으면 order++
	if (_allPlayerList[_order]->input() != POKEMON_STATE_DEFAULT) {
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