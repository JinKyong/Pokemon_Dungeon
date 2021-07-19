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

bool collisionManager::collisionInputPlayer(Player * player)
{
	vector<PTILE>* tile = TILEMANAGER->getvTile();

	float x = player->getX();					//플레이어 x좌표
	float y = player->getY();					//플레이어 y좌표
	int direct = player->getDirect();			//방향마다 다음타일 하나만 검사

	int tileWidth = TILEMANAGER->getWidth();	//가로 타일 갯수

	int index[4];

	//대각선 방향 예외처리 어떻게 할지

	//1. 방향별로 인덱스를 어떻게 줘야할지..?

	//if ((direct & RIGHT) == RIGHT)		index = tileX + tileY * tileWidth + 1;
	//if ((direct & LEFT) == LEFT)		index = tileX + tileY * tileWidth - 1;
	//if ((direct & UP) == UP)			index = tileX + tileY * tileWidth + tileWidth;
	//if ((direct & DOWN) == DOWN)		index = tileX + tileY * tileWidth - tileWidth;

	// 이렇게 방향을 줬더니 멤버 이니셜라이즈를 선언하지 않았다고 나오면서 터짐


	index[0] = x + y * tileWidth + 1;
	index[1] = x + y * tileWidth - 1;
	index[2] = x + y * tileWidth + tileWidth;
	index[3] = x + y * tileWidth - tileWidth;

	if ((*tile)[index[0]]->obj <= OBJ_BLOCK8)
		return false;

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
