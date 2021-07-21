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
	playerList _allPlayerList;		//현재 모든 플레이어
	playerList _inputPlayerList;	//입력이 끝난 플레이어

	//input
	int _order;
	bool _input;

	//progress
	POKEMON_STATE _currentProgressTurn;
	bool _pause;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	void randomSetting();


	//입력
	void inputFromPlayer();

	void addAllPlayer(Player* player);
	void addInputPlayer(Player* player);




	playerList& getAllPlayer() { return _allPlayerList; }
	Player* getCurrentPlayer() { return _inputPlayerList[0]; }

	bool getPause() { return _pause; }
	void setPause(bool pause) { _pause = pause; }
};