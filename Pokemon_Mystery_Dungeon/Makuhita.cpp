#include "stdafx.h"
#include "Makuhita.h"

Makuhita::Makuhita()
{
	//�̸�
	_name = L"��ũ��";
	_num = 35;


	//����(��ü��)
	_pokemonValue.hp = 72;
	_pokemonValue.attack = 60;
	_pokemonValue.defense = 30;
	_pokemonValue.sattack = 20;
	_pokemonValue.sdefense = 30;
	_pokemonValue.speed = 25;


	//Ÿ�� & Ư��
	_type[0] = POKEMON_TYPE_FIGHTING;
	_type[1] = END_POKEMON_TYPE;

	_jump = false;
}

Makuhita::~Makuhita()
{
}

HRESULT Makuhita::init()
{
	Pokemon::init();

	//�̹���
	_stateImage[POKEMON_STATE_IDLE] = IMAGEMANAGER->addFrameDImage("makuhita_idle",
		L"img/pokemon/35. makuhita/idle.png", 180, 660, 3, 11);
	_stateImage[POKEMON_STATE_MOVE] = IMAGEMANAGER->addFrameDImage("makuhita_move",
		L"img/pokemon/35. makuhita/move.png", 240, 660, 4, 11);
	_stateImage[POKEMON_STATE_ATTACK] = IMAGEMANAGER->addFrameDImage("makuhita_attack",
		L"img/pokemon/35. makuhita/attack.png", 300, 660, 5, 11);
	_stateImage[POKEMON_STATE_SATTACK] = IMAGEMANAGER->addFrameDImage("makuhita_sattack",
		L"img/pokemon/35. makuhita/sattack.png", 60, 660, 1, 11);
	_stateImage[POKEMON_STATE_HURT] = IMAGEMANAGER->addFrameDImage("makuhita_hurt",
		L"img/pokemon/35. makuhita/hurt.png", 56, 660, 1, 11);
	_stateImage[POKEMON_STATE_SLEEP] = IMAGEMANAGER->addFrameDImage("makuhita_sleep",
		L"img/pokemon/35. makuhita/sleep.png", 128, 52, 2, 1);
	_stateImage[POKEMON_STATE_DEFAULT] = IMAGEMANAGER->addFrameDImage("makuhita_default",
		L"img/pokemon/35. makuhita/default.png", 60, 660, 1, 11);

	//�ʻ�ȭ
	_portrait = IMAGEMANAGER->addDImage("makuhita_portrait",
		L"img/pokemon/35. makuhita/portrait.png", 40, 40);

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
