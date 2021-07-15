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
	//�÷��̾� ���ϸ�
	Pokemon* _pokemon;

	//���� ��
	bool _turn;

	//��ǥ
	float _x, _y;
	float _destX, _destY;
	RECT _body;

	//���� & ����ġ
	int _level;
	int _EXP;

	//���� (���� ��)
	STAT _realStat;

	//���(��ų)
	//Skill _skill[4];
	//float _effectX, _effectY; // ����Ʈ ��ǥ�� �ֱ����� ����
	Skill* _testSkill;

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



	//=================== ������ ===================//
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