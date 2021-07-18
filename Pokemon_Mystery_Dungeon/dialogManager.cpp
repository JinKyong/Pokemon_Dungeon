#include "stdafx.h"
#include "dialogManager.h"
#include "Item.h"

HRESULT dialogManager::init()
{

	return S_OK;
}

void dialogManager::release()
{
	battleIter iter = _battleLog.begin();

	for (; iter != _battleLog.end();)
		iter = _battleLog.erase(iter);

	_battleLog.clear();
}

void dialogManager::update()
{
}

void dialogManager::render()
{
}

void dialogManager::resetTimer()
{
	TIMEMANAGER->endTimer();
	TIMEMANAGER->setTimer();
	UIMANAGER->getCurrentDownMenu()->setHidden(false);
}

void dialogManager::addItemLog(Player * player, Item * item)
{
	resetTimer();

	WCHAR log[128];
	swprintf_s(log, L"%s(이)가 %s(을)를 주웠다.", player->getPokemon()->getName().c_str(), item->getName().c_str());
	_battleLog.push_back(log);
}

void dialogManager::addExpLog(Player * player, int exp)
{
	resetTimer();

	WCHAR log[128];
	swprintf_s(log, L"%s(이)가 %d경험치를 획득했다.", player->getPokemon()->getName().c_str(), exp);
	_battleLog.push_back(log);
}

void dialogManager::useSkillLog(Player * player, Skill * skill)
{
	resetTimer();

	WCHAR log[128];
	swprintf_s(log, L"%s(이)가 %s(을)를 사용했다.", player->getPokemon()->getName().c_str(), skill->getName().c_str());
	_battleLog.push_back(log);
}

void dialogManager::failSkillLog()
{
	resetTimer();

	WCHAR log[128];
	swprintf_s(log, L"기술은 실패했다.");
	_battleLog.push_back(log);
}
