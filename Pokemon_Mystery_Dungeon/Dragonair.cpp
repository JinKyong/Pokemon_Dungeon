#include "stdafx.h"
#include "Dragonair.h"

Dragonair::Dragonair()
{
	//�̸�
	_name = L"�Ŵ�";
	_num = 14;

	//Ÿ�� & Ư��
	_type[0] = POKEMON_TYPE_DRAGON;
	_type[1] = END_POKEMON_TYPE;
	//Ư�� _passive;

	//����(��ü��)


	_jump = false;
}

Dragonair::~Dragonair()
{
}

HRESULT Dragonair::init()
{
	//�̹���
	_stateImage[POKEMON_STATE_IDLE] = IMAGEMANAGER->addFrameDImage("dragonair_idle_move",
		L"img/pokemon/14. dragonair/idle_move.png", 258, 836, 3, 11);
	_stateImage[POKEMON_STATE_MOVE] = _stateImage[POKEMON_STATE_IDLE];

	_stateImage[POKEMON_STATE_ATTACK] = IMAGEMANAGER->addFrameDImage("dragonair_attack",
		L"img/pokemon/14. dragonair/attack.png", 512, 1188, 4, 11);
	_stateImage[POKEMON_STATE_SATTACK] = IMAGEMANAGER->addFrameDImage("dragonair_sattack",
		L"img/pokemon/14. dragonair/sattack.png", 192, 946, 2, 11);
	_stateImage[POKEMON_STATE_HURT] = IMAGEMANAGER->addFrameDImage("dragonair_hurt",
		L"img/pokemon/14. dragonair/hurt.png", 60, 704, 1, 11);
	_stateImage[POKEMON_STATE_SLEEP] = IMAGEMANAGER->addFrameDImage("dragonair_sleep",
		L"img/pokemon/14. dragonair/sleep.png", 88, 64, 2, 1);
	_stateImage[POKEMON_STATE_DEFAULT] = IMAGEMANAGER->addFrameDImage("dragonair_default",
		L"img/pokemon/14. dragonair/default.png", 86, 836, 1, 11);

	//�ʻ�ȭ
	_portrait = IMAGEMANAGER->addDImage("dragonair_portrait",
		L"img/pokemon/14. dragonair/portrait.png", 40, 40);

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

void Dragonair::release()
{
}
