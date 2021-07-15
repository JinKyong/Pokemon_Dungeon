#pragma once
#include "Skill.h"
#include "EF_DynamicPunch.h"

class DynamicPunch :
	public Skill
{
private :
	EF_DynamicPunch* _dynamicPunchEffect;

public :
	DynamicPunch() {};
	~DynamicPunch() {};

	virtual HRESULT init();
	virtual void release();

	void useSkill(float x, float y);
};

