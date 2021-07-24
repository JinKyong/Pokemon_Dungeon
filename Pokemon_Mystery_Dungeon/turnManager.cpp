#include "stdafx.h"
#include "turnManager.h"

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

	else {	//�Է��� ������ ����

		//�� �Ͻ�����
		if (_pause) return;

		playerIter player;

		//�տ������� ���ʴ��
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
	//��� �÷��̾� render
	playerIter player = _allPlayerList.end() - 1;
	for (; player != _allPlayerList.begin(); --player)
		(*player)->render();
	(*player)->render();
}

void turnManager::randomSetting()
{
	vector<RECT>* room = TILEMANAGER->getvRoom();

	playerIter player = _allPlayerList.begin();

	for (; player != _allPlayerList.end();) {
		int index = RND->getInt(room->size());

		float x = RND->getFromIntTo((*room)[index].left, (*room)[index].right);
		float y = RND->getFromIntTo((*room)[index].top, (*room)[index].bottom);

		(*player)->init(x, y);
		++player;
	}

}

void turnManager::inputFromPlayer()
{
	//(���� �Ҹ�Ǵ�)input�� ������ order++
	if (_allPlayerList[_order]->input() != POKEMON_STATE_DEFAULT) {
		addInputPlayer(_allPlayerList[_order]);
		_order++;
	}

	//��� Player input�� ������ ���� ������
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