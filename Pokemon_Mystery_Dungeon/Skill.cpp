#include "stdafx.h"
#include "Skill.h"

HRESULT Skill::init(Player * player)
{
	_player = player;
	return S_OK;
}

void Skill::useSkill()		//�÷��̾� ����Ʈ�� �޾ƿͼ�		+	���������� ���� ����			//�ڼ��� bool�� or float������, ������ ������
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

	//�����°��
	_finalDamage = atkType * _damage * steb;

	if (_player->getPlayerType() == PLAYER_TYPE_ENEMY)	_finalDamage = _finalDamage * -1;		//�� ������		(����)
	else											    _finalDamage = _finalDamage;			//�Ʊ� ������	(���)
}

/*
��or Ư��->�÷��̾� �� / Ư�� and ��ų�� ����Ÿ�� �ʿ�
��ų ��ü������
�ڼ�->�÷��̾��� �Ӽ� and ��ų�� �Ӽ� �ʿ�



���ݽǴ� or Ư���Ǵ� * ������� * �ڼ� * Ư�� * ���� * ����
*/