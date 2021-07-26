#include "stdafx.h"
#include "PatternOnAttack.h"

HRESULT PatternOnAttack::init(Player * player)
{
	Pattern::init(player);

	if (!_pathFinder) {
		_pathFinder = new PathFinder;
		_pathFinder->init();
	}
	_pathFinder->resetPathList();

	return S_OK;
}

void PatternOnAttack::release()
{
}

void PatternOnAttack::update()
{
	//����� ��ΰ� ������ ���� �� ã��
	//if(collisionmanager->room player) true�� �ǽð����� ã��
	//else false�� ��� �ѹ� ã��
	_pathFinder->setTiles(_player, (*TURNMANAGER->getAllPlayer())[0]);
	_pathFinder->update();
	_pathList = _pathFinder->getPathList();

	//�浹 �˻�
	//�ֺ� 8Ÿ�Ͽ� ������ ����
	if (COLLISIONMANAGER->detectionWith8Tiles(_player, (*TURNMANAGER->getAllPlayer())[0])) {
		int num = RND->getInt(4);
		Skill** skill = _player->getSkill();

		if (skill[num])
			_player->useSkill(num);
		else
			_player->useSkill(-1);
	}
	else {
		//������ ã�ư�
		if (COLLISIONMANAGER->playerWithPlayer(_player)) {
			//������ ����
			_player->setDestX(_pathList[0]->getIdX());
			_player->setDestY(_pathList[0]->getIdY());

			_pathList.erase(_pathList.begin());
			_player->setPlayerState(POKEMON_STATE_MOVE);
		}
		else {
			//_player->setDirect();

			//_pathList.erase(_pathList.begin());
			_player->setPlayerState(POKEMON_STATE_MOVE);
		}
	}
}

void PatternOnAttack::render()
{
}
