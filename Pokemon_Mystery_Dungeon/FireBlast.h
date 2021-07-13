#pragma once
#include "Skill.h"
class FireBlast :
	public Skill
{
private:
public:
	FireBlast() {};
	~FireBlast() {};

	virtual HRESULT init(float x, float y);
	virtual void release();

	void useSkill(float effectX, float effectY);
};

