#pragma once
#include "PokemonType.h"

enum SKILLTYPE	//공격속성
{
	PHYSICAL_ATTACK,
	SPECIAL_ATTACK,
	TRANSFORM_STATE
};

enum SKILLSCALE	//타격범위
{
	SS_FRONT,
	SS_PIERCE,
	SS_STRAIGHT,
	SS_SCREEN
};

class Skill
{
protected:
	wstring _name;
	float _x, _y;
	int _direct;
	int _skillNum;
	SKILLTYPE _atkType;
	POKEMON_TYPE _type;
	SKILLSCALE _scale;
	int _damage;
	float _accuracy;
	int _currentPP, _maxPP;

public:
	Skill() {};
	~Skill() {};

	virtual HRESULT init() = 0;
	virtual void release() = 0;

	virtual void useSkill(float x, float y, int direct);

	// ====================접근자,설정자==================== //
	wstring getName() { return _name; }
	int getDamage() { return _damage; }

	float getAccuracy() { return _accuracy; }

	int getCurrentPP() { return _currentPP; }
	void setCurrentPP(int plusCurPP) { _currentPP = plusCurPP; }

	int getMaxPP() { return _maxPP; }
	void setMaxPP(int plusMaxPP) { _maxPP = plusMaxPP; }

};

