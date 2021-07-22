#pragma once
#include "singletonBase.h"
#include "PokemonType.h"


// 계산식
// ( (종족값x2 + 개체값 + 노력치/4) x 레벨/100 + 10 + 레벨 ) x 성격보정
// 개체값은 28로 통일, 노력치는 0으로 통일, 성격은 없음
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


	//실능력치 계산
	STAT statCalculatior(Player* player);



	//데미지 계산
	int damageCalculation();
};

