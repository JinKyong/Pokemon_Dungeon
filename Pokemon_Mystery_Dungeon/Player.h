#pragma once
#include "Pokemon.h"
#include "SkillManager.h"

class Player
{
private:
	Pokemon* _pokemon;

	//좌표
	float _x, _y;
	RECT _body;

	//레벨 & 경험치
	int _level;
	int _EXP;

	//스탯 (실제 값)
	int _hp;
	int _attack;
	int _defense;
	int _sattack;
	int _sdefense;
	int _speed;

	//기술(스킬)
	//Skill _skill[4];
	SkillManager* _sm;
	float _effectX, _effectY; // 이펙트 좌표값 주기위한 변수
	int _skillNum;

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



	Pokemon* getPokemon() { return _pokemon; }
	void setPokemon(Pokemon* pokemon) { _pokemon = pokemon; }

	float getX() { return _x; }
	void setX(float x) { _x = x; }
	float getY() { return _y; }
	void setY(float y) { _y = y; }
};