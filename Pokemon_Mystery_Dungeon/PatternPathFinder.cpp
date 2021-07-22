#include "stdafx.h"
#include "PatternPathFinder.h"

HRESULT PatternPathFinder::init(Player * player)
{
	Pattern::init(player);

	_pathFinder = new PathFinder;
	_pathFinder->init();

	return S_OK;
}

void PatternPathFinder::release()
{
}

void PatternPathFinder::update()
{
	//����� ��ΰ� ������ ���� �� ã��
	if (_pathList.size() <= 0) {
		_pathFinder->setTiles(_player);
		_pathFinder->update();
		_pathList = _pathFinder->getPathList();
	}

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
		_player->changePattern(PLAYER_PATTERN_ONATTACK);
		_player->setPlayerState(POKEMON_STATE_ATTACK);
		_player->getPokemon()->setAttack(true);
	}
}

void PatternPathFinder::render()
{

}