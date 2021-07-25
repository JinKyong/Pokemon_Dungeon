#include "stdafx.h"
#include "Mawile.h"

Mawile::Mawile()
{
	//�̸�
	_name = L"��ġƮ";
	_num = 29;


	//����(��ü��)
	_pokemonValue.hp = 50;
	_pokemonValue.attack = 85;
	_pokemonValue.defense = 85;
	_pokemonValue.sattack = 55;
	_pokemonValue.sdefense = 55;
	_pokemonValue.speed = 50;


	//Ÿ�� & Ư��
	_type[0] = POKEMON_TYPE_STEEL;
	_type[1] = END_POKEMON_TYPE;

	_jump = false;
}

Mawile::~Mawile()
{
}

HRESULT Mawile::init()
{
	Pokemon::init();

	//�̹���
	_stateImage[POKEMON_STATE_IDLE] = IMAGEMANAGER->addFrameDImage("mawile_idle",
		L"img/pokemon/29. mawile/idle.png", 148, 682, 2, 11);
	_stateImage[POKEMON_STATE_MOVE] = IMAGEMANAGER->addFrameDImage("mawile_move",
		L"img/pokemon/29. mawile/move.png", 296, 682, 4, 11);
	_stateImage[POKEMON_STATE_ATTACK] = IMAGEMANAGER->addFrameDImage("mawile_attack",
		L"img/pokemon/29. mawile/attack.png", 148, 682, 2, 11);
	_stateImage[POKEMON_STATE_SATTACK] = IMAGEMANAGER->addFrameDImage("mawile_sattack",
		L"img/pokemon/29. mawile/sattack.png", 196, 1078, 2, 11);
	_stateImage[POKEMON_STATE_HURT] = IMAGEMANAGER->addFrameDImage("mawile_hurt",
		L"img/pokemon/29. mawile/hurt.png", 78, 858, 1, 11);
	_stateImage[POKEMON_STATE_SLEEP] = IMAGEMANAGER->addFrameDImage("mawile_sleep",
		L"img/pokemon/29. mawile/sleep.png", 108, 44, 2, 1);
	_stateImage[POKEMON_STATE_DEFAULT] = IMAGEMANAGER->addFrameDImage("mawile_default",
		L"img/pokemon/29. mawile/default.png", 74, 682, 1, 11);

	//�ʻ�ȭ
	_portrait = IMAGEMANAGER->addDImage("mawile_portrait",
		L"img/pokemon/29. mawile/portrait.png", 40, 40);

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
