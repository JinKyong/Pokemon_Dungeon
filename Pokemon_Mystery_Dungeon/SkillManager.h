#pragma once
#include "Skill.h"
#include <vector>
class SkillManager
{
private:
	typedef map<int, Skill*>				skillMap;
	typedef map<int, Skill*>::iterator		skillMapIter;

	typedef vector<Skill*>				skillList;
	typedef vector<Skill*>::iterator	skillIter;

private:
	skillMap		 _mSkill;
	skillMapIter	 _miSkill;

	skillList _vSkill;
	skillIter _viSkill;

public:
	SkillManager() {};
	~SkillManager() {};

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	Skill* registerSkill(int skillNum, Skill* skill);
	void addSkill(float x, float y, int skillNum);

};

