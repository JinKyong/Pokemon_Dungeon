#pragma once
#include "singletonBase.h"
#include "Player.h"
#include <vector>

class turnManager : public singletonBase<turnManager>
{
private:
	typedef vector<Player*>				playerList;
	typedef vector<Player*>::iterator	playerIter;

private:
	playerList _allPlayerList;		//���� ��� �÷��̾�

	playerList _attackPlayerList;	//������ �Է��� �÷��̾�
	playerList _movePlayerList;		//�̵��� �Է��� �÷��̾�

	int _order;
	bool _input;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	void addAllPlayer(Player* player);
	void addAttackPlayer(Player* player);
	void addMovePlayer(Player* player);
};