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
}