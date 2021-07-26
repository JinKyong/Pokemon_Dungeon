#include "stdafx.h"
#include "Bulbasaur.h"

Bulbasaur::Bulbasaur()
{
	//�̸�
	_name = L"�̻��ؾ�";
	_num = 7;


	//����(��ü��)
	_pokemonValue.hp = 45;
	_pokemonValue.attack = 49;
	_pokemonValue.defense = 49;
	_pokemonValue.sattack = 65;
	_pokemonValue.sdefense = 65;
	_pokemonValue.speed = 45;


	//Ÿ�� & Ư��
	_type[0] = POKEMON_TYPE_GRASS;
	_type[1] = POKEMON_TYPE_POISON;



	_jump = true;
}

Bulbasaur::~Bulbasaur()
{
}

HRESULT Bulbasaur::init()
{
	Pokemon::init();

	//�̹���
	_stateImage[POKEMON_STATE_IDLE] = IMAGEMANAGER->addFrameDImage("bulbasaur_idle_attack",
		L"img/pokemon/7. bulbasaur/idle_attack.png", 96, 484, 2, 11);
	_stateImage[POKEMON_STATE_MOVE] = IMAGEMANAGER->addFrameDImage("bulbasaur_move",
		L"img/pokemon/7. bulbasaur/move.png", 144, 484, 3, 11);
	_stateImage[POKEMON_STATE_ATTACK] = _stateImage[POKEMON_STATE_IDLE];

	_stateImage[POKEMON_STATE_SATTACK] = IMAGEMANAGER->addFrameDImage("bulbasaur_sattack",
		L"img/pokemon/7. bulbasaur/sattack.png", 76, 462, 2, 11);
	_stateImage[POKEMON_STATE_HURT] = IMAGEMANAGER->addFrameDImage("bulbasaur_hurt",
		L"img/pokemon/7. bulbasaur/hurt.png", 50, 506, 1, 11);
	_stateImage[POKEMON_STATE_SLEEP] = IMAGEMANAGER->addFrameDImage("bulbasaur_sleep",
		L"img/pokemon/7. bulbasaur/sleep.png", 80, 40, 2, 1);
	_stateImage[POKEMON_STATE_DEFAULT] = IMAGEMANAGER->addFrameDImage("bulbasaur_default",
		L"img/pokemon/7. bulbasaur/default.png", 48, 484, 1, 11);

	//�ʻ�ȭ
	_portrait = IMAGEMANAGER->addDImage("bulbasaur_portrait",
		L"img/pokemon/7. bulbasaur/portrait.png", 40, 40);

	//frame
	changeDirect(DOWN);
	changeState(POKEMON_STATE_DEFAULT);

	//frameCount(���ϸ󸶴� �����������)
	_count[POKEMON_STATE_IDLE] = 0.6 / (_stateImage[POKEMON_STATE_IDLE]->getMaxFrameX() + 1);
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
	_skill.push_back(6);
	_skill.push_back(11);
	_skill.push_back(12);
	_skill.push_back(13);
	_skill.push_back(15);
	_skill.push_back(23);

	return S_OK;
}
