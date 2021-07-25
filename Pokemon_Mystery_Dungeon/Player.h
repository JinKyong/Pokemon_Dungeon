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
	int _currentHP;
	int _starve;

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
	Item* _item;

	//�� ����(���� �Ǵ� ����)
	bool _inDungeon;

public:
	virtual HRESULT init(int pokemonNum);
	virtual HRESULT init(float x, float y);
	virtual void release();
	virtual void update();
	virtual void render();

	virtual int input() = 0;

	void changePattern(PLAYER_PATTERN pattern);
	void setDirect();
	void resetXY();

	void move();
	void attack();
	void sattack();
	void useSkill(int num);



	void hitDamage(int num);

	//=================== ������ ===================//
	PLAYER_TYPE getPlayerType() { return _playerType; }
	POKEMON_STATE getPlayerState() { return _playerState; }
	void setPlayerState(POKEMON_STATE playerState) { _playerState = playerState; }

	Pokemon* getPokemon() { return _pokemon; }
	void setPokemon(Pokemon* pokemon) { _pokemon = pokemon; }

	int getLevel() { return _level; }
	void setLevel(float level) { _level = level; }
	int getEXP() { return _EXP; }
	void setEXP(int EXP) { _EXP = EXP; }

	STAT getRealStat() { return _realStat; }
	void setRealStat(STAT realStat) { _realStat = realStat; }

	int getCurrentHP() { return _currentHP; }
	void setCurrentHP(int currentHP) { _currentHP = currentHP; }

	int getStarve() { return _starve; }
	void setStarve(int starve) { _starve = starve; }

	Skill** getSkill() { return _skill; }

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

	int getDirect() { return _direct; }

	RECT getBody() { return _body; }

	Item* getItem() { return _item; }
	void setItem(Item* item) { _item = item; }
};