#include "stdafx.h"
#include "Raichu.h"

HRESULT Raichu::init()
{
	//이미지
	_stateImage[P_IDLE] = IMAGEMANAGER->addFrameDImage("raichu_idle_move",
		L"img/pokemon/6. raichu/idle_move.png", 240, 660, 4, 11);
	_stateImage[P_MOVE] = _stateImage[P_IDLE];

	_stateImage[P_ATTACK] = IMAGEMANAGER->addFrameDImage("raichu_attack",
		L"img/pokemon/6. raichu/attack.png", 60, 638, 1, 11);
	_stateImage[P_SATTACK] = IMAGEMANAGER->addFrameDImage("raichu_sattack",
		L"img/pokemon/6. raichu/sattack.png", 116, 660, 2, 11);
	_stateImage[P_HURT] = IMAGEMANAGER->addFrameDImage("raichu_hurt",
		L"img/pokemon/6. raichu/hurt.png", 64, 682, 1, 11);
	_stateImage[P_SLEEP] = IMAGEMANAGER->addFrameDImage("raichu_sleep",
		L"img/pokemon/6. raichu/sleep.png", 104, 56, 2, 1);

	//방향
	_currentImage = _stateImage[P_IDLE];
	_frameX = 0;


	//이름
	_name = L"라이츄";
	
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

void Raichu::release()
{
}

void Raichu::update()
{
}

void Raichu::render(float x, float y)
{
}