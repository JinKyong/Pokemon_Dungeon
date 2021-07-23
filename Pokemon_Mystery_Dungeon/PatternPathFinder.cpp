#include "stdafx.h"
#include "PatternPathFinder.h"

HRESULT PatternPathFinder::init(Player * player)
{
	Pattern::init(player);

	if (!_pathFinder) {
		_pathFinder = new PathFinder;
		_pathFinder->init();
	}
	_pathFinder->resetPathList();

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

	//충돌 검사
	if (COLLISIONMANAGER->playerWithPlayer(_player)) {
		//목적지 설정
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

void PatternPathFinder::render()
{

}