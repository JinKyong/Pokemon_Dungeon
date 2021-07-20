#include "stdafx.h"
#include "Enemy.h"
#include "PatternPathFinder.h"

HRESULT Enemy::init(int pokemonNum)
{
	Player::init(pokemonNum);

	//플레이어 타입
	_playerType = PLAYER_TYPE_ENEMY;
	_playerState = POKEMON_STATE_DEFAULT;

	//스탯
	//계산해서 넣음 포켓몬 꺼
	_testHP = 200;

	//_inDungeon = false;

	_pattern = new PatternPathFinder;

	return S_OK;
}

void Enemy::release()
{
}

void Enemy::update()
{
	_body = RectMakeCenter(_x * TILEWIDTH + TILEWIDTH / 2, _y * TILEHEIGHT + TILEHEIGHT / 2,
		TILEWIDTH, TILEHEIGHT);
}

void Enemy::render()
{
	if (PRINTMANAGER->isDebug()) {
		WCHAR str[128];
		swprintf_s(str, L"HP : %d", _testHP);
		DTDMANAGER->printText(str, dRectMake(_body.left, _body.top - 80, 100, 20));
		swprintf_s(str, L"direct : %d", _pokemon->getDirect());
		DTDMANAGER->printText(str, dRectMake(_body.left, _body.top - 60, 100, 20));
		swprintf_s(str, L"name : %s", _pokemon->getName().c_str());
		DTDMANAGER->printText(str, dRectMake(_body.left, _body.top - 40, 100, 20));
		swprintf_s(str, L"state : %d", _pokemon->getState());
		DTDMANAGER->printText(str, dRectMake(_body.left, _body.top - 20, 100, 20));

		DTDMANAGER->Rectangle(_body);
	}

	_pokemon->render(_x, _y);
}

int Enemy::input()
{
	if (_pathList.size() <= 0) {
		_pattern->init(this);
		_pattern->update();
	}

	_playerState = POKEMON_STATE_MOVE;
	_initX = _x;
	_initY = _y;
	_destX = _pathList[0]->getIdX();
	_destY = _pathList[0]->getIdY();
	_pathList.erase(_pathList.begin());
	setDirect();

	return _playerState;
}

void Enemy::setDirect()
{
	_direct = 0;

	if (_x != _destX) {
		if (_x < _destX)
			_direct |= RIGHT;
		else
			_direct |= LEFT;
	}

	if (_y != _destY) {
		if (_y > _destY)
			_direct |= UP;
		else
			_direct |= DOWN;
	}
}
