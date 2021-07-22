#include "stdafx.h"
#include "Blastoise.h"

Blastoise::Blastoise()
{
	//�̸�
	_name = L"�źϿ�";
	_num = 12;


	//����(��ü��)
	_pokemonValue.hp = 79;
	_pokemonValue.attack = 83;
	_pokemonValue.defense = 100;
	_pokemonValue.sattack = 85;
	_pokemonValue.sdefense = 105;
	_pokemonValue.speed = 78;


	//Ÿ�� & Ư��
	_type[0] = POKEMON_TYPE_WATER;
	_type[1] = END_POKEMON_TYPE;

	_jump = false;
}

Blastoise::~Blastoise()
{
}

HRESULT Blastoise::init()
{
	//�̹���
	_stateImage[POKEMON_STATE_IDLE] = IMAGEMANAGER->addFrameDImage("blastoise_idle",
		L"img/pokemon/12. blastoise/idle.png", 60, 638, 1, 11);
	_stateImage[POKEMON_STATE_MOVE] = IMAGEMANAGER->addFrameDImage("blastoise_move",
		L"img/pokemon/12. blastoise/move.png", 224, 638, 4, 11);
	_stateImage[POKEMON_STATE_ATTACK] = IMAGEMANAGER->addFrameDImage("blastoise_attack",
		L"img/pokemon/12. blastoise/attack.png", 112, 638, 2, 11);
	_stateImage[POKEMON_STATE_SATTACK] = IMAGEMANAGER->addFrameDImage("blastoise_sattack",
		L"img/pokemon/12. blastoise/sattack.png", 60, 616, 1, 11);
	_stateImage[POKEMON_STATE_HURT] = IMAGEMANAGER->addFrameDImage("blastoise_hurt",
		L"img/pokemon/12. blastoise/hurt.png", 52, 440, 1, 11);
	_stateImage[POKEMON_STATE_SLEEP] = IMAGEMANAGER->addFrameDImage("blastoise_sleep",
		L"img/pokemon/12. blastoise/sleep.png", 112, 54, 2, 1);
	_stateImage[POKEMON_STATE_DEFAULT] = IMAGEMANAGER->addFrameDImage("blastoise_default",
		L"img/pokemon/12. blastoise/default.png", 60, 638, 1, 11);

	//�ʻ�ȭ
	_portrait = IMAGEMANAGER->addDImage("blastoise_portrait",
		L"img/pokemon/12. blastoise/portrait.png", 40, 40);

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

void Blastoise::release()
{
}
