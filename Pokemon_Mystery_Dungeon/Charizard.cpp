#include "stdafx.h"
#include "Charizard.h"

Charizard::Charizard()
{
	//�̸�
	_name = L"���ڸ�";
	_num = 1;

	//Ÿ�� & Ư��
	_type = TYPE_FIRE;
	//Ư�� _passive;

	//����(��ü��)
	//_hp;
	//_attack;
	//_defense;
	//_sattack;
	//_sdefense;
	//_speed;
}

Charizard::~Charizard()
{
}

HRESULT Charizard::init()
{
	//�̹���
	_stateImage[P_IDLE] = IMAGEMANAGER->addFrameDImage("charizard_idle_move",
		L"img/pokemon/3. charizard/idle_move.png", 264, 660, 4, 11);
	_stateImage[P_MOVE] = _stateImage[P_IDLE];

	_stateImage[P_ATTACK] = IMAGEMANAGER->addFrameDImage("charizard_attack",
		L"img/pokemon/3. charizard/attack.png", 328, 726, 4, 11);
	_stateImage[P_SATTACK] = IMAGEMANAGER->addFrameDImage("charizard_sattack",
		L"img/pokemon/3. charizard/sattack.png", 160, 704, 2, 11);
	_stateImage[P_HURT] = IMAGEMANAGER->addFrameDImage("charizard_hurt",
		L"img/pokemon/3. charizard/hurt.png", 62, 704, 1, 11);
	_stateImage[P_SLEEP] = IMAGEMANAGER->addFrameDImage("charizard_sleep",
		L"img/pokemon/3. charizard/sleep.png", 108, 58, 2, 1);

	//frameX, count
	_currentImage = _stateImage[P_IDLE];
	_frameX = 0;

	return S_OK;
}

void Charizard::release()
{
}

void Charizard::update()
{
}

void Charizard::render(float x, float y)
{
}
