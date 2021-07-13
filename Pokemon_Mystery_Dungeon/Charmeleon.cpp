#include "stdafx.h"
#include "Charmeleon.h"

HRESULT Charmeleon::init()
{
	//이미지
	_stateImage[P_IDLE] = IMAGEMANAGER->addFrameDImage("charmeleon_idle",
		L"img/pokemon/2. charmeleon/idle.png", 108, 594, 2, 11);
	_stateImage[P_MOVE] = IMAGEMANAGER->addFrameDImage("charmeleon_move",
		L"img/pokemon/2. charmeleon/move.png", 192, 528, 4, 11);
	_stateImage[P_ATTACK] = IMAGEMANAGER->addFrameDImage("charmeleon_attack",
		L"img/pokemon/2. charmeleon/attack.png", 192, 704, 3, 11);
	_stateImage[P_SATTACK] = IMAGEMANAGER->addFrameDImage("charmeleon_sattack",
		L"img/pokemon/2. charmeleon/sattack.png", 128, 594, 2, 11);
	_stateImage[P_HURT] = IMAGEMANAGER->addFrameDImage("charmeleon_hurt",
		L"img/pokemon/2. charmeleon/hurt.png", 52, 638, 1, 11);
	_stateImage[P_SLEEP] = IMAGEMANAGER->addFrameDImage("charmeleon_sleep",
		L"img/pokemon/2. charmeleon/sleep.png", 96, 48, 2, 1);

	//방향
	_currentImage = _stateImage[P_IDLE];
	_frameX = 0;


	//이름
	_name = L"리자드";

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

void Charmeleon::release()
{
}

void Charmeleon::update()
{
}

void Charmeleon::render(float x, float y)
{
}