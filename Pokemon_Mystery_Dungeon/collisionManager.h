#pragma once
#include "singletonBase.h"
#include "tileInfo.h"
#include <vector>

class Player;
class Scene;
class Item;
class Effect;

class collisionManager : public singletonBase<collisionManager>
{
private:
	Scene* _scene;
	vector<tagTile*>* _allTile;		//Ÿ�� ���
	vector<Item*>* _allItem;		//������ ���
	vector<Player*>* _allPlayer;	//�÷��̾� ���

	//�浹�ϴ� ��ü�� �ľ��ϱ�
	//�÷��̾�� ���ʹ�
	//�÷��̾�� ������

public:
	collisionManager() {};
	~collisionManager() {};

	HRESULT init(Scene* scene);
	void release();

	//Player �浹(�Է� ��)
	bool collisionInputPlayer(Player* player);
	bool playerWithTile(Player* player);
	bool playerWithPlayer(Player* player);
	
	//Player �浹(���� ��)
	void collisionEndTurnPlayer(Player* player);
	void playerWithItem(Player* player);
	void playerWithObject(Player* player);

	//�������� �浹
	void collisionDetection(Player* player);
	bool detectionWithRoom(Player* startPlayer, Player* destPlayer);
	bool detectionWith8Tiles(Player* startPlayer, Player* destPlayer);

	//����Ʈ �浹
	void effectWithEnemy(Effect* effect);
};
