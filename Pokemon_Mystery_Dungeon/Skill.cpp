#include "stdafx.h"
#include "Skill.h"

void Skill::useSkill(float x, float y)
{
	if (_currentPP <= 0) return;

	_currentPP--;
}
