#include "stdafx.h"
#include "Zubat.h"

Zubat::Zubat()
{
	//�̸�
	_name = L"�꺪";
	_num = 16;


	//����(��ü��)
	_pokemonValue.hp = 40;
	_pokemonValue.attack = 45;
	_pokemonValue.defense = 35;
	_pokemonValue.sattack = 30;
	_pokemonValue.sdefense = 40;
	_pokemonValue.speed = 55;


	//Ÿ�� & Ư��
	_type[0] = POKEMON_TYPE_POISON;
	_type[1] = POKEMON_TYPE_FLYING;

	_jump = true;
}

Zubat::~Zubat()
{
}

HRESULT Zubat::init()
{
	//�̹���
	_stateImage[POKEMON_STATE_IDLE] = IMAGEMANAGER->addFrameDImage("zubat_idle",
		L"img/pokemon/16. zubat/idle.png", 174, 550, 3, 11);
	_stateImage[POKEMON_STATE_MOVE] = IMAGEMANAGER->addFrameDImage("zubat_move_attack",
		L"img/pokemon/16. zubat/move_attack.png", 232, 550, 4, 11);
	_stateImage[POKEMON_STATE_ATTACK] = _stateImage[POKEMON_STATE_MOVE];

	_stateImage[POKEMON_STATE_SATTACK] = IMAGEMANAGER->addFrameDImage("zubat_sattack_default",
		L"img/pokemon/16. zubat/sattack_default.png", 58, 550, 1, 11);
	_stateImage[POKEMON_STATE_HURT] = IMAGEMANAGER->addFrameDImage("zubat_hurt",
		L"img/pokemon/16. zubat/hurt.png", 54, 594, 1, 11);
	_stateImage[POKEMON_STATE_SLEEP] = IMAGEMANAGER->addFrameDImage("zubat_sleep",
		L"img/pokemon/16. zubat/sleep.png", 108, 30, 2, 1);
	_stateImage[POKEMON_STATE_DEFAULT] = _stateImage[POKEMON_STATE_SATTACK];


	//�ʻ�ȭ
	_portrait = IMAGEMANAGER->addDImage("zubat_portrait",
		L"img/pokemon/16. zubat/portrait.png", 40, 40);

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

void Zubat::release()
{
}
