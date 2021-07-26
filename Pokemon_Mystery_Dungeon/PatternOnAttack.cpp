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
	//저장된 경로가 없으면 새로 길 찾기
	//if(collisionmanager->room player) true면 실시간으로 찾고
	//else false면 경로 한번 찾고
	_pathFinder->setTiles(_player, (*TURNMANAGER->getAllPlayer())[0]);
	_pathFinder->update();
	_pathList = _pathFinder->getPathList();

	//충돌 검사
	//주변 8타일에 있으면 공격
	if (COLLISIONMANAGER->detectionWith8Tiles(_player, (*TURNMANAGER->getAllPlayer())[0])) {
		int num = RND->getInt(4);
		Skill** skill = _player->getSkill();

		if (skill[num])
			_player->useSkill(num);
		else
			_player->useSkill(-1);
	}
	else {
		//없으면 찾아감
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
}

void PatternOnAttack::render()
{
}
