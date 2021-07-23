#pragma once
#include "singletonBase.h"
#include "PokemonType.h"


// ����
// ( (������x2 + ��ü�� + ���ġ/4) x ����/100 + 10 + ���� ) x ���ݺ���
// ��ü���� 28�� ����, ���ġ�� 0���� ����, ������ ����
#define STAT_CALCULATION(baseStat, level)\
	((baseStat) * 2 + 28) * ((float)(level) / 100) + 10 + (level);

// ��ų ����
// ���ݽǴ� or Ư���Ǵ� * ������� * �ڼ� * Ư�� * ���� * ����		
// Ư��, ����, ������ ���� 1�ΰ���
#define SKILL_CALCULATION(atkType, skillPower, stab)\
	atkType * skillPower * stab * 1 * 1 * 1;

// ������ ����
// HP�Ǵ� * ���Ǵ� or Ư��Ǵ� / 0.411
#define DEFENCE_CALCULATION(realHP, defType)\
	realHP * defType / 0.411f;

// �� ������ ����
// ��ų���ݷ� / ������ * ������(85 ~ 100)

class Player;
class Effect;

class battleManager : public singletonBase<battleManager>
{
private:
	vector<Player*> *_allPlayer;

	Player* _player;
	Player* _enemy;

public:
	battleManager() {};
	~battleManager() {};

	HRESULT init();
	void release();
	void update();
	void render();


	//�Ǵɷ�ġ ���
	STAT statCalculation(Player* player);

	//������ ���
	int defenceCalculation(Player* player, Effect* effect);
};

