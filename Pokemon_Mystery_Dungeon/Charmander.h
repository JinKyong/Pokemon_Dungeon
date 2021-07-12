#pragma once
#include "Pokemon.h"

class Charmander : public Pokemon
{
private:
	dImage* _stateImage[END_POKEMON_STATE];

public:
	HRESULT init();
	void release();
	void update();
	void render();

	void changeState(POKEMON_STATE state);
	void changeDirect(int direct);
};

