#pragma once
#include "singletonBase.h"
#include "PokemonType.h"


// 계산식
// ( (종족값x2 + 개체값 + 노력치/4) x 레벨/100 + 10 + 레벨 ) x 성격보정
// 개체값은 28로 통일, 노력치는 0으로 통일, 성격은 없음
#define STAT_CALCULATION(baseStat, level)\
	((baseStat) * 2 + 28) * ((float)(level) / 100) + 10 + (level);

// 스킬 계산식
// 공격실능 or 특공실능 * 기술위력 * 자속 * 특성 * 도구 * 날씨		
// 특성, 도구, 날씨는 현재 1로고정
#define SKILL_CALCULATION(atkType, skillPower, stab)\
	atkType * skillPower * stab * 1 * 1 * 1;

// 내구력 계산식
// HP실능 * 방어실능 or 특방실능 / 0.411
#define DEFENCE_CALCULATION(realHP, defType)\
	realHP * defType / 0.411f;

// 총 데미지 계산식
// 스킬공격력 / 내구력 * 랜덤수(85 ~ 100)

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


	//실능력치 계산
	STAT statCalculation(Player* player);

	//내구력 계산
	int defenceCalculation(Player* player, Effect* effect);
};

