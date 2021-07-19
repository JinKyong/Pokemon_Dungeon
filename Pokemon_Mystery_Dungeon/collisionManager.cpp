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

bool collisionManager::playerWithTile(Player* player)
{
	vector<PTILE>* tile = TILEMANAGER->getvTile();

	float x = player->getX();					//�÷��̾� �� x��ǥ
	float y = player->getY();					//�÷��̾� �� y��ǥ

	int direct = player->getDirect();			//���⸶�� ����Ÿ�� �ϳ��� �˻�


	int tileX = (int)x / TILEWIDTH;				//�÷��̾ ���� Ÿ�� x(0 ~ 39)
	int tileY = (int)y / TILEHEIGHT;			//�÷��̾ ���� Ÿ�� y(0 ~ 39)


	int tileWidth = TILEMANAGER->getWidth();	//���� Ÿ�� ����

	int index[4];

	//�밢�� ���� ����ó�� ��� ����

	//1. ���⺰�� �ε����� ��� �������..?

	//if ((direct & RIGHT) == RIGHT)		index = tileX + tileY * tileWidth + 1;
	//if ((direct & LEFT) == LEFT)		index = tileX + tileY * tileWidth - 1;
	//if ((direct & UP) == UP)			index = tileX + tileY * tileWidth + tileWidth;
	//if ((direct & DOWN) == DOWN)		index = tileX + tileY * tileWidth - tileWidth;

	// �̷��� ������ ����� ��� �̴ϼȶ���� �������� �ʾҴٰ� �����鼭 ����


	index[0] = tileX + tileY * tileWidth + 1;
	index[1] = tileX + tileY * tileWidth - 1;
	index[2] = tileX + tileY * tileWidth + tileWidth;
	index[3] = tileX + tileY * tileWidth - tileWidth;



	if ((*tile)[index[0]]->obj <= OBJ_BLOCK8)
		return false;

	return true;

	//�÷��̾� x, y�������� ���⿡ ���� 1Ÿ�ϸ� �˻�
	//�̵������ϸ� true, �ƴϸ� false ��ȯ
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
