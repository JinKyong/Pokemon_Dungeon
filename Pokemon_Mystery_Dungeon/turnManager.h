#pragma once
#include "singletonBase.h"
#include "Player.h"
#include <vector>

class ItemManager;

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
	bool _pause;

	ItemManager* _im;
public:
	HRESULT init();
	HRESULT init(ItemManager* im);
	void release();
	void update();
	void render();

	void randomSetting();
	void randomAddEnemy();


	//�Է�
	void inputFromPlayer();

	void addAllPlayer(Player* player);
	void addInputPlayer(Player* player);

	Player* getCurrentPlayer();




	playerList* getAllPlayer() { return &_allPlayerList; }

	bool getPause() { return _pause; }
	void setPause(bool pause) { _pause = pause; }
};