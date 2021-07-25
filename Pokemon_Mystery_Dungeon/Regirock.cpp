#include "stdafx.h"
#include "Regirock.h"

Regirock::Regirock()
{
	//�̸�
	_name = L"������";
	_num = 32;


	//����(��ü��)
	_pokemonValue.hp = 80;
	_pokemonValue.attack = 100;
	_pokemonValue.defense = 200;
	_pokemonValue.sattack = 50;
	_pokemonValue.sdefense = 100;
	_pokemonValue.speed = 50;


	//Ÿ�� & Ư��
	_type[0] = POKEMON_TYPE_ROCK;
	_type[1] = END_POKEMON_TYPE;

	_jump = false;
}

Regirock::~Regirock()
{
}

HRESULT Regirock::init()
{
	Pokemon::init();

	//�̹���
	_stateImage[POKEMON_STATE_IDLE] = IMAGEMANAGER->addFrameDImage("regirock_idle",
		L"img/pokemon/32. regirock/idle.png", 68, 748, 1, 11);
	_stateImage[POKEMON_STATE_MOVE] = IMAGEMANAGER->addFrameDImage("regirock_move",
		L"img/pokemon/32. regirock/move.png", 272, 748, 4, 11);
	_stateImage[POKEMON_STATE_ATTACK] = IMAGEMANAGER->addFrameDImage("regirock_attack",
		L"img/pokemon/32. regirock/attack.png", 408, 748, 6, 11);
	_stateImage[POKEMON_STATE_SATTACK] = IMAGEMANAGER->addFrameDImage("regirock_sattack",
		L"img/pokemon/32. regirock/sattack.png", 74, 814, 1, 11);
	_stateImage[POKEMON_STATE_HURT] = IMAGEMANAGER->addFrameDImage("regirock_hurt",
		L"img/pokemon/32. regirock/hurt.png", 66, 682, 1, 11);
	_stateImage[POKEMON_STATE_SLEEP] = IMAGEMANAGER->addFrameDImage("regirock_sleep",
		L"img/pokemon/32. regirock/sleep.png", 112, 54, 2, 1);
	_stateImage[POKEMON_STATE_DEFAULT] = _stateImage[POKEMON_STATE_IDLE];


	//�ʻ�ȭ
	_portrait = IMAGEMANAGER->addDImage("regirock_portrait",
		L"img/pokemon/32. regirock/portrait.png", 40, 40);

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
