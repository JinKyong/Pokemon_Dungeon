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
	swprintf_s(log, L"%s(��)�� %s(��)�� �ֿ���.", player->getPokemon()->getName().c_str(), item->getName().c_str());
	_battleLog.push_back(log);
}

void dialogManager::addExpLog(Player * player, int exp)
{
	resetTimer();

	WCHAR log[128];
	swprintf_s(log, L"%s(��)�� %d����ġ�� ȹ���ߴ�.", player->getPokemon()->getName().c_str(), exp);
	_battleLog.push_back(log);
}

void dialogManager::useSkillLog(Player * player, Skill * skill)
{
	resetTimer();

	WCHAR log[128];
	swprintf_s(log, L"%s(��)�� %s(��)�� ����ߴ�.", player->getPokemon()->getName().c_str(), skill->getName().c_str());
	_battleLog.push_back(log);
}

void dialogManager::failSkillLog()
{
	resetTimer();

	WCHAR log[128];
	swprintf_s(log, L"����� �����ߴ�.");
	_battleLog.push_back(log);
}
