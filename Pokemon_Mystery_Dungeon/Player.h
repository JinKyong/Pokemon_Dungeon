#pragma once
#include "Pokemon.h"

class Player
{
private:
	Pokemon* _pokemon;

public:
	HRESULT init();
	void release();
	void update();
	void render();






	Pokemon* getPokemon() { return _pokemon; }
	void setPokemon(Pokemon* pokemon) { _pokemon = pokemon; }
};

