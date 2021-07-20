#include "stdafx.h"
#include "collisionManager.h"
#include "Scene.h"
#include "ItemManager.h"
#include "Player.h"


HRESULT collisionManager::init(Scene * scene)
{
	_scene = scene;

	//_allTile = TILEMANAGER->getvTile();
	_allItem = _scene->getItemManager()->getVItem();
	_allPlayer = TURNMANAGER->getAllPlayer();

	return S_OK;
}

void collisionManager::release()
{
}

bool collisionManager::collisionInputPlayer(Player * player)		// User, Enemy 안에 함수 부름
{
	vector<PTILE>* tile = TILEMANAGER->getvTile();

	int x = player->getX();						//플레이어 x좌표
	int y = player->getY();						//플레이어 y좌표
	int direct = player->getDirect();			//방향마다 다음타일 하나만 검사

	int tileWidth = TILEMANAGER->getWidth();	//가로 타일 갯수

	int index[4];								//4방향 타일 검출용
	int cornerIndex[4];							//대각선 타일 검출용

	index[0] = x + y * tileWidth + 1;						//오른쪽
	index[1] = x + y * tileWidth - 1;						//왼쪽
	index[2] = x + y * tileWidth + tileWidth;				//아래
	index[3] = x + y * tileWidth - tileWidth;				//위

	cornerIndex[0] = x + 1 + y * tileWidth + tileWidth;		//오른쪽 아래
	cornerIndex[1] = x - 1 + y * tileWidth + tileWidth;		//왼쪽 아래
	cornerIndex[2] = x + 1 + y * tileWidth - tileWidth;		//오른쪽 위
	cornerIndex[3] = x - 1 + y * tileWidth - tileWidth;		//왼쪽 위

	if ((direct & RIGHT) == RIGHT && (*tile)[index[0]]->obj <= OBJ_BLOCK8)	return false;
	if ((direct & LEFT) == LEFT && (*tile)[index[1]]->obj <= OBJ_BLOCK8)	return false;
	if ((direct & DOWN) == DOWN && (*tile)[index[2]]->obj <= OBJ_BLOCK8)	return false;
	if ((direct & UP) == UP && (*tile)[index[3]]->obj <= OBJ_BLOCK8)		return false;

	if (((direct & RIGHT) == RIGHT && (direct & DOWN) == DOWN) &&
		(*tile)[cornerIndex[0]]->obj <= OBJ_BLOCK8) return false;

	if (((direct & LEFT) == LEFT && (direct & DOWN) == DOWN) &&
		(*tile)[cornerIndex[1]]->obj <= OBJ_BLOCK8) return false;

	if (((direct & RIGHT) == RIGHT && (direct & UP) == UP) &&
		(*tile)[cornerIndex[2]]->obj <= OBJ_BLOCK8) return false;

	if (((direct & LEFT) == LEFT && (direct & UP) == UP) &&
		(*tile)[cornerIndex[3]]->obj <= OBJ_BLOCK8) return false;

	//if ((direct & RIGHT) == RIGHT && (*tile)[index[0]]->x == x) return false;

	vector<Player*>::iterator playerIter;

	for (playerIter = _allPlayer->begin(); playerIter != _allPlayer->end(); ++playerIter)
	{
		int x, y;
		if ((*playerIter)->getPlayerType() == PLAYER_TYPE_ENEMY)
		{
			x = (*playerIter)->getDestX();
			y = (*playerIter)->getDestY();
		}
		else
		{
			x = (*playerIter)->getX();
			y = (*playerIter)->getY();
		}


		if ((direct & RIGHT) == RIGHT && (*tile)[index[0]]->x == x && (*tile)[index[0]]->y == y) return false;

		if ((direct & LEFT) == LEFT && (*tile)[index[1]]->x == x && (*tile)[index[1]]->y == y) return false;

		if ((direct & DOWN) == DOWN && (*tile)[index[2]]->x == x && (*tile)[index[2]]->y == y) return false;

		if ((direct & UP) == UP && (*tile)[index[3]]->x == x && (*tile)[index[3]]->y == y) return false;

	}

	//플레이어 destX, destY

	return true;

	//플레이어 x, y기준으로 방향에 따라 1타일만 검사
	//이동가능하면 true, 아니면 false 반환
}

void collisionManager::collisionEndTurnPlayer(Player* player)
{
	playerWithItem(player);
}

void collisionManager::playerWithItem(Player* player)
{
	for (int i = 0; i < _allItem->size(); i++)
	{
		RECT temp;
		if (IntersectRect(&temp, &player->getBody(), &(*_allItem)[i]->getBody()))
		{
			DIALOGMANAGER->addItemLog(player, (*_allItem)[i]);
			if(player->getPlayerType() <= PLAYER_TYPE_TEAM)
				INVENTORYMANAGER->addItem((*_allItem)[i]);
			_scene->getItemManager()->removeItem(i);
		}
	}
}

void collisionManager::effectWithEnemy(Effect * effect)
{
	RECT temp;

	vector<Player*>::iterator playerIter;

	for (playerIter = _allPlayer->begin(); playerIter != _allPlayer->end(); ++playerIter)
	{
		if (IntersectRect(&temp, &(*playerIter)->getBody(), &effect->getBody()))
		{
			(*playerIter)->getPokemon()->changeState(POKEMON_STATE_HURT);
			(*playerIter)->hitDamage(40);
			TURNMANAGER->setPause(true);
		}
	}
}
