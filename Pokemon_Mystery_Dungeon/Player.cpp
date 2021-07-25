#include "stdafx.h"
#include "Player.h"
#include "Pattern.h"

HRESULT Player::init(int pokemonNum)
{
	//포켓몬
	_pokemon = POKEDEX->makePokemon(pokemonNum);
	_pokemon->init();

	_level = 5;
	_EXP = 0;

	_realStat = BATTLEMANAGER->statCalculation(this);
	_currentHP = _realStat.hp;

	return S_OK;
}

HRESULT Player::init(float x, float y)
{
	//허기
	_starve = 100;

	//좌표
	_initX = _destX = _x = x;
	_initY = _destY = _y = y;
	_body = RectMakeCenter(_x * TILEWIDTH + TILEWIDTH / 2, _y * TILEHEIGHT + TILEHEIGHT / 2,
		TILEWIDTH, TILEHEIGHT);

	return S_OK;
}

void Player::release()
{
}

void Player::update()
{
	//방향 설정하고 포켓몬 상태 업데이트
	setDirect();

	//상태에 따라 함수 호출
	switch (_playerState) {
	case POKEMON_STATE_MOVE:
		_pokemon->changeState(_playerState);
		move();
		break;
	case POKEMON_STATE_ATTACK:
		attack();
		_pokemon->changeState(_playerState);
		break;
	case POKEMON_STATE_SATTACK:
		sattack();
		_pokemon->changeState(_playerState);
		break;
	default:
		break;
	}

	_body = RectMakeCenter(_x * TILEWIDTH + TILEWIDTH / 2, _y * TILEHEIGHT + TILEHEIGHT / 2,
		TILEWIDTH, TILEHEIGHT);

	_pokemon->update();
}

void Player::render()
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

void Player::changePattern(PLAYER_PATTERN pattern)
{
	if (_currentPattern == pattern) return;


	//패턴 갱신
	_currentPattern = pattern;
	_pattern[_currentPattern]->init(this);
}

void Player::setDirect()
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

	if (_direct)
		_pokemon->changeDirect(_direct);
}

void Player::resetXY()
{
	_initX = _destX = _x;
	_initY = _destY = _y;
}

void Player::move()
{
	if (_x != _destX)	_x += cosf(_pokemon->getAngle()) / 16;
	if (_y != _destY)	_y += -sinf(_pokemon->getAngle()) / 16;

	float limit = 1.4142;
	if (_direct == RIGHT || _direct == LEFT || _direct == UP || _direct == DOWN) limit = 1.0;

	//이동 시작지점과 현재 위치 거리가 타일 1칸이상이 되면 (== 이동거리가 타일 1칸이상되면) 이동 끝
	//이전에는 이동 목적지와 현재 위치 거리가 일정 거리만큼 가까워지면 이동 끝
	if (getDistance(_initX, _initY, _x, _y) >= limit ||
		getDistance(_destX, _destY, _x, _y) <= limit / 16) {
		_x = _destX;
		_y = _destY;

		//_pokemon->changeState(POKEMON_STATE_DEFAULT);
		_playerState = POKEMON_STATE_DEFAULT;
	}
}

void Player::attack()
{
	if (!_pokemon->getAttack()) {
		_playerState = POKEMON_STATE_DEFAULT;
		return;
	}

}

void Player::sattack()
{
	if (!_pokemon->getSattack()) {
		_playerState = POKEMON_STATE_DEFAULT;
		return;
	}

	if (_selectedSkill) {
		_selectedSkill->useSkill();
		DIALOGMANAGER->useSkillLog(this, _selectedSkill);
		_selectedSkill = nullptr;
	}

}

void Player::useSkill(int num)
{
	_selectedSkill = _skill[num];
	_playerState = POKEMON_STATE_SATTACK;
	_pokemon->setSattack(true);
}

void Player::hitDamage(int num)
{
	_currentHP -= num;
}