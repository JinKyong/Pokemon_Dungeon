#pragma once
#include "PokemonType.h"

enum SKILLKEYVALUE	//���ݼӼ�
{
	FIREBLAST,
	GUST,
	LIGHTNING,
	ROCKSLIDE
};

enum SKILLTYPE	//���ݼӼ�
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



	// ====================������,������==================== //
	int getDamage() { return _damage; }

	float getAccuracy() { return _accuracy; }

	int getCurrentPP() { return _currentPP; }
	void setCurrentPP(int plusCurPP) { _currentPP = plusCurPP; }

	int getMaxPP() { return _maxPP; }
	void setMaxPP(int plusMaxPP) { _maxPP = plusMaxPP; }
	//virtual SKILLTYPE getType() = 0;
	//useSkill -> ����Ʈ�Ŵ��� �ҷ��� ���Ϳ� �ִ½�����
	
};

