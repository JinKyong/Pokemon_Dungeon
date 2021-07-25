#include "stdafx.h"
#include "Vaporeon.h"

Vaporeon::Vaporeon()
{
	//�̸�
	_name = L"���̵�";
	_num = 21;


	//����(��ü��)
	_pokemonValue.hp = 130;
	_pokemonValue.attack = 65;
	_pokemonValue.defense = 60;
	_pokemonValue.sattack = 110;
	_pokemonValue.sdefense = 95;
	_pokemonValue.speed = 65;


	//Ÿ�� & Ư��
	_type[0] = POKEMON_TYPE_WATER;
	_type[1] = END_POKEMON_TYPE;

	_jump = false;
}

Vaporeon::~Vaporeon()
{
}

HRESULT Vaporeon::init()
{
	Pokemon::init();

	//�̹���
	_stateImage[POKEMON_STATE_IDLE] = IMAGEMANAGER->addFrameDImage("vaporeon_idle",
		L"img/pokemon/21. vaporeon/idle.png", 140, 880, 2, 11);
	_stateImage[POKEMON_STATE_MOVE] = IMAGEMANAGER->addFrameDImage("vaporeon_move",
		L"img/pokemon/21. vaporeon/move.png", 280, 704, 4, 11);
	_stateImage[POKEMON_STATE_ATTACK] = IMAGEMANAGER->addFrameDImage("vaporeon_attack",
		L"img/pokemon/21. vaporeon/attack.png", 344, 946, 4, 11);
	_stateImage[POKEMON_STATE_SATTACK] = IMAGEMANAGER->addFrameDImage("vaporeon_sattack",
		L"img/pokemon/21. vaporeon/sattack.png", 172, 946, 2, 11);
	_stateImage[POKEMON_STATE_HURT] = IMAGEMANAGER->addFrameDImage("vaporeon_hurt",
		L"img/pokemon/21. vaporeon/hurt.png", 62, 704, 1, 11);
	_stateImage[POKEMON_STATE_SLEEP] = IMAGEMANAGER->addFrameDImage("vaporeon_sleep",
		L"img/pokemon/21. vaporeon/sleep.png", 120, 46, 2, 1);
	_stateImage[POKEMON_STATE_DEFAULT] = IMAGEMANAGER->addFrameDImage("vaporeon_default",
		L"img/pokemon/21. vaporeon/default.png", 70, 704, 1, 11);

	//�ʻ�ȭ
	_portrait = IMAGEMANAGER->addDImage("vaporeon_portrait",
		L"img/pokemon/21. vaporeon/portrait.png", 40, 40);

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
	_count[POKEMON_STATE_DEFAULT] = 0.8;

	//���º� �̼�����
	_tuningX = 0;
	_tuningY = 0;

	//attack 2�� �Լ�
	_interceptX = _count[POKEMON_STATE_ATTACK] * (_stateImage[POKEMON_STATE_ATTACK]->getMaxFrameX() + 1);
	_interceptY = 3 * TILEWIDTH / 4;
	_gradient = -_interceptY / (_interceptX * _interceptX);


	return S_OK;
}
