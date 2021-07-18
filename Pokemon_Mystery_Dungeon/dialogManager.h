#pragma once
#include "singletonBase.h"

class Player;
class Item;
class Skill;

class dialogManager : public singletonBase<dialogManager>
{
private:
	typedef vector<wstring>				battleLog;
	typedef vector<wstring>::iterator	battleIter;

private:
	//전투 로그가 담기는 vector
	battleLog _battleLog;

public:
	HRESULT init();
	void release();
	void update();
	void render();


	void resetTimer();

	//로그를 추가하는 함수
	void addItemLog(Player* player, Item* item);
	void addExpLog(Player* player, int exp);

	void useSkillLog(Player* player, Skill* skill);
	void failSkillLog();





	battleLog* getBattleLog() { return &_battleLog; }
};

