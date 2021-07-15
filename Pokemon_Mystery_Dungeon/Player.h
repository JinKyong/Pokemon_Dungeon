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
protected:
	//플레이어 타입 & 상태
	PLAYER_TYPE _playerType;
	POKEMON_STATE _playerState;

	//플레이어 포켓몬
	Pokemon* _pokemon;

	//좌표
	float _x, _y;
	float _destX, _destY;
	int _direct;
	RECT _body;

	//레벨 & 경험치
	int _level;
	int _EXP;

	//스탯 (실제 값)
	STAT _realStat;

	//기술(스킬)
	Skill* _skill[4];

	//지닌도구(아이템)
	//Item _item;

	//맵 상태(마을 또는 던전)
	bool _inDungeon;

public:
	virtual HRESULT init(int pokemonNum) = 0;
	virtual void release() = 0;
	virtual void update() = 0;
	virtual void render() = 0;

	virtual int input() = 0;

	void attack();
	void move();



	//=================== 접근자 ===================//
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
};