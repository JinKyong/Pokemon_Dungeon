#pragma once
#include "Skill.h"
class StunSpore :
	public Skill
{
private :

public :
	StunSpore() {};
	~StunSpore() {};

	virtual HRESULT init();
	virtual void release();

	void useSkill(float x, float y);
};

