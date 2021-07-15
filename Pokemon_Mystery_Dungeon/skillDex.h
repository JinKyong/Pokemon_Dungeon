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

	// ================== 1 ~ 10 ================== //
	Skill* fireBlast() { return new FireBlast; }
	Skill* gust() { return new Gust; }
	Skill* lightning() { return new Lightning; }
	Skill* rockSlide() { return new RockSlide; }
	Skill* dynamicPunch() { return new DynamicPunch; }
	Skill* leafBlade() { return new LeafBlade; }
	Skill* thunderFang() { return new ThunderFang; }
	Skill* iceFang() { return new IceFang; }
	Skill* fireFang() { return new FireFang; }
	Skill* pound() { return new Pound; }

	// ================== 11 ~ 20 ================== //
	Skill* poisonPowder() { return new PoisonPowder; }
	Skill* sleepPowder() { return new SleepPowder; }
	Skill* stunSpore() { return new StunSpore; }
	Skill* metalClaw() { return new MetalClaw; }
};

