#include "stdafx.h"
#include "Raichu.h"

Raichu::Raichu()
{
	//이름
	_name = L"라이츄";
	_num = 6;

	//타입 & 특성
	_type = POKEMON_TYPE_ELECTRIC;
	//특성 _passive;

	//스탯
}

Raichu::~Raichu()
{
}

HRESULT Raichu::init()
{
	//이미지
	_stateImage[POKEMON_STATE_IDLE] = IMAGEMANAGER->addFrameDImage("raichu_idle_move",
		L"img/pokemon/6. raichu/idle_move.png", 180, 660, 3, 11);
	_stateImage[POKEMON_STATE_MOVE] = _stateImage[POKEMON_STATE_IDLE];

	_stateImage[POKEMON_STATE_ATTACK] = IMAGEMANAGER->addFrameDImage("raichu_attack",
		L"img/pokemon/6. raichu/attack.png", 60, 638, 1, 11);
	_stateImage[POKEMON_STATE_SATTACK] = IMAGEMANAGER->addFrameDImage("raichu_sattack",
		L"img/pokemon/6. raichu/sattack.png", 116, 660, 2, 11);
	_stateImage[POKEMON_STATE_HURT] = IMAGEMANAGER->addFrameDImage("raichu_hurt",
		L"img/pokemon/6. raichu/hurt.png", 64, 682, 1, 11);
	_stateImage[POKEMON_STATE_SLEEP] = IMAGEMANAGER->addFrameDImage("raichu_sleep",
		L"img/pokemon/6. raichu/sleep.png", 104, 56, 2, 1);
	_stateImage[POKEMON_STATE_DEFAULT] = IMAGEMANAGER->addFrameDImage("raichu_default",
		L"img/pokemon/6. raichu/default.png", 60, 660, 1, 11);

	//frame
	changeDirect(DOWN);
	changeState(POKEMON_STATE_DEFAULT);

	//frameCount(포켓몬마다 조정해줘야함)
	_count[POKEMON_STATE_IDLE] = 0.8 / (_stateImage[POKEMON_STATE_IDLE]->getMaxFrameX() + 1);
	_count[POKEMON_STATE_MOVE] = 0.8 / (_stateImage[POKEMON_STATE_MOVE]->getMaxFrameX() + 1);
	_count[POKEMON_STATE_ATTACK] = 0.8 / (_stateImage[POKEMON_STATE_ATTACK]->getMaxFrameX() + 1);
	_count[POKEMON_STATE_SATTACK] = 0.8 / (_stateImage[POKEMON_STATE_SATTACK]->getMaxFrameX() + 1);
	_count[POKEMON_STATE_HURT] = 0.5;
	_count[POKEMON_STATE_SLEEP] = 0.5;
	_count[POKEMON_STATE_DEFAULT] = 0.2;

	//상태별 미세조정
	_tuningX = 0;
	_tuningY = 0;

	//attack 2차 함수
	_interceptX = _count[POKEMON_STATE_ATTACK] * (_stateImage[POKEMON_STATE_ATTACK]->getMaxFrameX() + 1);
	_interceptY = 3 * TILEWIDTH / 4;
	_gradient = -_interceptY / (_interceptX * _interceptX);


	return S_OK;
}

void Raichu::release()
{
}