#include "stdafx.h"
#include "Skill.h"

HRESULT Skill::init(Player * player)
{
	_player = player;
	return S_OK;
}

void Skill::useSkill()		//플레이어 포인트를 받아와서		+	최종결정력 담을 변수			//자속은 bool값 or float값으로, 도구는 값으로
{
	if (_currentPP <= 0) return;

	int direct = _player->getPokemon()->getDirect();
	int atkType;
	float steb = 1.f;

	_currentPP--;

	_x = _player->getX();
	_y = _player->getY();

	if ((direct & RIGHT) == RIGHT)
		_x++;
	else if ((direct & LEFT) == LEFT)
		_x--;

	if ((direct & DOWN) == DOWN)
		_y++;
	else if ((direct & UP) == UP)
		_y--;

	if (_atkType == PHYSICAL_ATTACK)	atkType = _player->getRealStat().attack;
	else								atkType = _player->getRealStat().sattack;

	if (_player->getPokemon()->getPokemonType1() == _type || _player->getPokemon()->getPokemonType2() == _type) steb = 1.5f;
	else																										steb = 1.f;

	//결정력계산
	_finalDamage = atkType * _damage * steb;

	if (_player->getPlayerType() == PLAYER_TYPE_ENEMY)	_finalDamage = _finalDamage * -1;		//적 데미지		(음수)
	else											    _finalDamage = _finalDamage;			//아군 데미지	(양수)
}

/*
공or 특공->플레이어 공 / 특공 and 스킬의 공격타입 필요
스킬 자체데미지
자속->플레이어의 속성 and 스킬의 속성 필요



공격실능 or 특공실능 * 기술위력 * 자속 * 특성 * 도구 * 날씨
*/