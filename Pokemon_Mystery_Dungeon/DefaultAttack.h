#pragma once
#include "Skill.h"
#include "EF_DynamicPunch.h"

class DefaultAttack : public Skill
{
private:
	EF_DynamicPunch* _dynamicPunchEffect;

public:
	DefaultAttack() {};
	~DefaultAttack() {};

	virtual HRESULT init(Player* player);
	virtual void release();

	void useSkill();
};

