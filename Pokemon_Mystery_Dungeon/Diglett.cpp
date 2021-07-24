#include "stdafx.h"
#include "Diglett.h"

Diglett::Diglett()
{
	//�̸�
	_name = L"��״�";
	_num = 26;


	//����(��ü��)
	_pokemonValue.hp = 10;
	_pokemonValue.attack = 55;
	_pokemonValue.defense = 25;
	_pokemonValue.sattack = 35;
	_pokemonValue.sdefense = 45;
	_pokemonValue.speed = 95;


	//Ÿ�� & Ư��
	_type[0] = POKEMON_TYPE_GROUND;
	_type[1] = END_POKEMON_TYPE;

	_jump = false;
}

Diglett::~Diglett()
{
}

HRESULT Diglett::init()
{
	//�̹���
	_stateImage[POKEMON_STATE_IDLE] = IMAGEMANAGER->addFrameDImage("diglett_idle",
		L"img/pokemon/26. diglett/idle.png", 46, 418, 1, 11);
	_stateImage[POKEMON_STATE_MOVE] = IMAGEMANAGER->addFrameDImage("diglett_move",
		L"img/pokemon/26. diglett/move.png", 192, 506, 3, 11);
	_stateImage[POKEMON_STATE_ATTACK] = IMAGEMANAGER->addFrameDImage("diglett_attack",
		L"img/pokemon/26. diglett/attack.png", 138, 418, 3, 11);
	_stateImage[POKEMON_STATE_SATTACK] = IMAGEMANAGER->addFrameDImage("diglett_sattack",
		L"img/pokemon/26. diglett/sattack.png", 92, 418, 2, 11);
	_stateImage[POKEMON_STATE_HURT] = IMAGEMANAGER->addFrameDImage("diglett_hurt",
		L"img/pokemon/26. diglett/hurt.png", 46, 550, 1, 11);
	_stateImage[POKEMON_STATE_SLEEP] = IMAGEMANAGER->addFrameDImage("diglett_sleep",
		L"img/pokemon/26. diglett/sleep.png", 88, 32, 2, 1);
	_stateImage[POKEMON_STATE_DEFAULT] = IMAGEMANAGER->addFrameDImage("diglett_default",
		L"img/pokemon/26. diglett/default.png", 46, 418, 1, 11);

	//�ʻ�ȭ
	_portrait = IMAGEMANAGER->addDImage("diglett_portrait",
		L"img/pokemon/26. diglett/portrait.png", 40, 40);

	//frame
	changeDirect(DOWN);
	changeState(POKEMON_STATE_DEFAULT);

	//frameCount(���ϸ󸶴� �����������)
	_count[POKEMON_STATE_IDLE] = 0.8 / (_stateImage[POKEMON_STATE_IDLE]->getMaxFrameX() + 1);
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

void Diglett::release()
{
}
