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

	//충돌하는 객체들 파악하기
	//플레이어랑 에너미
	//플레이어랑 아이템

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
