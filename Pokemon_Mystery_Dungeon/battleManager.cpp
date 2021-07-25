#include "stdafx.h"
#include "battleManager.h"
#include "Item.h"

battleManager::battleManager() :
	_counter{
/*			�븻	����	��	��	����	����	����	��	��ö	��	��	����	Ǯ	����	����	�巡	��			*/
		{	C,	C,	C,	C,	C,	C,	W,	N,	W,	C,	C,	C,	C,	C,	C,	C,	C	},	//�븻
		{	G,	C,	W,	C,	W,	W,	G,	N,	G,	C,	C,	C,	C,	G,	W,	C,	G	},  //����
		{	C,	C,	W,	W,	C,	C,	W,	W,	N,	C,	C,	C,	G,	C,	C,	C,	C	},  //��
		{	C,	C,	G,	C,	N,	W,	G,	C,	G,	G,	C,	G,	W,	C,	C,	C,	C	},  //��
		{	C,	G,	C,	C,	C,	G,	W,	C,	W,	C,	C,	W,	G,	C,	C,	C,	C	},  //����
		{	C,	W,	W,	C,	W,	C,	C,	W,	W,	W,	C,	C,	G,	C,	G,	C,	G	},  //����
		{	C,	W,	C,	W,	G,	G,	C,	C,	W,	G,	C,	C,	C,	G,	C,	C,	C	},  //����
		{	N,	C,	C,	C,	C,	C,	C,	G,	C,	C,	C,	C,	C,	C,	G,	C,	W	},  //��Ʈ
		{	C,	C,	C,	C,	C,	C,	G,	C,	W,	W,	W,	W,	C,	G,	C,	C,	C	},  //��ö
		{	C,	C,	C,	C,	C,	G,	W,	C,	G,	W,	W,	C,	G,	G,	C,	W,	C	},  //��
		{	C,	C,	C,	G,	C,	C,	G,	C,	C,	G,	W,	C,	W,	C,	C,	W,	C	},  //��
		{	C,	C,	C,	N,	G,	C,	C,	C,	C,	C,	G,	W,	W,	C,	C,	W,	C	},  //����
		{	C,	C,	W,	G,	W,	W,	G,	C,	W,	W,	G,	C,	W,	C,	C,	W,	C	},  //Ǯ
		{	C,	C,	C,	G,	G,	C,	C,	C,	W,	W,	W,	C,	G,	W,	C,	G,	C	},  //����
		{	C,	G,	G,	C,	C,	C,	C,	C,	W,	C,	C,	C,	C,	C,	W,	C,	N	},  //������
		{	C,	C,	C,	C,	C,	C,	C,	C,	W,	C,	C,	C,	C,	C,	C,	G,	C	},  //�巡��
		{	C,	W,	C,	C,	C,	C,	C,	G,	C,	C,	C,	C,	C,	C,	G,	C,	W	},  //��
	}
{
}

battleManager::~battleManager()
{
}

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
	float stab = 1.0f;
	float equip;

	//���ϸ� �Ǵ�(���� || Ư��)
	if (skill->getAtkType() == PHYSICAL_ATTACK)	atkType = player->getRealStat().attack;
	else										atkType = player->getRealStat().sattack;

	//�ڼ� ���� Ȯ��
	POKEMON_TYPE* playerType = player->getPokemon()->getPokemonType();
	POKEMON_TYPE  skillType = skill->getSkillType();
	if(skillType == END_POKEMON_TYPE) {}
	else if (playerType[0] == skillType || playerType[1] == skillType)	stab = 1.5f;

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

	//��
	float counter = 1.0f;
	POKEMON_TYPE*	playerType = player->getPokemon()->getPokemonType();
	POKEMON_TYPE	skillType = effect->getType();

	if (playerType[0] < END_POKEMON_TYPE && skillType < END_POKEMON_TYPE)
		counter *= _counter[skillType][playerType[0]];
	if (playerType[1] < END_POKEMON_TYPE && skillType < END_POKEMON_TYPE)
		counter *= _counter[skillType][playerType[1]];

	

	float finalDamage = (float)skillDamage / defense * RND->getFromIntTo(8.5, 10) * counter;
	
	//�ּ� ������ 1
	if (finalDamage <= 1)
		finalDamage = 1;
	
	//�α� �߰�
	DIALOGMANAGER->hitDamageLog(player, finalDamage);
	if (counter >= 2)
		DIALOGMANAGER->greatSkillLog();
	else if (0 < counter && counter <= 0.5)
		DIALOGMANAGER->worseSkillLog();
	else if (counter <= 0)
		DIALOGMANAGER->noneSkillLog();

	return finalDamage;
}



//���� �������� �Լ� �߰�


//������ ���� : HP �Ǵ� x �� or Ư�� �Ǵ� / 0.411
//������ ���� : ��ų���ݷ� / ������ * ������(85~100)


//������
//��ų���ݷ� : ������ �� or Ư�� �Ǵ� * ����� ��� ���� * ����� ��� �ڼӿ��� * Ư�� * ���� * ����
//������		: ����� HP �Ǵ� * ����� �� or Ư�� �Ǵ� / 0.411f
//�ѵ�����	: ��ų���ݷ� / ������ * ������(85 ~ 100)