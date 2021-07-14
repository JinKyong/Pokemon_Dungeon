#pragma once
#include "Skill.h"
#include "EF_RockSlide.h"

class RockSlide :
	public Skill
{
private:
	EF_RockSlide* _rockSlideEffect;

public:
	RockSlide() {};
	~RockSlide() {};

	virtual HRESULT init(float x, float y);
	virtual void release();

	void useSkill(float x, float y);
};

