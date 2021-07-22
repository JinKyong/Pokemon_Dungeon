#include "stdafx.h"
#include "Dratini.h"

Dratini::Dratini()
{
	//�̸�
	_name = L"�̴�";
	_num = 13;


	//����(��ü��)
	_pokemonValue.hp = 41;
	_pokemonValue.attack = 64;
	_pokemonValue.defense = 45;
	_pokemonValue.sattack = 50;
	_pokemonValue.sdefense = 50;
	_pokemonValue.speed = 50;


	//Ÿ�� & Ư��
	_type[0] = POKEMON_TYPE_DRAGON;
	_type[1] = END_POKEMON_TYPE;

	_jump = false;
}

Dratini::~Dratini()
{
}

HRESULT Dratini::init()
{
	//�̹���
	_stateImage[POKEMON_STATE_IDLE] = IMAGEMANAGER->addFrameDImage("dratini_idle",
		L"img/pokemon/13. dratini/idle.png", 162, 638, 3, 11);
	_stateImage[POKEMON_STATE_MOVE] = IMAGEMANAGER->addFrameDImage("dratini_move",
		L"img/pokemon/13. dratini/move.png", 216, 638, 4, 11);
	_stateImage[POKEMON_STATE_ATTACK] = IMAGEMANAGER->addFrameDImage("dratini_attack",
		L"img/pokemon/13. dratini/attack.png", 108, 638, 2, 11);
	_stateImage[POKEMON_STATE_SATTACK] = IMAGEMANAGER->addFrameDImage("dratini_sattack",
		L"img/pokemon/13. dratini/sattack.png", 124, 660, 2, 11);
	_stateImage[POKEMON_STATE_HURT] = IMAGEMANAGER->addFrameDImage("dratini_hurt",
		L"img/pokemon/13. dratini/hurt.png", 46, 748, 1, 11);
	_stateImage[POKEMON_STATE_SLEEP] = IMAGEMANAGER->addFrameDImage("dratini_sleep",
		L"img/pokemon/13. dratini/sleep.png", 76, 40, 2, 1);
	_stateImage[POKEMON_STATE_DEFAULT] = IMAGEMANAGER->addFrameDImage("dratini_default",
		L"img/pokemon/13. dratini/default.png", 54, 638, 1, 11);

	//�ʻ�ȭ
	_portrait = IMAGEMANAGER->addDImage("dratini_portrait",
		L"img/pokemon/13. dratini/portrait.png", 40, 40);

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

void Dratini::release()
{
}
