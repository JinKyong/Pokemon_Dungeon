#include "stdafx.h"
#include "skillDex.h"

HRESULT skillDex::init()
{
	_index = 0;

	setSkillDex();

	return S_OK;
}

void skillDex::release()
{
}

void skillDex::addSkill(func f)
{
	_index++;
	_skillList.insert(make_pair(_index, f));
}

void skillDex::setSkillDex()
{
	//���⿡ addSkill()�� ��� �߰����� (��ȣ ���缭 �������)
	//����: addSkill(&skillDex::fireBlast);
	addSkill(&skillDex::fireBlast);
	addSkill(&skillDex::gust);
	addSkill(&skillDex::lightning);
	addSkill(&skillDex::rockSlide);
	addSkill(&skillDex::dynamicPunch);
	addSkill(&skillDex::leafBlade);
	addSkill(&skillDex::thunderFang);
	addSkill(&skillDex::iceFang);
	addSkill(&skillDex::fireFang);
}

Skill * skillDex::makeSkill(int num)
{
	if (num <= 0 || _index < num) return nullptr;

	return (this->*_skillList[num])();
}
