#include "stdafx.h"
#include "Squirtle.h"

Squirtle::Squirtle()
{
	//�̸�
	_name = L"���α�";
	_num = 10;


	//����(��ü��)
	_pokemonValue.hp = 44;
	_pokemonValue.attack = 48;
	_pokemonValue.defense = 65;
	_pokemonValue.sattack = 50;
	_pokemonValue.sdefense = 64;
	_pokemonValue.speed = 43;


	//Ÿ�� & Ư��
	_type[0] = POKEMON_TYPE_WATER;
	_type[1] = END_POKEMON_TYPE;

	_jump = true;
}

Squirtle::~Squirtle()
{
}

HRESULT Squirtle::init()
{
	//�̹���
	_stateImage[POKEMON_STATE_IDLE] = IMAGEMANAGER->addFrameDImage("squirtle_idle_attack",
		L"img/pokemon/10. squirtle/idle_attack.png", 138, 440, 3, 11);
	_stateImage[POKEMON_STATE_MOVE] = IMAGEMANAGER->addFrameDImage("squirtle_move",
		L"img/pokemon/10. squirtle/move.png", 184, 440, 4, 11);
	_stateImage[POKEMON_STATE_ATTACK] = _stateImage[POKEMON_STATE_IDLE];

	_stateImage[POKEMON_STATE_SATTACK] = IMAGEMANAGER->addFrameDImage("squirtle_sattack",
		L"img/pokemon/10. squirtle/sattack.png", 150, 506, 3, 11);
	_stateImage[POKEMON_STATE_HURT] = IMAGEMANAGER->addFrameDImage("squirtle_hurt",
		L"img/pokemon/10. squirtle/hurt.png", 46, 484, 1, 11);
	_stateImage[POKEMON_STATE_SLEEP] = IMAGEMANAGER->addFrameDImage("squirtle_sleep",
		L"img/pokemon/10. squirtle/sleep.png", 88, 34, 2, 1);
	_stateImage[POKEMON_STATE_DEFAULT] = IMAGEMANAGER->addFrameDImage("squirtle_default",
		L"img/pokemon/10. squirtle/default.png", 46, 440, 1, 11);

	//�ʻ�ȭ
	_portrait = IMAGEMANAGER->addDImage("squirtle_portrait",
		L"img/pokemon/10. squirtle/portrait.png", 40, 40);

	//frame
	changeDirect(DOWN);
	changeState(POKEMON_STATE_DEFAULT);

	//frameCount(���ϸ󸶴� �����������)
	_count[POKEMON_STATE_IDLE] = 0.6 / (_stateImage[POKEMON_STATE_IDLE]->getMaxFrameX() + 1);
	_count[POKEMON_STATE_MOVE] = 0.8 / (_stateImage[POKEMON_STATE_MOVE]->getMaxFrameX() + 1);
	_count[POKEMON_STATE_ATTACK] = 0.8 / (_stateImage[POKEMON_STATE_ATTACK]->getMaxFrameX() + 1);
	_count[POKEMON_STATE_SATTACK] = 0.8 / (_stateImage[POKEMON_STATE_SATTACK]->getMaxFrameX() + 1);
	_count[POKEMON_STATE_HURT] = 0.5;
	_count[POKEMON_STATE_SLEEP] = 0.5;
	_count[POKEMON_STATE_DEFAULT] = 0.5;

	//���º� �̼�����
	_tuningX = 0;
	_tuningY = 0;

	//attack 2�� �Լ�
	_interceptX = _count[POKEMON_STATE_ATTACK] * (_stateImage[POKEMON_STATE_ATTACK]->getMaxFrameX() + 1);
	_interceptY = 3 * TILEWIDTH / 4;
	_gradient = -_interceptY / (_interceptX * _interceptX);


	return S_OK;
}

void Squirtle::release()
{
}
