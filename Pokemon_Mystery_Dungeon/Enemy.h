#pragma once
#include "Player.h"
#include <vector>

class Pattern;
class Atile;

class Enemy : public Player
{
private:
	Pattern* _pattern;

public:
	virtual HRESULT init(int pokemonNum);
	virtual void release();
	virtual void update();
	virtual void render();

	virtual	int input();

	void setDirect();
};

