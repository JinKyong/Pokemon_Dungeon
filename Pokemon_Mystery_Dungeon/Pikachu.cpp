#include "stdafx.h"
#include "Pikachu.h"

Pikachu::Pikachu()
{
	//�̸�
	_name = L"��ī��";
	_num = 5;

	//Ÿ�� & Ư��
	_type = POKEMON_TYPE_ELECTRIC;
	//Ư�� _passive;

	//����
}

Pikachu::~Pikachu()
{
}

HRESULT Pikachu::init()
{
	//�̹���
	_stateImage[POKEMON_STATE_IDLE] = IMAGEMANAGER->addFrameDImage("pikachu_idle",
		L"img/pokemon/5. pikachu/idle.png", 60, 594, 1, 11);
	_stateImage[POKEMON_STATE_MOVE] = IMAGEMANAGER->addFrameDImage("pikachu_move",
		L"img/pokemon/5. pikachu/move.png", 208, 594, 4, 11);
	_stateImage[POKEMON_STATE_ATTACK] = IMAGEMANAGER->addFrameDImage("pikachu_attack",
		L"img/pokemon/5. pikachu/attack.png", 120, 594, 2, 11);
	_stateImage[POKEMON_STATE_SATTACK] = IMAGEMANAGER->addFrameDImage("pikachu_sattack",
		L"img/pokemon/5. pikachu/sattack.png", 112, 594, 2, 11);
	_stateImage[POKEMON_STATE_HURT] = IMAGEMANAGER->addFrameDImage("pikachu_hurt",
		L"img/pokemon/5. pikachu/hurt.png", 48, 594, 1, 11);
	_stateImage[POKEMON_STATE_SLEEP] = IMAGEMANAGER->addFrameDImage("pikachu_sleep",
		L"img/pokemon/5. pikachu/sleep.png", 96, 48, 2, 1);
	_stateImage[POKEMON_STATE_DEFAULT] = IMAGEMANAGER->addFrameDImage("pikachu_default",
		L"img/pokemon/5. pikachu/default.png", 60, 594, 1, 11);

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

void Pikachu::release()
{
}