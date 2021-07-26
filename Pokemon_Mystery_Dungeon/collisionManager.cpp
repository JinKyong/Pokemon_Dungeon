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
	index[UP | RIGHT] = index[UP] + 1;
	index[UP | LEFT] = index[UP] - 1;
	index[DOWN | RIGHT] = index[DOWN] + 1;
	index[DOWN | LEFT] = index[DOWN] - 1;


	int direct = player->getDirect();			//���⸶�� ����Ÿ�� �ϳ��� �˻�
	//�¿�
	if ((direct & RIGHT) == RIGHT) {
		if ((*_allTile)[index[RIGHT]]->terrain <= TR_BLOCK)		return false;
		directCount |= RIGHT;
	}
	else if ((direct & LEFT) == LEFT) {
		if ((*_allTile)[index[LEFT]]->terrain <= TR_BLOCK)		return false;
		directCount |= LEFT;
	}

	//����
	if ((direct & UP) == UP) {
		if ((*_allTile)[index[UP]]->terrain <= TR_BLOCK)		return false;
		directCount |= UP;
	}
	else if ((direct & DOWN) == DOWN) {
		if ((*_allTile)[index[DOWN]]->terrain <= TR_BLOCK)		return false;
		directCount |= DOWN;
	}

	//�밢
	if ((*_allTile)[index[directCount]]->terrain <= TR_BLOCK)	return false;


	return true;
}

bool collisionManager::playerWithPlayer(Player * player)
{
	int tileWidth = TILEMANAGER->getWidth();	//���� Ÿ�� ����

	int directCount;
	int playerIndex = player->getY() * tileWidth + player->getX();
	int index[11] = { 0, };

	//8���� �ε���
	index[RIGHT] = playerIndex + 1;
	index[LEFT] = playerIndex - 1;
	index[UP] = playerIndex - tileWidth;
	index[DOWN] = playerIndex + tileWidth;
	index[UP | RIGHT] = index[UP] + 1;
	index[UP | LEFT] = index[UP] - 1;
	index[DOWN | RIGHT] = index[DOWN] + 1;
	index[DOWN | LEFT] = index[DOWN] - 1;

	vector<Player*>::iterator playerIter;

	for (playerIter = _allPlayer->begin(); playerIter != _allPlayer->end(); ++playerIter)
	{
		if ((*playerIter) == player) continue;

		directCount = 0;
		int destX = (*playerIter)->getDestX();
		int	destY = (*playerIter)->getDestY();

		int direct = player->getDirect();			//���⸶�� ����Ÿ�� �ϳ��� �˻�
		//�¿�
		if ((direct & RIGHT) == RIGHT) {
			if ((*_allTile)[index[RIGHT]]->x == destX &&
				(*_allTile)[index[RIGHT]]->y == destY)		return false;
			directCount |= RIGHT;
		}
		else if ((direct & LEFT) == LEFT) {
			if ((*_allTile)[index[LEFT]]->x == destX &&
				(*_allTile)[index[LEFT]]->y == destY)		return false;
			directCount |= LEFT;
		}

		//����
		if ((direct & UP) == UP) {
			if ((*_allTile)[index[UP]]->x == destX &&
				(*_allTile)[index[UP]]->y == destY)		return false;
			directCount |= UP;
		}
		else if ((direct & DOWN) == DOWN) {
			if ((*_allTile)[index[DOWN]]->x == destX &&
				(*_allTile)[index[DOWN]]->y == destY)		return false;
			directCount |= DOWN;
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

	if (player->getPlayerType() == PLAYER_TYPE_ENEMY)
		collisionDetection(player);
}

void collisionManager::playerWithItem(Player* player)
{
	for (int i = 0; i < _allItem->size(); i++)
	{
		RECT temp;
		if (IntersectRect(&temp, &player->getBody(), &(*_allItem)[i]->getBody()))
		{
			DIALOGMANAGER->addItemLog(player, (*_allItem)[i]);
			if (player->getPlayerType() <= PLAYER_TYPE_TEAM)
				INVENTORYMANAGER->addItem((*_allItem)[i]);
			_scene->getItemManager()->removeItem(i);
		}
	}
}

void collisionManager::collisionDetection(Player * player)
{
	Player* user = (*TURNMANAGER->getAllPlayer())[0];

	//�ֺ� 8Ÿ�� �˻�
	if (!detectionWith8Tiles(player, user)) {
		//�� �浹 �˻�
		detectionWithRoom(player, user);
	}
}

bool collisionManager::detectionWithRoom(Player * startPlayer, Player * destPlayer)
{
	vector<RECT>* rooms = TILEMANAGER->getvRoom();
	vector<RECT>::iterator room = rooms->begin();

	RECT tmp;
	for (; room != rooms->end(); ++room) {
		//���� �� �ȿ� ������
		RECT rc = RectMake(room->left * TILEWIDTH, room->top * TILEHEIGHT,
			(room->right - room->left) * TILEWIDTH, (room->bottom - room->top) * TILEHEIGHT);
		if (IntersectRect(&tmp, &startPlayer->getBody(), &rc)) {
			//�ش� �� �ȿ� �÷��̾ �ִ��� �˻�
			if (IntersectRect(&tmp, &destPlayer->getBody(), &rc)) {
				startPlayer->changePattern(PLAYER_PATTERN_ONATTACK);
				return true;
			}
		}
	}

	//����� �ƴϰų� �濡 ������ ���ų�
	return false;
}

bool collisionManager::detectionWith8Tiles(Player * startPlayer, Player * destPlayer)
{
	int tileWidth = TILEMANAGER->getWidth();	//���� Ÿ�� ����

	//8���� �ε���
	int initX = startPlayer->getX() - 1;
	int endX = startPlayer->getX() + 1;
	int initY = startPlayer->getY() - 1;
	int endY = startPlayer->getY() + 1;

	int destX = destPlayer->getDestX();
	int destY = destPlayer->getDestY();

	for (int i = initY; i <= endY; i++) {
		for (int j = initX; j <= endX; j++) {
			if (i == startPlayer->getY() && j == startPlayer->getX()) continue;

			if ((*_allTile)[i * tileWidth + j]->x == destX &&
				(*_allTile)[i * tileWidth + j]->y == destY) {
				startPlayer->setDestX(destX);
				startPlayer->setDestY(destY);
				startPlayer->changePattern(PLAYER_PATTERN_ONATTACK);

				return true;
			}
		}
	}

	return false;
}

void collisionManager::effectWithEnemy(Effect * effect)
{
	RECT temp;
	vector<Player*>::iterator playerIter;
	bool fail = true;

	for (playerIter = _allPlayer->begin(); playerIter != _allPlayer->end(); ++playerIter)
	{
		if (IntersectRect(&temp, &(*playerIter)->getBody(), &effect->getBody()))
		{
			//�������� ���(��) -> ���ʹ�
			//�������� ����(��) -> ��(���� ����)
			//�� ��쿡�� �浹�� ó��
			if ((effect->getDamage() > 0 && (*playerIter)->getPlayerType() == PLAYER_TYPE_ENEMY) ||
				(effect->getDamage() < 0 && (*playerIter)->getPlayerType() <= PLAYER_TYPE_TEAM)) {

				SOUNDMANAGER->play("hitDamage");
				(*playerIter)->getPokemon()->changeState(POKEMON_STATE_HURT);
				(*playerIter)->hitDamage(BATTLEMANAGER->damageCalculation((*playerIter), effect));

				//HP�� 0���� �������� -> �ٷ� ����� ����
				if ((*playerIter)->getCurrentHP() <= 0)
					(*playerIter)->getPokemon()->setDeath(true);

				TURNMANAGER->setPause(true);
				fail = false;
				break;
			}
		}
	}

	if (fail)
		DIALOGMANAGER->failSkillLog();
}