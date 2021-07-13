#pragma once
#include "Pokemon.h"

class Charizard : public Pokemon
{
private:

public:
	Charizard();
	~Charizard();

	HRESULT init();
	void release();
	void update();
	void render(float x, float y);
};

