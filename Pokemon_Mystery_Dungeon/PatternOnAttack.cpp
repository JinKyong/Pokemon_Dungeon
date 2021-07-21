#include "stdafx.h"
#include "PatternOnAttack.h"

HRESULT PatternOnAttack::init(Player * player)
{
	Pattern::init(player);

	_pathFinder = new PathFinder;
	_pathFinder->init();

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

	//������ ���ϰ� ���� ����
	_player->setDestX(_pathList[0]->getIdX());
	_player->setDestY(_pathList[0]->getIdY());
	_player->setDirect();

	//�浹 �˻�
	if (COLLISIONMANAGER->playerWithPlayer(_player)) {
		_pathList.erase(_pathList.begin());
		_player->setPlayerState(POKEMON_STATE_MOVE);
	}
	else {
		_player->setPlayerState(POKEMON_STATE_ATTACK);
		_player->getPokemon()->setAttack(true);
	}
}

void PatternOnAttack::render()
{
}
