#pragma once
#include "singletonBase.h"
#include "Pokemon.h"
#include "PokemonHeader.h"
#include <map>

class pokeDex : public singletonBase<pokeDex>
{
private:
	typedef Pokemon*(pokeDex::*func)();
	typedef map<int, func>		pokemonList;

private:
	pokemonList _pokemonList;

	int _index;

public:
	HRESULT init();
	void release();

	void addPokemon(func f);
	void setPokeDex();
	void setPokemonImg();

	Pokemon* makePokemon(int num) { return (this->*_pokemonList[num])(); }

	int getIndex() { return _index; }

	//======================== 포켓몬 도감 ========================//
	Pokemon* charmander() { return new Charmander; }
	Pokemon* charmeleon() { return new Charmeleon; }
	Pokemon* charizard() { return new Charizard; }

	Pokemon* pichu() { return new Pichu; }
	Pokemon* pikachu() { return new Pikachu; }
	Pokemon* raichu() { return new Raichu; }

	Pokemon* bulbasaur() { return new Bulbasaur; }
	Pokemon* ivysaur() { return new Ivysaur; }
	Pokemon* venusaur() { return new Venusaur; }

	Pokemon* squirtle() { return new Squirtle; }
	Pokemon* wartortle() { return new Wartortle; }
	Pokemon* blastoise() { return new Blastoise; }

	Pokemon* dratini() { return new Dratini; }
	Pokemon* dragonair() { return new Dragonair; }
	Pokemon* dragonite() { return new Dragonite; }
};