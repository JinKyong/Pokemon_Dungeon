#include "stdafx.h"
#include "Charmander.h"

Charmander::Charmander()
{
}

Charmander::~Charmander()
{
}

HRESULT Charmander::init()
{
	//이미지
	_stateImage[P_IDLE] = IMAGEMANAGER->addFrameDImage("charmander_idle_move",
		L"img/pokemon/1. charmander/idle_move.png", 144, 528, 3, 11);
	_stateImage[P_MOVE] = _stateImage[P_IDLE];

	_stateImage[P_ATTACK] = IMAGEMANAGER->addFrameDImage("charmander_attack",
		L"img/pokemon/1. charmander/attack.png", 144, 528, 3, 11);
	_stateImage[P_SATTACK] = IMAGEMANAGER->addFrameDImage("charmander_sattack",
		L"img/pokemon/1. charmander/sattack.png", 46, 550, 1, 11);
	_stateImage[P_HURT] = IMAGEMANAGER->addFrameDImage("charmander_hurt",
		L"img/pokemon/1. charmander/hurt.png", 48, 528, 1, 11);
	_stateImage[P_SLEEP] = IMAGEMANAGER->addFrameDImage("charmander_sleep",
		L"img/pokemon/1. charmander/sleep.png", 96, 48, 2, 1);
	_stateImage[P_DEFAULT] = IMAGEMANAGER->addFrameDImage("charmander_default",
		L"img/pokemon/1. charmander/default.png", 48, 528, 1, 11);

	//frame
	changeDirect(DOWN);
	changeState(P_DEFAULT);

	//frameCount
	_count[P_IDLE] = 0.2;
	_count[P_MOVE] = 0.2;
	_count[P_ATTACK] = 0.2;
	_count[P_SATTACK] = 0.5;
	_count[P_HURT] = 0.5;
	_count[P_SLEEP] = 0.5;
	_count[P_DEFAULT] = 0;

	//이름
	_name = L"파이리";

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


	_tmpX = 0;
	_tmpY = 0;
	_tmpCount = 0;
	_tmpCountMax = 0;

	_p = _count[P_ATTACK] * (_stateImage[P_ATTACK]->getMaxFrameX() + 1);
	_q = 3 * PSIZEX / 4;
	_a = -_q / (_p * _p);
	_attack = false;
	_attackDirect = true;

	return S_OK;
}

void Charmander::release()
{
}

void Charmander::update()
{
	if (_state == P_DEFAULT) {
		_tmpCount = 0;
		_idleCount += TIMEMANAGER->getElapsedTime();

		if (_idleCount >= 0.5)
			changeState(P_IDLE);
	}
}

void Charmander::render(float x, float y)
{
	controlFrame();

	if (_state == P_ATTACK)
		_attack = true;
	if (_attack) {
		if (_tmpCount >= _p * 0.75)
			_attackDirect = false;

		if (_attackDirect) {
			_tmpCount += TIMEMANAGER->getElapsedTime();
		}
		else {
			_tmpCount -= TIMEMANAGER->getElapsedTime() * 4;
		}
			_tmpX = (x + cosf(_angle) * attackRange(_tmpCount));
			_tmpY = (y - sinf(_angle) * attackRange(_tmpCount));
		

		if (_tmpCount <= 0) {
			_attack = false;
			_attackDirect = true;
			_tmpCountMax = 0;
			changeState(P_DEFAULT);
		}
	}
	//(0, 0), (_count[P_ATTACK] * 0.75, 3*PISZE/4), (_count[P_ATTACK] * 1.5, 0) 세 점의 좌표를 앎
	switch (_state) {

	case P_IDLE:
		renderImage(x, y - 3);
		break;


	case P_ATTACK:
		renderImage(_tmpX, _tmpY);
		//renderImage(x + cosf(_angle) * _frameX * PSIZEX / _currentImage->getMaxFrameX(),
			//y - sinf(_angle) * _frameX * PSIZEY / _currentImage->getMaxFrameX());
		break;


	case P_HURT:
		renderImage(x - cosf(_angle) * 10 + RND->getFromFloatTo(-1, 1),
			y + sinf(_angle) * 10 + RND->getFromFloatTo(-1, 1));
		break;

	default:
		renderImage(x, y);
		break;
	}
}

float Charmander::attackRange(float x)
{
	return _a * (x - _p) * (x - _p) + _q;
}

void Charmander::renderImage(float x, float y)
{
	_currentImage->frameRender(
		x - _currentImage->getFrameWidth() / 2, y - _currentImage->getFrameHeight() / 2,
		_frameX, _frameY);
}

void Charmander::renderAttack(float x, float y)
{
	//위치 조정
	float tmpX, tmpY;

	switch (_frameX) {
	case 0:
		tmpX = x;
		tmpY = y;
		break;

	case 1:
		tmpX = x + cosf(_angle) * 3 * PSIZEX / 4;
		tmpY = y + -sinf(_angle) * 3 * PSIZEX / 4;
		break;

	case 2:
		tmpX = x + cosf(_angle) * 3 * PSIZEX / 4;
		tmpY = y + -sinf(_angle) * 3 * PSIZEX / 4;
		break;
	}

	//render
	renderImage(tmpX, tmpY);
}