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
	playerList _inputPlayerList;	//�Է��� ���� �÷��̾�

	//input
	int _order;
	bool _input;

	//progress
	POKEMON_STATE _currentProgressTurn;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	void inputFromPlayer();

	void addAllPlayer(Player* player);
	void addInputPlayer(Player* player);


	playerList* getAllPlayer() { return &_allPlayerList; }
};