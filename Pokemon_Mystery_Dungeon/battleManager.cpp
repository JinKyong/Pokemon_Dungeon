#include "stdafx.h"
#include "battleManager.h"

HRESULT battleManager::init()
{
	_allPlayer = TURNMANAGER->getAllPlayer();

	vector<Player*>::iterator playerIter;

	for (playerIter = _allPlayer->begin(); playerIter != _allPlayer->end(); ++playerIter)
	{
		if ((*playerIter)->getPlayerType() == PLAYER_TYPE_USER) _player = (*playerIter);
		else if ((*playerIter)->getPlayerType() == PLAYER_TYPE_ENEMY) _enemy = (*playerIter);
	}
	return S_OK;
}

void battleManager::release()
{
}

void battleManager::update()
{
}

void battleManager::render()
{
}

STAT battleManager::statCalculation(Player * player)
{
	//종족값, 레벨
	STAT baseStat = player->getPokemon()->getPokemonValue();
	int level = player->getLevel();
	//실능력치
	STAT realStat;

	realStat.hp = STAT_CALCULATION(baseStat.hp, level);
	realStat.attack = STAT_CALCULATION(baseStat.attack, level);
	realStat.defense = STAT_CALCULATION(baseStat.defense, level);
	realStat.sattack = STAT_CALCULATION(baseStat.sattack, level);
	realStat.sdefense = STAT_CALCULATION(baseStat.sdefense, level);
	realStat.speed = STAT_CALCULATION(baseStat.speed, level);

	return realStat;
}

int battleManager::defenceCalculation(Player * player, Effect * effect)
{
	int defType;

	//if (effect->getAtkType() == PHYSICAL_ATTACK) defType = player->getRealStat().defense;
	//else										 defType = player->getRealStat().sdefense;

	return 0;
}



//최종 데미지용 함수 추가

//스킬 계산식 : 공격실능 or 특공실능 * 기술위력 * 자속 * 특성 * 도구 * 날씨	
//내구력 공식 : HP 실능 x 방 or 특방 실능 / 0.411
//데미지 공식 : 스킬공격력 / 내구력 * 랜덤수(85~100)


//총정리
//스킬공격력 : 공격자 공 or 특공 실능 * 사용한 기술 위력 * 사용한 기술 자속여부 * 특성 * 도구 * 날씨
//내구력		: 방어자 HP 실능 * 방어자 방 or 특방 실능 / 0.411f
//총데미지	: 스킬공격력 / 내구력 * 랜덤수(85 ~ 100)