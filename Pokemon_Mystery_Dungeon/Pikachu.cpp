#include "stdafx.h"
#include "Pikachu.h"

Pikachu::Pikachu()
{
	//�̸�
	_name = L"��ī��";
	_num = 5;


	//����(��ü��)
	_pokemonValue.hp = 35;
	_pokemonValue.attack = 55;
	_pokemonValue.defense = 30;
	_pokemonValue.sattack = 50;
	_pokemonValue.sdefense = 40;
	_pokemonValue.speed = 90;


	//Ÿ�� & Ư��
	_type[0] = POKEMON_TYPE_ELECTRIC;
	_type[1] = END_POKEMON_TYPE;

	_jump = true;
}

Pikachu::~Pikachu()
{
}

HRESULT Pikachu::init()
{
	Pokemon::init();

	//�̹���
	_stateImage[POKEMON_STATE_IDLE] = IMAGEMANAGER->addFrameDImage("pikachu_idle",
		L"img/pokemon/5. pikachu/idle.png", 60, 594, 1, 11);
	_stateImage[POKEMON_STATE_MOVE] = IMAGEMANAGER->addFrameDImage("pikachu_move",
		L"img/pokemon/5. pikachu/move.png", 208, 594, 4, 11);
	_stateImage[POKEMON_STATE_ATTACK] = IMAGEMANAGER->addFrameDImage("pikachu_attack",
		L"img/pokemon/5. pikachu/attack.png", 120, 594, 2, 11);
	_stateImage[POKEMON_STATE_SATTACK] = IMAGEMANAGER->addFrameDImage("pikachu_sattack",
		L"img/pokemon/5. pikachu/sattack.png", 112, 594, 2, 11);
	_stateImage[POKEMON_STATE_HURT] = IMAGEMANAGER->addFrameDImage("pikachu_hurt",
		L"img/pokemon/5. pikachu/hurt.png", 48, 594, 1, 11);
	_stateImage[POKEMON_STATE_SLEEP] = IMAGEMANAGER->addFrameDImage("pikachu_sleep",
		L"img/pokemon/5. pikachu/sleep.png", 96, 48, 2, 1);
	_stateImage[POKEMON_STATE_DEFAULT] = IMAGEMANAGER->addFrameDImage("pikachu_default",
		L"img/pokemon/5. pikachu/default.png", 60, 594, 1, 11);

	//�ʻ�ȭ
	_portrait = IMAGEMANAGER->addDImage("pikachu_portrait",
		L"img/pokemon/5. pikachu/portrait.png", 40, 40);

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
	_skill.push_back(3);
	_skill.push_back(5);
	_skill.push_back(10);
	_skill.push_back(17);
	_skill.push_back(18);
	_skill.push_back(21);

	return S_OK;
}