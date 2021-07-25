#include "stdafx.h"
#include "Charmeleon.h"

Charmeleon::Charmeleon()
{
	//�̸�
	_name = L"���ڵ�";
	_num = 2;


	//����(��ü��)
	_pokemonValue.hp = 58;
	_pokemonValue.attack = 64;
	_pokemonValue.defense = 58;
	_pokemonValue.sattack = 80;
	_pokemonValue.sdefense = 65;
	_pokemonValue.speed = 80;


	//Ÿ�� & Ư��
	_type[0] = POKEMON_TYPE_FIRE;
	_type[1] = END_POKEMON_TYPE;

	_jump = false;
}

Charmeleon::~Charmeleon()
{
}

HRESULT Charmeleon::init()
{
	Pokemon::init();

	//�̹���
	_stateImage[POKEMON_STATE_IDLE] = IMAGEMANAGER->addFrameDImage("charmeleon_idle",
		L"img/pokemon/2. charmeleon/idle.png", 54, 594, 1, 11);
	_stateImage[POKEMON_STATE_MOVE] = IMAGEMANAGER->addFrameDImage("charmeleon_move",
		L"img/pokemon/2. charmeleon/move.png", 192, 528, 4, 11);
	_stateImage[POKEMON_STATE_ATTACK] = IMAGEMANAGER->addFrameDImage("charmeleon_attack",
		L"img/pokemon/2. charmeleon/attack.png", 192, 704, 3, 11);
	_stateImage[POKEMON_STATE_SATTACK] = IMAGEMANAGER->addFrameDImage("charmeleon_sattack",
		L"img/pokemon/2. charmeleon/sattack.png", 128, 594, 2, 11);
	_stateImage[POKEMON_STATE_HURT] = IMAGEMANAGER->addFrameDImage("charmeleon_hurt",
		L"img/pokemon/2. charmeleon/hurt.png", 52, 638, 1, 11);
	_stateImage[POKEMON_STATE_SLEEP] = IMAGEMANAGER->addFrameDImage("charmeleon_sleep",
		L"img/pokemon/2. charmeleon/sleep.png", 96, 48, 2, 1);
	_stateImage[POKEMON_STATE_DEFAULT] = IMAGEMANAGER->addFrameDImage("charmeleon_default",
		L"img/pokemon/2. charmeleon/default.png", 54, 594, 1, 11);

	//�ʻ�ȭ
	_portrait = IMAGEMANAGER->addDImage("charmeleon_portrait",
		L"img/pokemon/2. charmeleon/portrait.png", 40, 40);

	//frame
	changeDirect(DOWN);
	changeState(POKEMON_STATE_DEFAULT);

	//frameCount(���ϸ󸶴� �����������)
	_count[POKEMON_STATE_IDLE] = 0.6 / (_stateImage[POKEMON_STATE_IDLE]->getMaxFrameX() + 1);
	_count[POKEMON_STATE_MOVE] = 0.8 / (_stateImage[POKEMON_STATE_MOVE]->getMaxFrameX() + 1);
	_count[POKEMON_STATE_ATTACK] = 0.8 / (_stateImage[POKEMON_STATE_ATTACK]->getMaxFrameX() + 1);
	_count[POKEMON_STATE_SATTACK] = 0.8 / (_stateImage[POKEMON_STATE_SATTACK]->getMaxFrameX() + 1);
	_count[POKEMON_STATE_HURT] = 1.0;
	_count[POKEMON_STATE_SLEEP] = 0.5;
	_count[POKEMON_STATE_DEFAULT] = 0.8;

	//���º� �̼�����
	_tuningX = 0;
	_tuningY = 0;

	//attack 2�� �Լ�
	_interceptX = _count[POKEMON_STATE_ATTACK] * (_stateImage[POKEMON_STATE_ATTACK]->getMaxFrameX() + 1);
	_interceptY = 3 * TILEWIDTH / 4;
	_gradient = -_interceptY / (_interceptX * _interceptX);


	return S_OK;
}