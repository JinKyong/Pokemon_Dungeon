#include "stdafx.h"
#include "Dragonite.h"

Dragonite::Dragonite()
{
	//�̸�
	_name = L"������";
	_num = 15;

	//Ÿ�� & Ư��
	_type[0] = POKEMON_TYPE_DRAGON;
	_type[1] = POKEMON_TYPE_FLYING;
	//Ư�� _passive;

	//����(��ü��)


	_jump = false;
}

Dragonite::~Dragonite()
{
}

HRESULT Dragonite::init()
{
	//�̹���
	_stateImage[POKEMON_STATE_IDLE] = IMAGEMANAGER->addFrameDImage("dragonite_idle",
		L"img/pokemon/15. dragonite/idle.png", 124, 770, 2, 11);
	_stateImage[POKEMON_STATE_MOVE] = IMAGEMANAGER->addFrameDImage("dragonite_move",
		L"img/pokemon/15. dragonite/move.png", 248, 770, 4, 11);
	_stateImage[POKEMON_STATE_ATTACK] = IMAGEMANAGER->addFrameDImage("dragonite_attack",
		L"img/pokemon/15. dragonite/attack.png", 198, 726, 3, 11);
	_stateImage[POKEMON_STATE_SATTACK] = IMAGEMANAGER->addFrameDImage("dragonite_sattack",
		L"img/pokemon/15. dragonite/sattack.png", 66, 682, 1, 11);
	_stateImage[POKEMON_STATE_HURT] = IMAGEMANAGER->addFrameDImage("dragonite_hurt",
		L"img/pokemon/15. dragonite/hurt.png", 66, 836, 1, 11);
	_stateImage[POKEMON_STATE_SLEEP] = IMAGEMANAGER->addFrameDImage("dragonite_sleep",
		L"img/pokemon/15. dragonite/sleep.png", 108, 56, 2, 1);
	_stateImage[POKEMON_STATE_DEFAULT] = IMAGEMANAGER->addFrameDImage("dragonite_default",
		L"img/pokemon/15. dragonite/default.png", 62, 770, 1, 11);

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

void Dragonite::release()
{
}
