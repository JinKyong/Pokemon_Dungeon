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

int battleManager::defenceCalculation(Player * player, Effect * effect)
{
	int defType;

	//if (effect->getAtkType() == PHYSICAL_ATTACK) defType = player->getRealStat().defense;
	//else										 defType = player->getRealStat().sdefense;

	return 0;
}



//���� �������� �Լ� �߰�

//��ų ���� : ���ݽǴ� or Ư���Ǵ� * ������� * �ڼ� * Ư�� * ���� * ����	
//������ ���� : HP �Ǵ� x �� or Ư�� �Ǵ� / 0.411
//������ ���� : ��ų���ݷ� / ������ * ������(85~100)


//������
//��ų���ݷ� : ������ �� or Ư�� �Ǵ� * ����� ��� ���� * ����� ��� �ڼӿ��� * Ư�� * ���� * ����
//������		: ����� HP �Ǵ� * ����� �� or Ư�� �Ǵ� / 0.411f
//�ѵ�����	: ��ų���ݷ� / ������ * ������(85 ~ 100)