#pragma once
#include "Pokemon.h"

class Charmander : public Pokemon
{
private:
	float _tmpX, _tmpY;
	float _tmpCount;
	float _tmpCountMax;

	float _a, _p, _q;
	bool _attack;
	bool _attackDirect;

public:
	Charmander();
	~Charmander();

	HRESULT init();
	void release();
	void update();
	void render(float x, float y);

	float attackRange(float x);



	void renderImage(float x, float y);

	void renderAttack(float x, float y);
};

