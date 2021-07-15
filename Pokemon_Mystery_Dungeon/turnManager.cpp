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
		//��ǲ ����
		int state = _allPlayerList[_order]->input();

		//�̵� input
		if (state == POKEMON_STATE_MOVE) {
			addMovePlayer(_allPlayerList[_order]);
			_order++;
		}
		//����(Ư������ ����) input
		else if (state == POKEMON_STATE_ATTACK || state == POKEMON_STATE_SATTACK) {
			addAttackPlayer(_allPlayerList[_order]);
			_order++;
		}

		//���� �Ҹ�Ǵ� �Է��� �޾����� ���� �Է� ����
		if (_order >= _allPlayerList.size())
			_input = false;
	}

	else {	//�Է��� ������ ����

		playerIter player;

		//���� 
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

		//�̵�
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

		//����, �̵��� ��� ������ �ٽ� �Է������� ���ư�
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
