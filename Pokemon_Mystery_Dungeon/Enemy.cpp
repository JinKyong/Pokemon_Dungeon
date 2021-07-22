#include "stdafx.h"
#include "Enemy.h"
#include "PatternPathFinder.h"
#include "PatternOnAttack.h"

HRESULT Enemy::init(int pokemonNum)
{
	Player::init(pokemonNum);

	//플레이어 타입
	_playerType = PLAYER_TYPE_ENEMY;
	_playerState = POKEMON_STATE_DEFAULT;
	//패턴
	_pattern[PLAYER_PATTERN_PATHFINDER] = new PatternPathFinder;
	_pattern[PLAYER_PATTERN_ONATTACK] = new PatternOnAttack;
	changePattern(PLAYER_PATTERN_PATHFINDER);


	//기술
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

void Enemy::release()
{
}

void Enemy::update()
{
	//패턴 정하기

	_body = RectMakeCenter(_x * TILEWIDTH + TILEWIDTH / 2, _y * TILEHEIGHT + TILEHEIGHT / 2,
		TILEWIDTH, TILEHEIGHT);
}

void Enemy::render()
{
	if (PRINTMANAGER->isDebug()) {
		WCHAR str[128];
		swprintf_s(str, L"x : %f", _x);
		DTDMANAGER->printText(str, dRectMake(_body.left, _body.top - 60, 100, 20));
		swprintf_s(str, L"y : %f", _y);
		DTDMANAGER->printText(str, dRectMake(_body.left, _body.top - 40, 100, 20));
		swprintf_s(str, L"name : %s", _pokemon->getName().c_str());
		DTDMANAGER->printText(str, dRectMake(_body.left, _body.top - 20, 100, 20));

		DTDMANAGER->Rectangle(_body);
	}

	_pokemon->render(_x, _y);
}

int Enemy::input()
{
	//시작지점 설정
	_initX = _x;
	_initY = _y;

	_pattern[_currentPattern]->update();

	return _playerState;
}