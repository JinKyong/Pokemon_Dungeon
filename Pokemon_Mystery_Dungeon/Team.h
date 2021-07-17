#pragma once
#include "Player.h"

class Team : public Player
{
public:
	virtual HRESULT init(int pokemonNum);
	virtual void release();
	virtual void update();
	virtual void render();

	virtual	int input();
};
