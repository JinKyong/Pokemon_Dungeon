#pragma once
#include "singletonBase.h"
#include "PokemonType.h"


// ����
// ( (������x2 + ��ü�� + ���ġ/4) x ����/100 + 10 + ���� ) x ���ݺ���
// ��ü���� 28�� ����, ���ġ�� 0���� ����, ������ ����
#define STAT_CALCULATION(baseStat, level)\
	((baseStat) * 2 + 28) * ((float)(level) / 100) + 10 + (level);

class Player;

class battleManager : public singletonBase<battleManager>
{
private:
	int _damage;
	int _rndNum;
	int _critical;
	int _type;
	int _pokemonType;
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
	STAT statCalculatior(Player* player);



	//������ ���
	int damageCalculation();
};

