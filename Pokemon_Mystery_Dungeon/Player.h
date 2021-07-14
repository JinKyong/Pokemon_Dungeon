#pragma once
#include "Pokemon.h"
#include "SkillManager.h"

class Player
{
private:
	Pokemon* _pokemon;

	//��ǥ
	float _x, _y;
	RECT _body;

	//���� & ����ġ
	int _level;
	int _EXP;

	//���� (���� ��)
	int _hp;
	int _attack;
	int _defense;
	int _sattack;
	int _sdefense;
	int _speed;

	//���(��ų)
	//Skill _skill[4];
	SkillManager* _sm;
	float _effectX, _effectY; // ����Ʈ ��ǥ�� �ֱ����� ����
	int _skillNum;

	//���ѵ���(������)
	//Item _item;

	//�� ����(���� �Ǵ� ����)
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