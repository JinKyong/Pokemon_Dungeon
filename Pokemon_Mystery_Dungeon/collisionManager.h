#pragma once
#include "singletonBase.h"
#include <vector>

class Player;
class Scene;
class Item;
class Effect;

class collisionManager : public singletonBase<collisionManager>
{
private:
	Scene* _scene;
	//vector<tagTile*> *_allTile;		//타일 목록
	vector<Item*> *_allItem;		//아이템 목록
	vector<Player*> *_allPlayer;	//플레이어 목록

	//충돌하는 객체들 파악하기
	//플레이어랑 에너미
	//플레이어랑 아이템

public:
	collisionManager() {};
	~collisionManager() {};

	HRESULT init(Scene* scene);
	void release();

	bool collisionInputPlayer(Player* player);

	void collisionEndTurnPlayer(Player* player);
	void playerWithItem(Player* player);


	void effectWithEnemy(Effect* effect);
};
