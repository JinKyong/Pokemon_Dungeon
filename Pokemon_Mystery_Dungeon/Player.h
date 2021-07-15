#pragma once
#include "Pokemon.h"

enum PLAYER_TYPE {
	PLAYER_TYPE_USER,
	PLAYER_TYPE_TEAM,
	PLAYER_TYPE_ENEMY,
	END_PLAYER_TYPE
};

class Player
{
private:
	//플레이어 포켓몬
	Pokemon* _pokemon;

	//현재 턴
	bool _turn;

	//좌표
	float _x, _y;
	float _destX, _destY;
	RECT _body;

	//레벨 & 경험치
	int _level;
	int _EXP;

	//스탯 (실제 값)
	STAT _realStat;

	//기술(스킬)
	//Skill _skill[4];
	//float _effectX, _effectY; // 이펙트 좌표값 주기위한 변수
	Skill* _testSkill;

	//지닌도구(아이템)
	//Item _item;

	//맵 상태(마을 또는 던전)
	bool _inDungeon;


public:
	HRESULT init();
	void release();
	void update();
	void render();

	void controlKey();
	void testKey();



	//=================== 접근자 ===================//
	Pokemon* getPokemon() { return _pokemon; }
	void setPokemon(Pokemon* pokemon) { _pokemon = pokemon; }

	bool getTurn() { return _turn; }
	void setTurn(bool turn) { _turn = turn; }

	float getX() { return _x; }
	void setX(float x) { _x = x; }
	float getY() { return _y; }
	void setY(float y) { _y = y; }

	float getDestX() { return _destX; }
	void setDestX(float destX) { _destX = destX; }
	float getDestY() { return _destY; }
	void setDestY(float destY) { _destY = destY; }

	int getLevel() { return _level; }
	void setLevel(float level) { _level = level; }

	STAT getRealStat() { return _realStat; }
	void setRealStat(STAT realStat) { _realStat = realStat; }
};