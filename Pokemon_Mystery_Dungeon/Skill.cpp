#include "stdafx.h"
#include "Skill.h"

HRESULT Skill::init(Player * player)
{
	_player = player;
	return S_OK;
}

void Skill::useSkill()		//�÷��̾� ����Ʈ�� �޾ƿͼ�		+	���������� ���� ����			//�ڼ��� bool�� or float������, ������ ������
{
	//if (_currentPP <= 0) return;

	int direct = _player->getPokemon()->getDirect();

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

	_finalDamage = BATTLEMANAGER->skillCalculation(_player, this);
}

/*
��or Ư��->�÷��̾� �� / Ư�� and ��ų�� ����Ÿ�� �ʿ�
��ų ��ü������
�ڼ�->�÷��̾��� �Ӽ� and ��ų�� �Ӽ� �ʿ�



���ݽǴ� or Ư���Ǵ� * ������� * �ڼ� * Ư�� * ���� * ����
*/