#include "stdafx.h"
#include "Enemy.h"
#include "PatternPathFinder.h"
#include "PatternOnAttack.h"

HRESULT Enemy::init(int pokemonNum)
{
	Player::init(pokemonNum);

	//�÷��̾� Ÿ��
	_playerType = PLAYER_TYPE_ENEMY;
	_playerState = POKEMON_STATE_DEFAULT;
	//����
	_pattern[PLAYER_PATTERN_PATHFINDER] = new PatternPathFinder;
	_pattern[PLAYER_PATTERN_ONATTACK] = new PatternOnAttack;
	changePattern(PLAYER_PATTERN_PATHFINDER);


	//���
	//_selectedSkill = nullptr;
	//_skill[0] = SKILLDEX->makeSkill(1);
	//_skill[0]->init();
	//_skill[1] = SKILLDEX->makeSkill(6);
	//_skill[1]->init();
	//_skill[2] = SKILLDEX->makeSkill(3);
	//_skill[2]->init();
	//_skill[3] = SKILLDEX->makeSkill(4);
	//_skill[3]->init();
	//_inDungeon = false;

	return S_OK;
}

int Enemy::input()
{
	_pattern[_currentPattern]->update();

	return _playerState;
}