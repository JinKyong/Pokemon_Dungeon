#include "stdafx.h"
#include "Pichu.h"

HRESULT Pichu::init()
{
	//이미지
	_stateImage[P_IDLE] = IMAGEMANAGER->addFrameDImage("pichu_idle",
		L"img/pokemon/4. pichu/idle.png", 84, 572, 2, 11);
	_stateImage[P_MOVE] = IMAGEMANAGER->addFrameDImage("pichu_move",
		L"img/pokemon/4. pichu/move.png", 84, 594, 2, 11);
	_stateImage[P_ATTACK] = IMAGEMANAGER->addFrameDImage("pichu_attack_sattack",
		L"img/pokemon/4. pichu/attack_sattack.png", 46, 528, 1, 11);
	_stateImage[P_SATTACK] = _stateImage[P_ATTACK];

	_stateImage[P_HURT] = IMAGEMANAGER->addFrameDImage("pichu_hurt",
		L"img/pokemon/4. pichu/hurt.png", 54, 440, 1, 11);
	_stateImage[P_SLEEP] = IMAGEMANAGER->addFrameDImage("pichu_sleep",
		L"img/pokemon/4. pichu/sleep.png", 72, 46, 2, 1);

	//방향
	_currentImage = _stateImage[P_IDLE];
	_frameX = 0;


	//이름
	_name = L"피츄";

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

void Pichu::release()
{
}

void Pichu::update()
{
}

void Pichu::render(float x, float y)
{
}