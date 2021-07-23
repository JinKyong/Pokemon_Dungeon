#pragma once
#include "PokemonType.h"
class Player;

enum ATTACKTYPE	//���ݼӼ�
{
	PHYSICAL_ATTACK,
	SPECIAL_ATTACK,
	TRANSFORM_STATE
};

enum SKILLSCALE	//Ÿ�ݹ���
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
	ATTACKTYPE _atkType;
	POKEMON_TYPE _type;
	SKILLSCALE _scale;
	Player* _player;
	int _damage;
	float _accuracy;
	int _currentPP, _maxPP;
	int _finalDamage;

public:
	Skill() {};
	~Skill() {};

	virtual HRESULT init(Player* player);
	virtual void release() = 0;

	virtual void useSkill();

	// ====================������,������==================== //
	wstring getName() { return _name; }
	int getDamage() { return _damage; }

	float getAccuracy() { return _accuracy; }

	int getCurrentPP() { return _currentPP; }
	void setCurrentPP(int plusCurPP) { _currentPP = plusCurPP; }

	int getMaxPP() { return _maxPP; }
	void setMaxPP(int plusMaxPP) { _maxPP = plusMaxPP; }

	ATTACKTYPE getAtkType() { return _atkType; }
	POKEMON_TYPE getSkillType() { return _type; }
};

