#include "stdafx.h"
#include "Pichu.h"

Pichu::Pichu()
{
	//이름
	_name = L"피츄";
	_num = 4;

	//타입 & 특성
	_type[0] = POKEMON_TYPE_ELECTRIC;
	_type[1] = END_POKEMON_TYPE;
	//특성 _passive;

	//스탯


	_jump = true;
}

Pichu::~Pichu()
{
}

HRESULT Pichu::init()
{
	//이미지
	_stateImage[POKEMON_STATE_IDLE] = IMAGEMANAGER->addFrameDImage("pichu_idle",
		L"img/pokemon/4. pichu/idle.png", 42, 572, 1, 11);
	_stateImage[POKEMON_STATE_MOVE] = IMAGEMANAGER->addFrameDImage("pichu_move",
		L"img/pokemon/4. pichu/move.png", 84, 594, 2, 11);
	_stateImage[POKEMON_STATE_ATTACK] = IMAGEMANAGER->addFrameDImage("pichu_attack_sattack",
		L"img/pokemon/4. pichu/attack_sattack.png", 92, 572, 2, 11);
	_stateImage[POKEMON_STATE_SATTACK] = _stateImage[POKEMON_STATE_ATTACK];

	_stateImage[POKEMON_STATE_HURT] = IMAGEMANAGER->addFrameDImage("pichu_hurt",
		L"img/pokemon/4. pichu/hurt.png", 54, 440, 1, 11);
	_stateImage[POKEMON_STATE_SLEEP] = IMAGEMANAGER->addFrameDImage("pichu_sleep",
		L"img/pokemon/4. pichu/sleep.png", 72, 46, 2, 1);
	_stateImage[POKEMON_STATE_DEFAULT] = IMAGEMANAGER->addFrameDImage("pichu_default",
		L"img/pokemon/4. pichu/default.png", 42, 572, 1, 11);

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

void Pichu::release()
{
}