#pragma once
#include "Skill.h"

class Lightning :
	public Skill
{
private :

public :
	Lightning() {};
	~Lightning() {};

	virtual HRESULT init(float x, float y);
	virtual void release();

	void useSkill(float effectX, float effectY);
};

