#include "stdafx.h"
#include "Lunatone.h"

Lunatone::Lunatone()
{
	//�̸�
	_name = L"�糪��";
	_num = 30;


	//����(��ü��)
	_pokemonValue.hp = 70;
	_pokemonValue.attack = 55;
	_pokemonValue.defense = 65;
	_pokemonValue.sattack = 95;
	_pokemonValue.sdefense = 85;
	_pokemonValue.speed = 70;


	//Ÿ�� & Ư��
	_type[0] = POKEMON_TYPE_ROCK;
	_type[1] = POKEMON_TYPE_PSYCHIC;

	_jump = false;
}

Lunatone::~Lunatone()
{
}

HRESULT Lunatone::init()
{
	Pokemon::init();

	//�̹���
	_stateImage[POKEMON_STATE_IDLE] = IMAGEMANAGER->addFrameDImage("lunatone_idle_move",
		L"img/pokemon/30. lunatone/idle_move.png", 138, 638, 3, 11);
	_stateImage[POKEMON_STATE_MOVE] = _stateImage[POKEMON_STATE_IDLE];

	_stateImage[POKEMON_STATE_ATTACK] = IMAGEMANAGER->addFrameDImage("lunatone_attack",
		L"img/pokemon/30. lunatone/attack.png", 92, 638, 2, 11);
	_stateImage[POKEMON_STATE_SATTACK] = IMAGEMANAGER->addFrameDImage("lunatone_sattack",
		L"img/pokemon/30. lunatone/sattack.png", 46, 638, 1, 11);
	_stateImage[POKEMON_STATE_HURT] = IMAGEMANAGER->addFrameDImage("lunatone_hurt",
		L"img/pokemon/30. lunatone/hurt.png", 46, 638, 1, 11);
	_stateImage[POKEMON_STATE_SLEEP] = IMAGEMANAGER->addFrameDImage("lunatone_sleep",
		L"img/pokemon/30. lunatone/sleep.png", 76, 42, 2, 1);
	_stateImage[POKEMON_STATE_DEFAULT] = IMAGEMANAGER->addFrameDImage("lunatone_default",
		L"img/pokemon/30. lunatone/default.png", 46, 638, 1, 11);

	//�ʻ�ȭ
	_portrait = IMAGEMANAGER->addDImage("lunatone_portrait",
		L"img/pokemon/30. lunatone/portrait.png", 40, 40);

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
	_skill.push_back(4);
	_skill.push_back(17);
	_skill.push_back(18);
	_skill.push_back(20);

	return S_OK;
}
