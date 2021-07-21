#include "stdafx.h"
#include "battleManager.h"

HRESULT battleManager::init()
{
	//_allPlayer = TURNMANAGER->getAllPlayer();

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

int battleManager::damageCalculation()								//이펙트 데미지용
{
	_rndNum = RND->getFromIntTo(217, 256) * 100 / 255;									//랜덤수

	int rndCri = RND->getFloat(100);													//급소
	if (rndCri > 6.25f) _critical = 1;
	else				_critical = 2;

	//if (_player->getPlayerType() == SKILLDEX->fireBlast()->getSkillType()) _type = 2;	//자속
	//else																   _type = 1;
	//
	//
	//
	//
	//_damage = (((((((_player->getLevel() * 2 / 5) + 2) * 50 * _player->getSpAtk() / 50) /
	//	_enemy->getSpDef()) + 2) * _critical * _rndNum / 100) * _type * 1 * 1);

	return _damage;
}



//최종 데미지용 함수 추가


//4세대 데미지 계산
//(데미지 = (((((((레벨 × 2 ÷ 5) + 2) × 위력 × 특수공격 ÷ 50) ÷ 특수방어) + 2) × [[급소]] ×  랜덤수 ÷ 100) × 자속보정 × 타입상성1 × 타입상성2)
					//여기까지 이펙트 데미지						나머지는 충돌처리시					(자속보정은 스킬쓸때 bool값으로)

//2세대 데미지 계산
//(데미지 = (위력 × 공격 × (레벨 × 2 ÷ 5 + 2 ) ÷ 방어 ÷ 50 × [[급소]] + 2 ) × [[자속 보정]] × 타입상성1 × 타입상성2 × 랜덤수/255)

/*
데미지 공식에 필요한것
레벨,
스킬공격력(위력),
(공격하는애)특수공격력,
(쳐맞는애)특수방어력,
급소율 6.25 % (급소 맞으면 2 대입)
랜덤수((217~255 사이의 랜덤한 수) × 100) ÷ 255, 소수점 이하 버림.
자속보정(스킬타입, 포켓몬타입이 일치하면 1.5 대입)
타입상성(효과가뛰어남2, 효과별로0.5, 효과없음 0)
*/