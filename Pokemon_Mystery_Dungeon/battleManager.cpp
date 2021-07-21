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

int battleManager::damageCalculation()								//����Ʈ ��������
{
	_rndNum = RND->getFromIntTo(217, 256) * 100 / 255;									//������

	int rndCri = RND->getFloat(100);													//�޼�
	if (rndCri > 6.25f) _critical = 1;
	else				_critical = 2;

	//if (_player->getPlayerType() == SKILLDEX->fireBlast()->getSkillType()) _type = 2;	//�ڼ�
	//else																   _type = 1;
	//
	//
	//
	//
	//_damage = (((((((_player->getLevel() * 2 / 5) + 2) * 50 * _player->getSpAtk() / 50) /
	//	_enemy->getSpDef()) + 2) * _critical * _rndNum / 100) * _type * 1 * 1);

	return _damage;
}



//���� �������� �Լ� �߰�


//4���� ������ ���
//(������ = (((((((���� �� 2 �� 5) + 2) �� ���� �� Ư������ �� 50) �� Ư�����) + 2) �� [[�޼�]] ��  ������ �� 100) �� �ڼӺ��� �� Ÿ�Ի�1 �� Ÿ�Ի�2)
					//������� ����Ʈ ������						�������� �浹ó����					(�ڼӺ����� ��ų���� bool������)

//2���� ������ ���
//(������ = (���� �� ���� �� (���� �� 2 �� 5 + 2 ) �� ��� �� 50 �� [[�޼�]] + 2 ) �� [[�ڼ� ����]] �� Ÿ�Ի�1 �� Ÿ�Ի�2 �� ������/255)

/*
������ ���Ŀ� �ʿ��Ѱ�
����,
��ų���ݷ�(����),
(�����ϴ¾�)Ư�����ݷ�,
(�ĸ´¾�)Ư������,
�޼��� 6.25 % (�޼� ������ 2 ����)
������((217~255 ������ ������ ��) �� 100) �� 255, �Ҽ��� ���� ����.
�ڼӺ���(��ųŸ��, ���ϸ�Ÿ���� ��ġ�ϸ� 1.5 ����)
Ÿ�Ի�(ȿ�����پ2, ȿ������0.5, ȿ������ 0)
*/