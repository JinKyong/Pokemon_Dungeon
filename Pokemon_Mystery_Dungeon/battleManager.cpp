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
	//������, ����
	STAT baseStat = player->getPokemon()->getPokemonValue();
	int level = player->getLevel();
	//�Ǵɷ�ġ
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

	//���ϸ� �Ǵ�(���� || Ư��)
	if (skill->getAtkType() == PHYSICAL_ATTACK)	atkType = player->getRealStat().attack;
	else										atkType = player->getRealStat().sattack;

	//�ڼ� ���� Ȯ��
	POKEMON_TYPE* playerType = player->getPokemon()->getPokemonType();
	POKEMON_TYPE  skillType = skill->getSkillType();
	if (playerType[0] == skillType || playerType[1] == skillType)	stab = 1.5f;
	else															stab = 1.f;

	//���� Ȯ��
	//if(player->getItem())
	//	equip = player->getItem()->
	//�ϴ��� 1


	//�����°��
	float finalDamage = SKILL_CALCULATION(atkType, skill->getDamage(), stab, 1, 1, 1);

	//enemy�� �� ��ų�� ����, team�� �� ��ų�� ���
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
	// �� ������ ����
	// ��ų���ݷ� / ������ * ������(85 ~ 100)
	int skillDamage;
	int defense;

	skillDamage = effect->getDamage();
	defense = defenceCalculation(player, effect);

	return (float)skillDamage / defense * RND->getFromIntTo(85, 101);
}



//���� �������� �Լ� �߰�


//������ ���� : HP �Ǵ� x �� or Ư�� �Ǵ� / 0.411
//������ ���� : ��ų���ݷ� / ������ * ������(85~100)


//������
//��ų���ݷ� : ������ �� or Ư�� �Ǵ� * ����� ��� ���� * ����� ��� �ڼӿ��� * Ư�� * ���� * ����
//������		: ����� HP �Ǵ� * ����� �� or Ư�� �Ǵ� / 0.411f
//�ѵ�����	: ��ų���ݷ� / ������ * ������(85 ~ 100)