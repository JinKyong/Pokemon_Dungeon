#pragma once
#include "Skill.h"
#include "EF_Pound.h"

class Pound :
	public Skill
{
private :
	EF_Pound* _poundEffect;

public :
	Pound() {};
	~Pound() {};

	virtual HRESULT init();
	virtual void release();

	void useSkill(float x, float y);
};

