#pragma once
#include "Skill.h"
#include "EF_MetalClaw.h"

class MetalClaw :
	public Skill
{
private :
	EF_MetalClaw* _metalClawEffect;

public :
	MetalClaw() {};
	~MetalClaw() {};

	virtual HRESULT init();
	virtual void release();

	void useSkill(float x, float y);
};

