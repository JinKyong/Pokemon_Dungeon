#pragma once
#include "singletonBase.h"
#include "PokemonType.h"

#define G	2.0f	//GREAT		== ȿ���� ����
#define C	1.0f	//COMMON	== �Ϲ�
#define W	0.5f	//WORSE		== ȿ���� ����
#define N	0.0f	//NONE		== ȿ���� ����

// ����
// ( (������x2 + ��ü�� + ���ġ/4) x ����/100 + 10 + ���� ) x ���ݺ���
// ��ü���� 28�� ����, ���ġ�� 0���� ����, ������ ����
#define STAT_CALCULATION(baseStat, level)\
	((baseStat) * 2 + 28) * ((float)(level) / 100) + 10 + (level);

// ��ų ����
// ���ݽǴ� or Ư���Ǵ� * ������� * �ڼ� * Ư�� * ���� * ����		
// Ư��, ������ ���� 1�ΰ���
#define SKILL_CALCULATION(atkType, skillPower, stab, equip)\
	atkType * skillPower * stab * equip * 1 * 1;

// ������ ����
// HP�Ǵ� * ���Ǵ� or Ư��Ǵ� / 0.411
#define DEFENCE_CALCULATION(realHP, defType)\
	realHP * defType / 0.411f;

// �� ������ ����
// ��ų���ݷ� / ������ * ������(85 ~ 100)

class Player;
class Effect;
class Item;

class battleManager : public singletonBase<battleManager>
{
private:
	float _counter[END_POKEMON_TYPE][END_POKEMON_TYPE];
	int _test[5][5];

public:
	battleManager();
	~battleManager();

	HRESULT init();
	void release();
	void update();
	void render();


	//�Ǵɷ�ġ ���
	STAT statCalculation(Player* player);

	//������ ���
	float skillCalculation(Player* player, Skill* skill);
	//������ ���
	float defenceCalculation(Player* player, Effect* effect);
	//���������� ���
	float damageCalculation(Player* player, Effect* effect);
};

