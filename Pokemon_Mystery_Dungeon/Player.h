#pragma once
#include "Pokemon.h"
#include "KeyNDirect.h"
#include <vector>

class Atile;
class Pattern;

enum PLAYER_TYPE {
	PLAYER_TYPE_USER,
	PLAYER_TYPE_TEAM,
	PLAYER_TYPE_ENEMY,
	END_PLAYER_TYPE
};

enum PLAYER_PATTERN {
	PLAYER_PATTERN_PATHFINDER,
	PLAYER_PATTERN_ONATTACK,
	END_PLAYER_PATTERN
};

class Player
{
protected:
	//�÷��̾� Ÿ�� & ���� & ����(�˰���)
	PLAYER_TYPE _playerType;
	POKEMON_STATE _playerState;

	Pattern* _pattern[END_PLAYER_PATTERN];
	PLAYER_PATTERN _currentPattern = END_PLAYER_PATTERN;

	//�÷��̾� ���ϸ�
	Pokemon* _pokemon;

	//���� & ����ġ
	int _level;
	int _EXP;

	//���� (���� ��)
	STAT _realStat;

	//���(��ų)
	Skill* _selectedSkill;
	Skill* _skill[4];


	//��ǥ
	float _x, _y;
	float _initX, _initY;
	float _destX, _destY;
	int _direct;
	RECT _body;

	//���ѵ���(������)
	//Item _item;

	//�� ����(���� �Ǵ� ����)
	bool _inDungeon;

public:
	virtual HRESULT init(int pokemonNum);
	virtual HRESULT init(float x, float y);
	virtual void release() = 0;
	virtual void update() = 0;
	virtual void render() = 0;

	virtual int input() = 0;

	void changePattern(PLAYER_PATTERN pattern);
	void setDirect();

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

	float getInitX() { return _initX; }
	void setInitX(float initX) { _initX = initX; }
	float getInitY() { return _initY; }
	void setInitY(float initY) { _initY = initY; }

	float getDestX() { return _destX; }
	void setDestX(float destX) { _destX = destX; }
	float getDestY() { return _destY; }
	void setDestY(float destY) { _destY = destY; }

	int getLevel() { return _level; }
	void setLevel(float level) { _level = level; }

	STAT getRealStat() { return _realStat; }
	void setRealStat(STAT realStat) { _realStat = realStat; }

	RECT getBody() { return _body; }

	int getDirect() { return _direct; }

	Skill** getSkill() { return _skill; }
};