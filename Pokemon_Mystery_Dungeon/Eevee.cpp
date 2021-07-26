#include "stdafx.h"
#include "Eevee.h"

Eevee::Eevee()
{
	//�̸�
	_name = L"�̺���";
	_num = 20;


	//����(��ü��)
	_pokemonValue.hp = 55;
	_pokemonValue.attack = 55;
	_pokemonValue.defense = 50;
	_pokemonValue.sattack = 45;
	_pokemonValue.sdefense = 65;
	_pokemonValue.speed = 55;


	//Ÿ�� & Ư��
	_type[0] = POKEMON_TYPE_NORMAL;
	_type[1] = END_POKEMON_TYPE;

	_jump = false;
}

Eevee::~Eevee()
{
}

HRESULT Eevee::init()
{
	Pokemon::init();

	//�̹���
	_stateImage[POKEMON_STATE_IDLE] = IMAGEMANAGER->addFrameDImage("eevee_idle",
		L"img/pokemon/20. eevee/idle.png", 54, 528, 1, 11);
	_stateImage[POKEMON_STATE_MOVE] = IMAGEMANAGER->addFrameDImage("eevee_move_attack",
		L"img/pokemon/20. eevee/move_attack.png", 216, 528, 4, 11);
	_stateImage[POKEMON_STATE_ATTACK] = _stateImage[POKEMON_STATE_MOVE];

	_stateImage[POKEMON_STATE_SATTACK] = IMAGEMANAGER->addFrameDImage("eevee_sattack",
		L"img/pokemon/20. eevee/sattack.png", 108, 572, 2, 11);
	_stateImage[POKEMON_STATE_HURT] = IMAGEMANAGER->addFrameDImage("eevee_hurt",
		L"img/pokemon/20. eevee/hurt.png", 58, 638, 1, 11);
	_stateImage[POKEMON_STATE_SLEEP] = IMAGEMANAGER->addFrameDImage("eevee_sleep",
		L"img/pokemon/20. eevee/sleep.png", 100, 38, 2, 1);
	_stateImage[POKEMON_STATE_DEFAULT] = IMAGEMANAGER->addFrameDImage("eevee_default",
		L"img/pokemon/20. eevee/default.png", 54, 528, 1, 11);

	//�ʻ�ȭ
	_portrait = IMAGEMANAGER->addDImage("eevee_portrait",
		L"img/pokemon/20. eevee/portrait.png", 40, 40);

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

	//��ų ���
	_skill.push_back(10);
	_skill.push_back(17);
	_skill.push_back(18);

	return S_OK;
}
