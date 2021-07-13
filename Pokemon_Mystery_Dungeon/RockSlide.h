#pragma once
#include "Skill.h"
class RockSlide :
	public Skill
{
private :

public :
	RockSlide() {};
	~RockSlide() {};

	virtual HRESULT init(float x, float y);
	virtual void release();

	void useSkill(float effectX, float effectY);
};

