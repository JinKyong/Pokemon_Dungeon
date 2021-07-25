#include "stdafx.h"
#include "Espeon.h"

Espeon::Espeon()
{
	//�̸�
	_name = L"������";
	_num = 24;


	//����(��ü��)
	_pokemonValue.hp = 65;
	_pokemonValue.attack = 65;
	_pokemonValue.defense = 60;
	_pokemonValue.sattack = 130;
	_pokemonValue.sdefense = 95;
	_pokemonValue.speed = 110;


	//Ÿ�� & Ư��
	_type[0] = POKEMON_TYPE_PSYCHIC;
	_type[1] = END_POKEMON_TYPE;

	_jump = false;
}

Espeon::~Espeon()
{
}

HRESULT Espeon::init()
{
	Pokemon::init();

	//�̹���
	_stateImage[POKEMON_STATE_IDLE] = IMAGEMANAGER->addFrameDImage("espeon_idle",
		L"img/pokemon/24. espeon/idle.png", 186, 704, 3, 11);
	_stateImage[POKEMON_STATE_MOVE] = IMAGEMANAGER->addFrameDImage("espeon_move_attack",
		L"img/pokemon/24. espeon/move_attack.png", 248, 682, 4, 11);
	_stateImage[POKEMON_STATE_ATTACK] = _stateImage[POKEMON_STATE_MOVE];

	_stateImage[POKEMON_STATE_SATTACK] = IMAGEMANAGER->addFrameDImage("espeon_sattack",
		L"img/pokemon/24. espeon/sattack.png", 124, 682, 2, 11);
	_stateImage[POKEMON_STATE_HURT] = IMAGEMANAGER->addFrameDImage("espeon_hurt",
		L"img/pokemon/24. espeon/hurt.png", 62, 682, 1, 11);
	_stateImage[POKEMON_STATE_SLEEP] = IMAGEMANAGER->addFrameDImage("espeon_sleep",
		L"img/pokemon/24. espeon/sleep.png", 100, 44, 2, 1);
	_stateImage[POKEMON_STATE_DEFAULT] = IMAGEMANAGER->addFrameDImage("espeon_default",
		L"img/pokemon/24. espeon/default.png", 62, 704, 1, 11);

	//�ʻ�ȭ
	_portrait = IMAGEMANAGER->addDImage("espeon_portrait",
		L"img/pokemon/24. espeon/portrait.png", 40, 40);

	//frame
	changeDirect(DOWN);
	changeState(POKEMON_STATE_DEFAULT);

	//frameCount(���ϸ󸶴� �����������)
	_count[POKEMON_STATE_IDLE] = 0.8 / (_stateImage[POKEMON_STATE_IDLE]->getMaxFrameX() + 1);
	_count[POKEMON_STATE_MOVE] = 0.8 / (_stateImage[POKEMON_STATE_MOVE]->getMaxFrameX() + 1);
	_count[POKEMON_STATE_ATTACK] = 0.8 / (_stateImage[POKEMON_STATE_ATTACK]->getMaxFrameX() + 1);
	_count[POKEMON_STATE_SATTACK] = 0.8 / (_stateImage[POKEMON_STATE_SATTACK]->getMaxFrameX() + 1);
	_count[POKEMON_STATE_HURT] = 1.0;
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
