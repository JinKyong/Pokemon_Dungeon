#include "stdafx.h"
#include "Solrock.h"

Solrock::Solrock()
{
	//�̸�
	_name = L"�ַ�";
	_num = 31;


	//����(��ü��)
	_pokemonValue.hp = 70;
	_pokemonValue.attack = 95;
	_pokemonValue.defense = 85;
	_pokemonValue.sattack = 55;
	_pokemonValue.sdefense = 65;
	_pokemonValue.speed = 70;


	//Ÿ�� & Ư��
	_type[0] = POKEMON_TYPE_ROCK;
	_type[1] = POKEMON_TYPE_PSYCHIC;

	_jump = false;
}

Solrock::~Solrock()
{
}

HRESULT Solrock::init()
{
	Pokemon::init();

	//�̹���
	_stateImage[POKEMON_STATE_IDLE] = IMAGEMANAGER->addFrameDImage("solrock_idle_move",
		L"img/pokemon/31. solrock/idle_move.png", 174, 682, 3, 11);
	_stateImage[POKEMON_STATE_MOVE] = _stateImage[POKEMON_STATE_IDLE];

	_stateImage[POKEMON_STATE_ATTACK] = IMAGEMANAGER->addFrameDImage("solrock_attack",
		L"img/pokemon/31. solrock/attack.png", 116, 682, 2, 11);
	_stateImage[POKEMON_STATE_SATTACK] = IMAGEMANAGER->addFrameDImage("solrock_sattack",
		L"img/pokemon/31. solrock/sattack.png", 58, 682, 1, 11);
	_stateImage[POKEMON_STATE_HURT] = IMAGEMANAGER->addFrameDImage("solrock_hurt",
		L"img/pokemon/31. solrock/hurt.png", 58, 682, 1, 11);
	_stateImage[POKEMON_STATE_SLEEP] = IMAGEMANAGER->addFrameDImage("solrock_sleep",
		L"img/pokemon/31. solrock/sleep.png", 76, 44, 2, 1);
	_stateImage[POKEMON_STATE_DEFAULT] = IMAGEMANAGER->addFrameDImage("solrock_default",
		L"img/pokemon/31. solrock/default.png", 58, 682, 1, 11);

	//�ʻ�ȭ
	_portrait = IMAGEMANAGER->addDImage("solrock_portrait",
		L"img/pokemon/31. solrock/portrait.png", 40, 40);

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
