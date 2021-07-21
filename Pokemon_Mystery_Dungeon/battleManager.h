#pragma once
#include "singletonBase.h"
class Player;

class battleManager : public singletonBase<battleManager>
{
private:
	int _damage;
	int _rndNum;
	int _critical;
	int _type;
	int _pokemonType;
	vector<Player*> *_allPlayer;

	Player* _player;
	Player* _enemy;

public:
	battleManager() {};
	~battleManager() {};

	HRESULT init();
	void release();
	void update();
	void render();

	int damageCalculation();
};

