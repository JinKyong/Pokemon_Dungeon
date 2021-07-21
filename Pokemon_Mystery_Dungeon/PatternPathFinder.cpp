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
	//저장된 경로가 없으면 새로 길 찾기
	if (_pathList.size() <= 0) {
		_pathFinder->setTiles(_player);
		_pathFinder->update();
		_pathList = _pathFinder->getPathList();
	}

	//목적지 정하고 방향 설정
	_player->setDestX(_pathList[0]->getIdX());
	_player->setDestY(_pathList[0]->getIdY());
	_player->setDirect();

	//충돌 검사
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