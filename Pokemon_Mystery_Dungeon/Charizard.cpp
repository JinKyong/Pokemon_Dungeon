#include "stdafx.h"
#include "Charizard.h"

Charizard::Charizard()
{
	//�̸�
	_name = L"���ڸ�";
	_num = 3;

	//Ÿ�� & Ư��
	_type[0] = POKEMON_TYPE_FIRE;
	_type[1] = END_POKEMON_TYPE;
	//Ư�� _passive;

	//����(��ü��)


	_jump = true;
}

Charizard::~Charizard()
{
}

HRESULT Charizard::init()
{
	//�̹���
	_stateImage[POKEMON_STATE_IDLE] = IMAGEMANAGER->addFrameDImage("charizard_idle",
		L"img/pokemon/3. charizard/idle.png", 198, 660, 3, 11);
	_stateImage[POKEMON_STATE_MOVE] = IMAGEMANAGER->addFrameDImage("charizard_move",
		L"img/pokemon/3. charizard/move.png", 264, 660, 4, 11);
	_stateImage[POKEMON_STATE_ATTACK] = IMAGEMANAGER->addFrameDImage("charizard_attack",
		L"img/pokemon/3. charizard/attack.png", 328, 726, 4, 11);
	_stateImage[POKEMON_STATE_SATTACK] = IMAGEMANAGER->addFrameDImage("charizard_sattack",
		L"img/pokemon/3. charizard/sattack.png", 160, 704, 2, 11);
	_stateImage[POKEMON_STATE_HURT] = IMAGEMANAGER->addFrameDImage("charizard_hurt",
		L"img/pokemon/3. charizard/hurt.png", 62, 704, 1, 11);
	_stateImage[POKEMON_STATE_SLEEP] = IMAGEMANAGER->addFrameDImage("charizard_sleep",
		L"img/pokemon/3. charizard/sleep.png", 108, 58, 2, 1);
	_stateImage[POKEMON_STATE_DEFAULT] = IMAGEMANAGER->addFrameDImage("charizard_default",
		L"img/pokemon/3. charizard/default.png", 66, 660, 1, 11);

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
	_count[POKEMON_STATE_DEFAULT] = 0.3;

	//���º� �̼�����
	_tuningX = 0;
	_tuningY = 0;

	//attack 2�� �Լ�
	_interceptX = _count[POKEMON_STATE_ATTACK] * (_stateImage[POKEMON_STATE_ATTACK]->getMaxFrameX() + 1);
	_interceptY = 3 * TILEWIDTH / 4;
	_gradient = -_interceptY / (_interceptX * _interceptX);


	return S_OK;
}

void Charizard::release()
{
}
