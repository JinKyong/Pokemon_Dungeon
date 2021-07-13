#pragma once
#include "Skill.h"
class Gust :
	public Skill
{
private :

public :
	Gust() {};
	~Gust() {};
	virtual HRESULT init(float x, float y);
	virtual void release();

	void useSkill(float effectX, float effectY);
};

