#include "stdafx.h"
#include "collisionManager.h"
#include "Player.h"
#include "ItemManager.h"
#include "Scene.h"

void collisionManager::release()
{
}

HRESULT collisionManager::init(Scene * scene, ItemManager* im)
{
	_scene = scene;
	_im = im;

	_allPlayer = TURNMANAGER->getAllPlayer();
	return S_OK;
}

void collisionManager::collisionPlayer(Player* player)
{
	playerWithItem(player);
}

void collisionManager::playerWithTile(Player* player)
{
	float x = player->getX();
	float y = player->getY();

	//플레이어 x, y기준으로 방향에 따라 1타일만 검사
	//이동가능하면 true, 아니면 false 반환
}

void collisionManager::playerWithItem(Player* player)
{
	for (int i = 0; i < _im->getVItem().size(); i++)
	{
		RECT temp;
		if (IntersectRect(&temp, &player->getBody(), &_im->getVItem()[i]->getBody()))
		{
			DIALOGMANAGER->addItemLog(player, _im->getVItem()[i]);
			_im->removeItem(i);
		}
	}
}

void collisionManager::playerWithEnemy(Player * player, Player* enemy)
{
	//RECT temp;
	//if (IntersectRect(&temp, &player->getBody(), &enemy->getBody()))
	//{
	//	
	//	
	//}
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
