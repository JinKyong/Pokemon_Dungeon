#pragma once
#include "Player.h"

class User : public Player
{
private:

public:
	virtual HRESULT init(int pokemonNum);
	virtual void release();
	virtual void update();
	virtual void render();

	virtual	int input();

	void controlKey();
	void testKey();
};