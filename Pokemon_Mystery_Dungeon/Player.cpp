#include "stdafx.h"
#include "Player.h"

HRESULT Player::init(int pokemonNum)
{
	//���ϸ�
	_pokemon = POKEDEX->makePokemon(pokemonNum);
	_pokemon->init();

	return S_OK;
}

HRESULT Player::init(float x, float y)
{
	//��ǥ
	_x = x;
	_y = y;
	_destX = _x;
	_destY = _y;
	_body = RectMakeCenter(_x * TILEWIDTH + TILEWIDTH / 2, _y * TILEHEIGHT + TILEHEIGHT / 2,
		TILEWIDTH, TILEHEIGHT);

	return S_OK;
}

void Player::move()
{
	_pokemon->changeDirect(_direct);
	_pokemon->changeState(_playerState);

	if (_x != _destX)	_x += cosf(_pokemon->getAngle()) / 16;
	if (_y != _destY)	_y += -sinf(_pokemon->getAngle()) / 16;

	float limit = 1.4142;
	if (_direct == RIGHT || _direct == LEFT || _direct == UP || _direct == DOWN) limit = 1.0;

	//�̵� ���������� ���� ��ġ �Ÿ��� Ÿ�� 1ĭ�̻��� �Ǹ� (== �̵��Ÿ��� Ÿ�� 1ĭ�̻�Ǹ�) �̵� ��
	//�������� �̵� �������� ���� ��ġ �Ÿ��� ���� �Ÿ���ŭ ��������� �̵� ��
	if (getDistance(_initX, _initY, _x, _y) >= limit) {
		_x = _destX;
		_y = _destY;

		//_pokemon->changeState(POKEMON_STATE_DEFAULT);
		_playerState = POKEMON_STATE_DEFAULT;
	}
}

void Player::attack()
{
	if (_pokemon->getState() == POKEMON_STATE_DEFAULT) {
		_playerState = _pokemon->getState();
		return;
	}

	_pokemon->changeState(_playerState);
}

void Player::sattack()
{
	_pokemon->changeState(_playerState);

	if (_selectedSkill) {
		_selectedSkill->useSkill(_x, _y, _pokemon->getDirect());
		DIALOGMANAGER->useSkillLog(this, _selectedSkill);
		_selectedSkill = nullptr;
	}
}

void Player::hitDamage(int num)
{
	_testHP -= num;
}
