#include "stdafx.h"
#include "SkillManager.h"
#include "Lightning.h"
#include "FireBlast.h"
#include "Gust.h"
#include "RockSlide.h"

HRESULT SkillManager::init()
{
	registerSkill(FIREBLAST, new FireBlast);
	registerSkill(GUST, new Gust);
	registerSkill(LIGHTNING, new Lightning);
	registerSkill(ROCKSLIDE, new RockSlide);
	return S_OK;
}

void SkillManager::release()
{
}

void SkillManager::update()
{
}

void SkillManager::render()
{
}

Skill * SkillManager::registerSkill(int skillNum, Skill * skill)
{
	if (!skill) return nullptr;

	_mSkill.insert(make_pair(skillNum, skill));

	return skill;
}

void SkillManager::addSkill(float x, float y, int skillNum)
{
	_miSkill = _mSkill.find(skillNum);

	if (_miSkill != _mSkill.end())
	{
		_miSkill->second->init(x, y);
		_vSkill.push_back(_miSkill->second);
	}
}
