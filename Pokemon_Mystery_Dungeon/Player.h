#pragma once
#include "Pokemon.h"
#include "SkillManager.h"

class Player
{
private:
	Pokemon* _pokemon;
	SkillManager* _sm;

	int _testNum;
public:
	HRESULT init();
	void release();
	void update();
	void render();






	Pokemon* getPokemon() { return _pokemon; }
	void setPokemon(Pokemon* pokemon) { _pokemon = pokemon; }
};

