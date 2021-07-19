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
	//vector<tagTile*> *_allTile;		//Ÿ�� ���
	vector<Item*> *_allItem;		//������ ���
	vector<Player*> *_allPlayer;	//�÷��̾� ���

	//�浹�ϴ� ��ü�� �ľ��ϱ�
	//�÷��̾�� ���ʹ�
	//�÷��̾�� ������

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
