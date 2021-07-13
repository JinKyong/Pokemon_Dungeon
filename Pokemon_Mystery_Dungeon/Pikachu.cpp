#include "stdafx.h"
#include "Pikachu.h"

HRESULT Pikachu::init()
{
	//이미지
	_stateImage[P_IDLE] = IMAGEMANAGER->addFrameDImage("pikachu_idle_attack",
		L"img/pokemon/5. pikachu/idle_attack.png", 120, 594, 2, 11);
	_stateImage[P_MOVE] = IMAGEMANAGER->addFrameDImage("pikachu_move",
		L"img/pokemon/5. pikachu/move.png", 208, 594, 4, 11);
	_stateImage[P_ATTACK] = _stateImage[P_IDLE];

	_stateImage[P_SATTACK] = IMAGEMANAGER->addFrameDImage("pikachu_sattack",
		L"img/pokemon/5. pikachu/sattack.png", 112, 594, 2, 11);
	_stateImage[P_HURT] = IMAGEMANAGER->addFrameDImage("pikachu_hurt",
		L"img/pokemon/5. pikachu/hurt.png", 48, 594, 1, 11);
	_stateImage[P_SLEEP] = IMAGEMANAGER->addFrameDImage("pikachu_sleep",
		L"img/pokemon/5. pikachu/sleep.png", 96, 48, 2, 1);

	//방향
	_currentImage = _stateImage[P_IDLE];
	_frameX = 0;


	//이름
	_name = L"피카츄";

	//타입 & 특성
	_type = TYPE_FIRE;
	//특성 _passive;



	//스탯
	//_hp = 15;
	//_attack = 5;
	//_defense = 5;
	//_sattack = 5;
	//_sdefense = 5;
	//_speed = 5;

	return S_OK;
}

void Pikachu::release()
{
}

void Pikachu::update()
{
}

void Pikachu::render(float x, float y)
{
}