#include "stdafx.h"
#include "Bulbasaur.h"

Bulbasaur::Bulbasaur()
{
	//이름
	_name = L"이상해씨";
	_num = 7;

	//타입 & 특성
	_type[0] = POKEMON_TYPE_GRASS;
	_type[1] = POKEMON_TYPE_POISON;
	//특성 _passive;

	//스탯(개체값)


	_jump = true;
}

Bulbasaur::~Bulbasaur()
{
}

HRESULT Bulbasaur::init()
{
	//이미지
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

	//frame
	changeDirect(DOWN);
	changeState(POKEMON_STATE_DEFAULT);

	//frameCount(포켓몬마다 조정해줘야함)
	_count[POKEMON_STATE_IDLE] = 0.6 / (_stateImage[POKEMON_STATE_IDLE]->getMaxFrameX() + 1);
	_count[POKEMON_STATE_MOVE] = 0.8 / (_stateImage[POKEMON_STATE_MOVE]->getMaxFrameX() + 1);
	_count[POKEMON_STATE_ATTACK] = 0.8 / (_stateImage[POKEMON_STATE_ATTACK]->getMaxFrameX() + 1);
	_count[POKEMON_STATE_SATTACK] = 0.8 / (_stateImage[POKEMON_STATE_SATTACK]->getMaxFrameX() + 1);
	_count[POKEMON_STATE_HURT] = 0.5;
	_count[POKEMON_STATE_SLEEP] = 0.5;
	_count[POKEMON_STATE_DEFAULT] = 0.5;

	//상태별 미세조정
	_tuningX = 0;
	_tuningY = 0;

	//attack 2차 함수
	_interceptX = _count[POKEMON_STATE_ATTACK] * (_stateImage[POKEMON_STATE_ATTACK]->getMaxFrameX() + 1);
	_interceptY = 3 * TILEWIDTH / 4;
	_gradient = -_interceptY / (_interceptX * _interceptX);


	return S_OK;
}

void Bulbasaur::release()
{
}
