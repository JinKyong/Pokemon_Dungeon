#pragma once
#include "singletonBase.h"
#include <vector>

class Player;
class Scene;
class ItemManager;
class Effect;

class collisionManager : public singletonBase<collisionManager>
{
private:
	Player* _player;
	Scene* _scene;
	ItemManager* _im;

	vector<Player*> *_allPlayer;

	//�浹�ϴ� ��ü�� �ľ��ϱ�
	//�÷��̾�� ���ʹ�
	//�÷��̾�� ������

public:
	collisionManager() {};
	~collisionManager() {};

	void release();

	HRESULT init(Scene* scene, ItemManager* im);

	void collisionPlayer(Player* player);
	bool playerWithTile(Player* player);
	void playerWithItem(Player* player);
	void playerWithEnemy(Player* player, Player* enemy);

	void effectWithEnemy(Effect* effect);
};
