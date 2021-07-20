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

bool collisionManager::collisionInputPlayer(Player * player)		// User, Enemy �ȿ� �Լ� �θ�
{
	vector<PTILE>* tile = TILEMANAGER->getvTile();

	int x = player->getX();						//�÷��̾� x��ǥ
	int y = player->getY();						//�÷��̾� y��ǥ
	int direct = player->getDirect();			//���⸶�� ����Ÿ�� �ϳ��� �˻�

	int tileWidth = TILEMANAGER->getWidth();	//���� Ÿ�� ����

	int index[4];								//4���� Ÿ�� �����
	int cornerIndex[4];							//�밢�� Ÿ�� �����

	index[0] = x + y * tileWidth + 1;						//������
	index[1] = x + y * tileWidth - 1;						//����
	index[2] = x + y * tileWidth + tileWidth;				//�Ʒ�
	index[3] = x + y * tileWidth - tileWidth;				//��

	cornerIndex[0] = x + 1 + y * tileWidth + tileWidth;		//������ �Ʒ�
	cornerIndex[1] = x - 1 + y * tileWidth + tileWidth;		//���� �Ʒ�
	cornerIndex[2] = x + 1 + y * tileWidth - tileWidth;		//������ ��
	cornerIndex[3] = x - 1 + y * tileWidth - tileWidth;		//���� ��

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

	//�÷��̾� destX, destY

	return true;

	//�÷��̾� x, y�������� ���⿡ ���� 1Ÿ�ϸ� �˻�
	//�̵������ϸ� true, �ƴϸ� false ��ȯ
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
