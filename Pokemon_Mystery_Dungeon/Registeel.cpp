#include "stdafx.h"
#include "Registeel.h"

Registeel::Registeel()
{
	//�̸�
	_name = L"������ƿ";
	_num = 34;


	//����(��ü��)
	_pokemonValue.hp = 80;
	_pokemonValue.attack = 75;
	_pokemonValue.defense = 150;
	_pokemonValue.sattack = 75;
	_pokemonValue.sdefense = 150;
	_pokemonValue.speed = 50;


	//Ÿ�� & Ư��
	_type[0] = POKEMON_TYPE_STEEL;
	_type[1] = END_POKEMON_TYPE;

	_jump = false;
}

Registeel::~Registeel()
{
}

HRESULT Registeel::init()
{
	Pokemon::init();

	//�̹���
	_stateImage[POKEMON_STATE_IDLE] = IMAGEMANAGER->addFrameDImage("registeel_idle",
		L"img/pokemon/34. registeel/idle.png", 70, 770, 1, 11);
	_stateImage[POKEMON_STATE_MOVE] = IMAGEMANAGER->addFrameDImage("registeel_move",
		L"img/pokemon/34. registeel/move.png", 280, 770, 4, 11);
	_stateImage[POKEMON_STATE_ATTACK] = IMAGEMANAGER->addFrameDImage("registeel_attack",
		L"img/pokemon/34. registeel/attack.png", 140, 770, 2, 11);
	_stateImage[POKEMON_STATE_SATTACK] = IMAGEMANAGER->addFrameDImage("registeel_sattack",
		L"img/pokemon/34. registeel/sattack.png", 70, 858, 1, 11);
	_stateImage[POKEMON_STATE_HURT] = IMAGEMANAGER->addFrameDImage("registeel_hurt",
		L"img/pokemon/34. registeel/hurt.png", 70, 858, 1, 11);
	_stateImage[POKEMON_STATE_SLEEP] = IMAGEMANAGER->addFrameDImage("registeel_sleep",
		L"img/pokemon/34. registeel/sleep.png", 108, 52, 2, 1);
	_stateImage[POKEMON_STATE_DEFAULT] = IMAGEMANAGER->addFrameDImage("registeel_default",
		L"img/pokemon/34. registeel/default.png", 70, 770, 1, 11);

	//�ʻ�ȭ
	_portrait = IMAGEMANAGER->addDImage("registeel_portrait",
		L"img/pokemon/34. registeel/portrait.png", 40, 40);

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

	//��ų ���
	_skill.push_back(4);
	_skill.push_back(14);
	_skill.push_back(18);
	_skill.push_back(19);

	return S_OK;
}
