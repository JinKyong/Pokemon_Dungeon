#pragma once
#include "Skill.h"
#include "EF_FireFang.h"

class FireFang :
	public Skill
{
private:
	EF_FireFang* _fireFangEffect;

public:
	FireFang() {};
	~FireFang() {};

	virtual HRESULT init();
	virtual void release();

	void useSkill(float x, float y, int direct);
};

