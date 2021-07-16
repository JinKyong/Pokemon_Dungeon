#pragma once
#include "Player.h"

class User : public Player
{
private:
	int _num;

public:
	virtual HRESULT init(int pokemonNum);
	virtual void release();
	virtual void update();
	virtual void render();

	virtual	int input();

	void controlKey();
	void testKey();
};