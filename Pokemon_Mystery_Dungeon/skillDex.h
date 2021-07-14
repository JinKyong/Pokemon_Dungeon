#pragma once
#include "singletonBase.h"
#include "Skill.h"
#include "SkillHeader.h"
#include <map>

class skillDex : public singletonBase <skillDex>
{
private:
	typedef Skill*(skillDex::*func)();
	typedef map<int, func>		skillList;

private:
	skillList _skillList;

	int _index;

public:
	HRESULT init();
	void release();

	void addSkill(func f);
	void setSkillDex();

	Skill* makeSkill(int num);

	//======================== 스킬 도감 ========================//

};

