#pragma once
#include "Skill.h"
#include "EF_SleepPowder.h"

class SleepPowder :
	public Skill
{
private :
	EF_SleepPowder* _sleepPowderEffect;

public :
	SleepPowder() {};
	~SleepPowder() {};

	virtual HRESULT init();
	virtual void release();

	void useSkill(float x, float y);
};

