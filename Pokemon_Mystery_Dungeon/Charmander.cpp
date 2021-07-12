#include "stdafx.h"
#include "Charmander.h"

HRESULT Charmander::init()
{
	//�̹���
	_stateImage[P_IDLE] = IMAGEMANAGER->addFrameDImage("charmander_idle",
		L"img/pokemon/1. charmander/charmander_idle.png", 192, 528, 4, 11);
	_stateImage[P_MOVE] = _stateImage[P_IDLE];

	_stateImage[P_ATTACK] = IMAGEMANAGER->addFrameDImage("charmander_attack",
		L"img/pokemon/1. charmander/charmander_attack.png", 144, 528, 3, 11);
	_stateImage[P_SATTACK] = IMAGEMANAGER->addFrameDImage("charmander_sattack",
		L"img/pokemon/1. charmander/charmander_sattack.png", 46, 550, 1, 11);
	_stateImage[P_HURT] = IMAGEMANAGER->addFrameDImage("charmander_hurt",
		L"img/pokemon/1. charmander/charmander_hurt.png", 48, 528, 1, 11);
	_stateImage[P_SLEEP] = IMAGEMANAGER->addFrameDImage("charmander_sleep",
		L"img/pokemon/1. charmander/charmander_sleep.png", 96, 48, 2, 1);

	//����
	_direct = RIGHT;
	_currentImg = _stateImage[P_IDLE];
	_frameX = 0;

	//��ǥ & Body
	_x = WINSIZEX;
	_y = WINSIZEY;
	_body = RectMakeCenter(_x, _y, PSIZEX, PSIZEY);



	//�̸�
	_name = L"���̸�";

	//���� & ����ġ
	_level = 1;
	_EXP = 0;



	//Ÿ�� & Ư��
	_type = TYPE_FIRE;
	//Ư�� _passive;



	//����
	_hp = 15;
	_attack = 5;
	_defense = 5;
	_sattack = 5;
	_sdefense = 5;
	_speed = 5;



	//���(��ų)
	//Skill _skill[4];

	return S_OK;
}

void Charmander::release()
{
}

void Charmander::update()
{
	_body = RectMakeCenter(_x, _y, PSIZEX, PSIZEY);
}

void Charmander::render()
{
	controlFrame();

	_currentImg->frameRender(_x - _currentImg->getFrameWidth() / 2, _y - _currentImg->getFrameY() / 2,
		_frameX, _direct);
}

void Charmander::changeState(POKEMON_STATE state)
{
	if (_state == state) return;

	if (_currentImg != _stateImage[state])
		_frameX = 0;
	_currentImg = _stateImage[state];
}

void Charmander::changeDirect(int direct)
{
	_direct = direct;
}
