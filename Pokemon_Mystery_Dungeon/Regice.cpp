#include "stdafx.h"
#include "Regice.h"

Regice::Regice()
{
	//�̸�
	_name = L"�������̽�";
	_num = 33;


	//����(��ü��)
	_pokemonValue.hp = 80;
	_pokemonValue.attack = 50;
	_pokemonValue.defense = 100;
	_pokemonValue.sattack = 100;
	_pokemonValue.sdefense = 200;
	_pokemonValue.speed = 50;


	//Ÿ�� & Ư��
	_type[0] = POKEMON_TYPE_ICE;
	_type[1] = END_POKEMON_TYPE;

	_jump = false;
}

Regice::~Regice()
{
}

HRESULT Regice::init()
{
	Pokemon::init();

	//�̹���
	_stateImage[POKEMON_STATE_IDLE] = IMAGEMANAGER->addFrameDImage("regice_idle",
		L"img/pokemon/33. regice/idle.png", 132, 726, 2, 11);
	_stateImage[POKEMON_STATE_MOVE] = IMAGEMANAGER->addFrameDImage("regice_move",
		L"img/pokemon/33. regice/move.png", 132, 726, 2, 11);
	_stateImage[POKEMON_STATE_ATTACK] = IMAGEMANAGER->addFrameDImage("regice_attack",
		L"img/pokemon/33. regice/attack.png", 132, 726, 2, 11);
	_stateImage[POKEMON_STATE_SATTACK] = IMAGEMANAGER->addFrameDImage("regice_sattack",
		L"img/pokemon/33. regice/sattack.png", 66, 726, 1, 11);
	_stateImage[POKEMON_STATE_HURT] = IMAGEMANAGER->addFrameDImage("regice_hurt",
		L"img/pokemon/33. regice/hurt.png", 70, 726, 1, 11);
	_stateImage[POKEMON_STATE_SLEEP] = IMAGEMANAGER->addFrameDImage("regice_sleep",
		L"img/pokemon/33. regice/sleep.png", 112, 56, 2, 1);
	_stateImage[POKEMON_STATE_DEFAULT] = IMAGEMANAGER->addFrameDImage("regice_default",
		L"img/pokemon/33. regice/default.png", 66, 726, 1, 11);

	//�ʻ�ȭ
	_portrait = IMAGEMANAGER->addDImage("regice_portrait",
		L"img/pokemon/33. regice/portrait.png", 40, 40);

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
