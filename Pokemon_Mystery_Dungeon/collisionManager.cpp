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

	float x = player->getX();					//�÷��̾� x��ǥ
	float y = player->getY();					//�÷��̾� y��ǥ
	int direct = player->getDirect();			//���⸶�� ����Ÿ�� �ϳ��� �˻�

	int tileWidth = TILEMANAGER->getWidth();	//���� Ÿ�� ����

	int index[4];

	//�밢�� ���� ����ó�� ��� ����

	//1. ���⺰�� �ε����� ��� �������..?

	//if ((direct & RIGHT) == RIGHT)		index = tileX + tileY * tileWidth + 1;
	//if ((direct & LEFT) == LEFT)		index = tileX + tileY * tileWidth - 1;
	//if ((direct & UP) == UP)			index = tileX + tileY * tileWidth + tileWidth;
	//if ((direct & DOWN) == DOWN)		index = tileX + tileY * tileWidth - tileWidth;

	// �̷��� ������ ����� ��� �̴ϼȶ���� �������� �ʾҴٰ� �����鼭 ����


	index[0] = x + y * tileWidth + 1;
	index[1] = x + y * tileWidth - 1;
	index[2] = x + y * tileWidth + tileWidth;
	index[3] = x + y * tileWidth - tileWidth;

	if ((*tile)[index[0]]->obj <= OBJ_BLOCK8)
		return false;

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
