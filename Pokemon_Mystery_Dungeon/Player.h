#pragma once
#include "Pokemon.h"
#include "KeyNDirect.h"
#include <vector>

class Atile;

enum PLAYER_TYPE {
	PLAYER_TYPE_USER,
	PLAYER_TYPE_TEAM,
	PLAYER_TYPE_ENEMY,
	END_PLAYER_TYPE
};

class Player
{
protected:
	//�÷��̾� Ÿ�� & ����
	PLAYER_TYPE _playerType;
	POKEMON_STATE _playerState;

	//�÷��̾� ���ϸ�
	Pokemon* _pokemon;

	//��ǥ
	float _x, _y;
	float _initX, _initY;
	float _destX, _destY;
	int _direct;
	RECT _body;

	//���� & ����ġ
	int _level;
	int _EXP;

	//���� (���� ��)
	STAT _realStat;
	int _testHP;

	//���(��ų)
	Skill* _selectedSkill;
	Skill* _skill[4];

	//���ѵ���(������)
	//Item _item;

	//�� ����(���� �Ǵ� ����)
	bool _inDungeon;

	vector<Atile*> _pathList;

public:
	virtual HRESULT init(int pokemonNum);
	virtual HRESULT init(float x, float y);
	virtual void release() = 0;
	virtual void update() = 0;
	virtual void render() = 0;

	virtual int input() = 0;

	void move();
	void attack();
	void sattack();

	void hitDamage(int num);

	//=================== ������ ===================//
	PLAYER_TYPE getPlayerType() { return _playerType; }
	POKEMON_STATE getPlayerState() { return _playerState; }
	void setPlayerState(POKEMON_STATE playerState) { _playerState = playerState; }

	Pokemon* getPokemon() { return _pokemon; }
	void setPokemon(Pokemon* pokemon) { _pokemon = pokemon; }

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

	int getTestHP() { return _testHP; }
	RECT getBody() { return _body; }

	int getDirect() { return _direct; }

	vector<Atile*> getPathList() { return _pathList; }
	void setPathList(vector<Atile*> pathList) { _pathList = pathList; }
};