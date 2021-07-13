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





	Pokemon* makePokemon(int num) { return (this->*_pokemonList[num])(); }

	//======================== 포켓몬 도감 ========================//
	Pokemon* charmander() { return new Charmander; }
	Pokemon* charmeleon() { return new Charmeleon; }
	Pokemon* charizard() { return new Charizard; }

	Pokemon* pichu() { return new Pichu; }
	Pokemon* pikachu() { return new Pikachu; }
	Pokemon* raichu() { return new Raichu; }
};