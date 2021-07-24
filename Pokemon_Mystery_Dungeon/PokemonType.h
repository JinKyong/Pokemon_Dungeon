#pragma once

enum POKEMON_STATE {
	POKEMON_STATE_IDLE,
	POKEMON_STATE_MOVE,
	POKEMON_STATE_ATTACK,
	POKEMON_STATE_SATTACK,
	POKEMON_STATE_HURT,
	POKEMON_STATE_SLEEP,
	POKEMON_STATE_DEFAULT,
	END_POKEMON_STATE
};

typedef struct tagPokemonStat {
	int hp;
	int attack;
	int defense;
	int sattack;
	int sdefense;
	int speed;
}STAT, *PSTAT;

enum POKEMON_TYPE {
	POKEMON_TYPE_NORMAL,
	POKEMON_TYPE_FIGHTING,
	POKEMON_TYPE_POISON,
	POKEMON_TYPE_GROUND,
	POKEMON_TYPE_FLYING,
	POKEMON_TYPE_BUG,
	POKEMON_TYPE_ROCK,
	POKEMON_TYPE_GHOST,
	POKEMON_TYPE_STEEL,
	POKEMON_TYPE_FIRE,
	POKEMON_TYPE_WATER,
	POKEMON_TYPE_ELECTRIC,
	POKEMON_TYPE_GRASS,
	POKEMON_TYPE_ICE,
	POKEMON_TYPE_PSYCHIC,
	POKEMON_TYPE_DRAGON,
	POKEMON_TYPE_DARK,
	END_POKEMON_TYPE
};