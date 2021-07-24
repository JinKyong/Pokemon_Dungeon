#include "stdafx.h"
#include "battleManager.h"
#include "Item.h"

HRESULT battleManager::init()
{

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

float battleManager::skillCalculation(Player * player, Skill * skill)
{
	int atkType;
	float stab;
	float equip;

	//포켓몬 실능(물공 || 특공)
	if (skill->getAtkType() == PHYSICAL_ATTACK)	atkType = player->getRealStat().attack;
	else										atkType = player->getRealStat().sattack;

	//자속 여부 확인
	POKEMON_TYPE* playerType = player->getPokemon()->getPokemonType();
	POKEMON_TYPE  skillType = skill->getSkillType();
	if (playerType[0] == skillType || playerType[1] == skillType)	stab = 1.5f;
	else															stab = 1.f;

	//도구 확인
	//if(player->getItem())
	//	equip = player->getItem()->
	//일단은 1


	//결정력계산
	float finalDamage = SKILL_CALCULATION(atkType, skill->getDamage(), stab, 1, 1, 1);

	//enemy가 쓴 스킬은 음수, team이 쓴 스킬은 양수
	if (player->getPlayerType() == PLAYER_TYPE_ENEMY)	return -finalDamage;
	else											    return finalDamage;
}

float battleManager::defenceCalculation(Player * player, Effect * effect)
{
	int defType;

	if (effect->getAtkType() == PHYSICAL_ATTACK) defType = player->getRealStat().defense;
	else										 defType = player->getRealStat().sdefense;

	return DEFENCE_CALCULATION(player->getRealStat().hp, defType);
}

float battleManager::damageCalculation(Player * player, Effect * effect)
{
	// 총 데미지 계산식
	// 스킬공격력 / 내구력 * 랜덤수(85 ~ 100)
	int skillDamage;
	int defense;

	skillDamage = effect->getDamage();
	defense = defenceCalculation(player, effect);

	return (float)skillDamage / defense * RND->getFromIntTo(85, 101);
}



//최종 데미지용 함수 추가


//내구력 공식 : HP 실능 x 방 or 특방 실능 / 0.411
//데미지 공식 : 스킬공격력 / 내구력 * 랜덤수(85~100)


//총정리
//스킬공격력 : 공격자 공 or 특공 실능 * 사용한 기술 위력 * 사용한 기술 자속여부 * 특성 * 도구 * 날씨
//내구력		: 방어자 HP 실능 * 방어자 방 or 특방 실능 / 0.411f
//총데미지	: 스킬공격력 / 내구력 * 랜덤수(85 ~ 100)