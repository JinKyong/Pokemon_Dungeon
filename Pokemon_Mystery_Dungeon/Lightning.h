#pragma once
#include "Skill.h"
#include "EF_Lightning.h"

class Lightning :
	public Skill
{
private:
	EF_Lightning* _lightningEffect;

public:
	Lightning() {};
	~Lightning() {};

	virtual HRESULT init(float x, float y);
	virtual void release();

	void useSkill(float x, float y);
};

