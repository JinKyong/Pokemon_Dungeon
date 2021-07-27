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
	//if(collisionmanager->room player) true�� �ǽð����� ã��
	//else false�� ��� �ѹ� ã��
	_pathFinder->setTiles(_player, (*TURNMANAGER->getAllPlayer())[0]);
	_pathFinder->update();
	_pathList = _pathFinder->getPathList();

	//������ ����
	_player->setDestX(_pathList[0]->getIdX());
	_player->setDestY(_pathList[0]->getIdY());
	_player->setDirect();

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
			//_pathList.erase(_pathList.begin());
			_player->setPlayerState(POKEMON_STATE_MOVE);
		}
		else {
			//���⿡ ���� �˻�
			detour();
		}
	}
}

void PatternOnAttack::render()
{
}

void PatternOnAttack::detour()
{
	int direct = _player->getDirect();
	switch (direct) {
	case RIGHT:
		_player->setDestX(_player->getX() + 1);
		_player->setDestY(_player->getY() - 1);
		_player->setDirect();
		if (COLLISIONMANAGER->collisionInputPlayer(_player)) {
			//_pathList.erase(_pathList.begin());
			_player->setPlayerState(POKEMON_STATE_MOVE);
		}
		else {
			_player->setDestX(_player->getX() + 1);
			_player->setDestY(_player->getY() + 1);
			_player->setDirect();
			if (COLLISIONMANAGER->collisionInputPlayer(_player)) {
				//_pathList.erase(_pathList.begin());
				_player->setPlayerState(POKEMON_STATE_MOVE);
			}
			else {
				_player->setDestX(_pathList[0]->getIdX());
				_player->setDestY(_pathList[0]->getIdY());
				_player->setDirect();
				_player->setPlayerState(POKEMON_STATE_DEFAULT);
			}
		}
		break;
	case LEFT:
		_player->setDestX(_player->getX() - 1);
		_player->setDestY(_player->getY() - 1);
		_player->setDirect();
		if (COLLISIONMANAGER->collisionInputPlayer(_player)) {
			//_pathList.erase(_pathList.begin());
			_player->setPlayerState(POKEMON_STATE_MOVE);
		}
		else {
			_player->setDestX(_player->getX() - 1);
			_player->setDestY(_player->getY() + 1);
			_player->setDirect();
			if (COLLISIONMANAGER->collisionInputPlayer(_player)) {
				//_pathList.erase(_pathList.begin());
				_player->setPlayerState(POKEMON_STATE_MOVE);
			}
			else {
				_player->setDestX(_pathList[0]->getIdX());
				_player->setDestY(_pathList[0]->getIdY());
				_player->setDirect();
				_player->setPlayerState(POKEMON_STATE_DEFAULT);
			}
		}
		break;

	case UP:
		_player->setDestX(_player->getX() + 1);
		_player->setDestY(_player->getY() - 1);
		_player->setDirect();
		if (COLLISIONMANAGER->collisionInputPlayer(_player)) {
			//_pathList.erase(_pathList.begin());
			_player->setPlayerState(POKEMON_STATE_MOVE);
		}
		else {
			_player->setDestX(_player->getX() - 1);
			_player->setDestY(_player->getY() - 1);
			_player->setDirect();
			if (COLLISIONMANAGER->collisionInputPlayer(_player)) {
				//_pathList.erase(_pathList.begin());
				_player->setPlayerState(POKEMON_STATE_MOVE);
			}
			else {
				_player->setDestX(_pathList[0]->getIdX());
				_player->setDestY(_pathList[0]->getIdY());
				_player->setDirect();
				_player->setPlayerState(POKEMON_STATE_DEFAULT);
			}
		}
		break;
	case DOWN:
		_player->setDestX(_player->getX() + 1);
		_player->setDestY(_player->getY() + 1);
		_player->setDirect();
		if (COLLISIONMANAGER->collisionInputPlayer(_player)) {
			//_pathList.erase(_pathList.begin());
			_player->setPlayerState(POKEMON_STATE_MOVE);
		}
		else {
			_player->setDestX(_player->getX() - 1);
			_player->setDestY(_player->getY() + 1);
			_player->setDirect();
			if (COLLISIONMANAGER->collisionInputPlayer(_player)) {
				//_pathList.erase(_pathList.begin());
				_player->setPlayerState(POKEMON_STATE_MOVE);
			}
			else {
				_player->setDestX(_pathList[0]->getIdX());
				_player->setDestY(_pathList[0]->getIdY());
				_player->setDirect();
				_player->setPlayerState(POKEMON_STATE_DEFAULT);
			}
		}
		break;

	case RIGHT | UP:
		_player->setDestX(_player->getX());
		_player->setDestY(_player->getY() - 1);
		_player->setDirect();
		if (COLLISIONMANAGER->collisionInputPlayer(_player)) {
			//_pathList.erase(_pathList.begin());
			_player->setPlayerState(POKEMON_STATE_MOVE);
		}
		else {
			_player->setDestX(_player->getX() + 1);
			_player->setDestY(_player->getY());
			_player->setDirect();
			if (COLLISIONMANAGER->collisionInputPlayer(_player)) {
				//_pathList.erase(_pathList.begin());
				_player->setPlayerState(POKEMON_STATE_MOVE);
			}
			else {
				_player->setDestX(_pathList[0]->getIdX());
				_player->setDestY(_pathList[0]->getIdY());
				_player->setDirect();
				_player->setPlayerState(POKEMON_STATE_DEFAULT);
			}
		}
		break;
	case LEFT | UP:
		_player->setDestX(_player->getX());
		_player->setDestY(_player->getY() - 1);
		_player->setDirect();
		if (COLLISIONMANAGER->collisionInputPlayer(_player)) {
			//_pathList.erase(_pathList.begin());
			_player->setPlayerState(POKEMON_STATE_MOVE);
		}
		else {
			_player->setDestX(_player->getX() - 1);
			_player->setDestY(_player->getY());
			_player->setDirect();
			if (COLLISIONMANAGER->collisionInputPlayer(_player)) {
				//_pathList.erase(_pathList.begin());
				_player->setPlayerState(POKEMON_STATE_MOVE);
			}
			else {
				_player->setDestX(_pathList[0]->getIdX());
				_player->setDestY(_pathList[0]->getIdY());
				_player->setDirect();
				_player->setPlayerState(POKEMON_STATE_DEFAULT);
			}
		}
		break;

	case RIGHT | DOWN:
		_player->setDestX(_player->getX() + 1);
		_player->setDestY(_player->getY());
		_player->setDirect();
		if (COLLISIONMANAGER->collisionInputPlayer(_player)) {
			//_pathList.erase(_pathList.begin());
			_player->setPlayerState(POKEMON_STATE_MOVE);
		}
		else {
			_player->setDestX(_player->getX());
			_player->setDestY(_player->getY() + 1);
			_player->setDirect();
			if (COLLISIONMANAGER->collisionInputPlayer(_player)) {
				//_pathList.erase(_pathList.begin());
				_player->setPlayerState(POKEMON_STATE_MOVE);
			}
			else {
				_player->setDestX(_pathList[0]->getIdX());
				_player->setDestY(_pathList[0]->getIdY());
				_player->setDirect();
				_player->setPlayerState(POKEMON_STATE_DEFAULT);
			}
		}
		break;
	case LEFT | DOWN:
		_player->setDestX(_player->getX() - 1);
		_player->setDestY(_player->getY());
		_player->setDirect();
		if (COLLISIONMANAGER->collisionInputPlayer(_player)) {
			//_pathList.erase(_pathList.begin());
			_player->setPlayerState(POKEMON_STATE_MOVE);
		}
		else {
			_player->setDestX(_player->getX());
			_player->setDestY(_player->getY() + 1);
			_player->setDirect();
			if (COLLISIONMANAGER->collisionInputPlayer(_player)) {
				//_pathList.erase(_pathList.begin());
				_player->setPlayerState(POKEMON_STATE_MOVE);
			}
			else {
				_player->setDestX(_pathList[0]->getIdX());
				_player->setDestY(_pathList[0]->getIdY());
				_player->setDirect();
				_player->setPlayerState(POKEMON_STATE_DEFAULT);
			}
		}
		break;

	default:
		break;
	}
}
