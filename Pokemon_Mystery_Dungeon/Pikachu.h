#pragma once
#include "Pokemon.h"

class Pikachu : public Pokemon
{
private:

public:
	HRESULT init();
	void release();
	void update();
	void render(float x, float y);
};

