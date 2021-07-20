#include "stdafx.h"
#include "pokeDex.h"

HRESULT pokeDex::init()
{
	_index = 0;

	setPokeDex();

	return S_OK;
}

void pokeDex::release()
{
}

void pokeDex::addPokemon(func f)
{
	_index++;
	_pokemonList.insert(make_pair(_index, f));
}

void pokeDex::setPokeDex()
{
	addPokemon(&pokeDex::charmander);
	addPokemon(&pokeDex::charmeleon);
	addPokemon(&pokeDex::charizard);

	addPokemon(&pokeDex::pichu);
	addPokemon(&pokeDex::pikachu);
	addPokemon(&pokeDex::raichu);

	addPokemon(&pokeDex::bulbasaur);
	addPokemon(&pokeDex::ivysaur);
	addPokemon(&pokeDex::venusaur);

	addPokemon(&pokeDex::squirtle);
	addPokemon(&pokeDex::wartortle);
	addPokemon(&pokeDex::blastoise);

	addPokemon(&pokeDex::dratini);
	addPokemon(&pokeDex::dragonair);
	addPokemon(&pokeDex::dragonite);
}
