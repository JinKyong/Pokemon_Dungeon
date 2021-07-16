#include "stdafx.h"
#include "Ivysaur.h"

Ivysaur::Ivysaur()
{
	//�̸�
	_name = L"�̻���Ǯ";
	_num = 8;

	//Ÿ�� & Ư��
	_type[0] = POKEMON_TYPE_GRASS;
	_type[1] = POKEMON_TYPE_POISON;
	//Ư�� _passive;

	//����(��ü��)


	_jump = false;
}

Ivysaur::~Ivysaur()
{
}

HRESULT Ivysaur::init()
{
	//�̹���
	_stateImage[POKEMON_STATE_IDLE] = IMAGEMANAGER->addFrameDImage("ivysaur_idle",
		L"img/pokemon/8. ivysaur/idle.png", 150, 484, 3, 11);
	_stateImage[POKEMON_STATE_MOVE] = IMAGEMANAGER->addFrameDImage("ivysaur_move",
		L"img/pokemon/8. ivysaur/move.png", 200, 506, 4, 11);
	_stateImage[POKEMON_STATE_ATTACK] = IMAGEMANAGER->addFrameDImage("ivysaur_attack",
		L"img/pokemon/8. ivysaur/attack.png", 92, 506, 2, 11);
	_stateImage[POKEMON_STATE_SATTACK] = IMAGEMANAGER->addFrameDImage("ivysaur_sattack",
		L"img/pokemon/8. ivysaur/sattack.png", 92, 572, 2, 11);
	_stateImage[POKEMON_STATE_HURT] = IMAGEMANAGER->addFrameDImage("ivysaur_hurt",
		L"img/pokemon/8. ivysaur/hurt.png", 50, 484, 1, 11);
	_stateImage[POKEMON_STATE_SLEEP] = IMAGEMANAGER->addFrameDImage("ivysaur_sleep",
		L"img/pokemon/8. ivysaur/sleep.png", 88, 44, 2, 1);
	_stateImage[POKEMON_STATE_DEFAULT] = IMAGEMANAGER->addFrameDImage("ivysaur_default",
		L"img/pokemon/8. ivysaur/default.png", 50, 484, 1, 11);

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

void Ivysaur::release()
{
}
