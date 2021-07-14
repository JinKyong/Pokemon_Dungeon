#pragma once
#include "PokemonType.h"

enum SKILLKEYVALUE	//공격속성
{
	FIREBLAST,
	GUST,
	LIGHTNING,
	ROCKSLIDE
};

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
protected :
	wstring _name;
	int _skillNum;
	SKILLTYPE _skType;
	//ATTRIBUTE _att;
	SKILLSCALE _scale;
	int _damage;
	float _accuracy;
	int _currentPP, _maxPP;

public :
	Skill() {};
	~Skill() {};

	virtual HRESULT init(float x, float y) = 0;
	virtual void release() = 0;



	// ====================접근자,설정자==================== //
	int getDamage() { return _damage; }

	float getAccuracy() { return _accuracy; }

	int getCurrentPP() { return _currentPP; }
	void setCurrentPP(int plusCurPP) { _currentPP = plusCurPP; }

	int getMaxPP() { return _maxPP; }
	void setMaxPP(int plusMaxPP) { _maxPP = plusMaxPP; }
	//virtual SKILLTYPE getType() = 0;
	//useSkill -> 이펙트매니저 불러서 벡터에 넣는식으로
	
};

