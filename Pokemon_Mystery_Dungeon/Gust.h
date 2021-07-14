#pragma once
#include "Skill.h"
#include "EF_Gust.h"

class Gust :
	public Skill
{
private:
	EF_Gust* _gustEffect;

public:
	Gust() {};
	~Gust() {};
	virtual HRESULT init(float x, float y);
	virtual void release();

	void useSkill(float x, float y);
};

