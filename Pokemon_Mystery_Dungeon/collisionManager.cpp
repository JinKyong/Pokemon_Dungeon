#include "stdafx.h"
#include "collisionManager.h"
#include "Scene.h"
#include "ItemManager.h"
#include "Player.h"


HRESULT collisionManager::init(Scene * scene)
{
	_scene = scene;

	_allTile = TILEMANAGER->getvTile();
	_allItem = _scene->getItemManager()->getVItem();
	_allPlayer = TURNMANAGER->getAllPlayer();

	return S_OK;
}

void collisionManager::release()
{
}

bool collisionManager::collisionInputPlayer(Player * player)		// User, Enemy �ȿ� �Լ� �θ�
{
	if (!playerWithTile(player)) return false;
	if (!playerWithPlayer(player)) return false;

	return true;
	//�÷��̾� x, y�������� ���⿡ ���� 1Ÿ�ϸ� �˻�
	//�̵������ϸ� true, �ƴϸ� false ��ȯ
}

bool collisionManager::playerWithTile(Player * player)
{
	int tileWidth = TILEMANAGER->getWidth();	//���� Ÿ�� ����

	int directCount = 0;
	int playerIndex = player->getY() * tileWidth + player->getX();
	int index[11] = { 0, };

	//8���� �ε���
	index[RIGHT] = playerIndex + 1;
	index[LEFT] = playerIndex - 1;
	index[UP] = playerIndex - tileWidth;
	index[DOWN] = playerIndex + tileWidth;
	index[UP + RIGHT] = index[UP] + 1;
	index[UP + LEFT] = index[UP] - 1;
	index[DOWN + RIGHT] = index[DOWN] + 1;
	index[DOWN + LEFT] = index[DOWN] - 1;


	int direct = player->getDirect();			//���⸶�� ����Ÿ�� �ϳ��� �˻�
	//�¿�
	if ((direct & RIGHT) == RIGHT) {
		if ((*_allTile)[index[RIGHT]]->obj <= OBJ_BLOCK8)		return false;
		directCount += RIGHT;
	}
	else if ((direct & LEFT) == LEFT) {
		if ((*_allTile)[index[LEFT]]->obj <= OBJ_BLOCK8)		return false;
		directCount += LEFT;
	}

	//����
	if ((direct & UP) == UP) {
		if ((*_allTile)[index[UP]]->obj <= OBJ_BLOCK8)		return false;
		directCount += UP;
	}
	else if ((direct & DOWN) == DOWN) {
		if ((*_allTile)[index[DOWN]]->obj <= OBJ_BLOCK8)		return false;
		directCount += DOWN;
	}

	//�밢
	if ((*_allTile)[index[directCount]]->obj <= OBJ_BLOCK8)	return false;


	return true;
}

bool collisionManager::playerWithPlayer(Player * player)
{
	int tileWidth = TILEMANAGER->getWidth();	//���� Ÿ�� ����

	int directCount = 0;
	int playerIndex = player->getY() * tileWidth + player->getX();
	int index[11] = { 0, };

	//8���� �ε���
	index[RIGHT] = playerIndex + 1;
	index[LEFT] = playerIndex - 1;
	index[UP] = playerIndex - tileWidth;
	index[DOWN] = playerIndex + tileWidth;
	index[UP + RIGHT] = index[UP] + 1;
	index[UP + LEFT] = index[UP] - 1;
	index[DOWN + RIGHT] = index[DOWN] + 1;
	index[DOWN + LEFT] = index[DOWN] - 1;

	vector<Player*>::iterator playerIter;

	for (playerIter = _allPlayer->begin(); playerIter != _allPlayer->end(); ++playerIter)
	{
		if ((*playerIter) == player) continue;

		int destX, destY;

		if (player->getPlayerType() == PLAYER_TYPE_ENEMY)
		{
			destX = (*playerIter)->getDestX();
			destY = (*playerIter)->getDestY();
		}
		else
		{
			destX = (*playerIter)->getX();
			destY = (*playerIter)->getY();
		}


		int direct = player->getDirect();			//���⸶�� ����Ÿ�� �ϳ��� �˻�
		//�¿�
		if ((direct & RIGHT) == RIGHT) {
			if ((*_allTile)[index[RIGHT]]->x == destX &&
				(*_allTile)[index[RIGHT]]->y == destY)		return false;
			directCount += RIGHT;
		}
		else if ((direct & LEFT) == LEFT) {
			if ((*_allTile)[index[LEFT]]->x == destX &&
				(*_allTile)[index[LEFT]]->y == destY)		return false;
			directCount += LEFT;
		}

		//����
		if ((direct & UP) == UP) {
			if ((*_allTile)[index[UP]]->x == destX &&
				(*_allTile)[index[UP]]->y == destY)		return false;
			directCount += UP;
		}
		else if ((direct & DOWN) == DOWN) {
			if ((*_allTile)[index[DOWN]]->x == destX &&
				(*_allTile)[index[DOWN]]->y == destY)		return false;
			directCount += DOWN;
		}

		//�밢
		if ((*_allTile)[index[directCount]]->x == destX &&
			(*_allTile)[index[directCount]]->y == destY)	return false;
	}

	return true;
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
