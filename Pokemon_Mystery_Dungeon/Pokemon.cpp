#include "stdafx.h"
#include "Pokemon.h"

void Pokemon::release()
{
}

void Pokemon::update()
{
}

void Pokemon::render(float x, float y)
{
	if (_state == POKEMON_STATE_IDLE)			tuneIdle();
	else if (_state == POKEMON_STATE_ATTACK)	tuneAttack();
	else if (_state == POKEMON_STATE_HURT)		tuneHurt();

	controlFrame();

	_currentImage->frameRender(
		x *TILEWIDTH + TILEWIDTH / 2 + _tuningX - _currentImage->getFrameWidth() / 2,
		y *TILEHEIGHT + TILEHEIGHT / 2 + _tuningY - _currentImage->getFrameHeight() / 2,
		_frameX, _frameY);
}

void Pokemon::controlFrame()
{
	_frameCount += TIMEMANAGER->getElapsedTime();

	if (_frameCount >= _count[_state]) {
		if (_frameX >= _currentImage->getMaxFrameX()) {
			if (_state == POKEMON_STATE_DEFAULT)
				changeState(POKEMON_STATE_IDLE);
			else if (_state == POKEMON_STATE_ATTACK) {

			}
			else if (_state == POKEMON_STATE_HURT) {
				changeState(POKEMON_STATE_DEFAULT);
				TURNMANAGER->setPause(false);
			}
			else if (_state == POKEMON_STATE_SLEEP)
				_frameX = 0;
			else
				changeState(POKEMON_STATE_DEFAULT);
		}
		else {
			_frameX++;
		}

		_frameCount = 0;
	}
}

void Pokemon::changeDirect(int direct)
{
	if (_frameY == direct) return;

	_frameY = direct;

	switch (_frameY) {
	case 1:		//RIGHT
		_angle = 0;
		break;
	case 2:		//LEFT
		_angle = PI;
		break;

	case 4:		//UP
		_angle = PI / 2;
		break;
	case 5:		//UPRIGHT
		_angle = PI / 4;
		break;
	case 6:		//UPLEFT
		_angle = 3 * PI / 4;
		break;

	case 8:		//DOWN
		_angle = 3 * PI2 / 4;
		break;
	case 9:		//DOWNRIGHT
		_angle = 7 * PI2 / 8;
		break;
	case 10:	//DOWNLEFT
		_angle = 5 * PI2 / 8;
		break;

	default:
		_angle = 0;
		break;
	}
}

void Pokemon::changeState(POKEMON_STATE state)
{
	if (_state == state) return;


	//���� ����
	_state = state;
	_currentImage = _stateImage[_state];


	//�̼����� �ʱ�ȭ
	_tuningX = 0;
	_tuningY = 0;


	//�̹��� ������/ī��Ʈ �ʱ�ȭ
	if (_state == POKEMON_STATE_SLEEP)
		_frameY = 0;
	_frameX = 0;
	_frameCount = 0;
}

void Pokemon::tuneIdle()
{
	_tuningX = 0;

	if (_jump)
		_tuningY = -4;
	else
		_tuningY = 0;

}

void Pokemon::tuneAttack()
{
	if (_frameX < _stateImage[POKEMON_STATE_ATTACK]->getMaxFrameX())
		_tmpCount = _frameX * _count[POKEMON_STATE_ATTACK] + _frameCount;
	else
		_tmpCount -= TIMEMANAGER->getElapsedTime() * 2;

	_tuningX = cosf(_angle) * attackRange(_tmpCount);
	_tuningY = -sinf(_angle) * attackRange(_tmpCount);

	if (_tmpCount < 0) {
		_tmpCount = 0;
		changeState(POKEMON_STATE_DEFAULT);
	}
}

void Pokemon::tuneHurt()
{
	_tuningX = -cosf(_angle) * TILEWIDTH / 4 + RND->getFromFloatTo(-1, 1);
	_tuningY = sinf(_angle) * TILEHEIGHT / 4 + RND->getFromFloatTo(-1, 1);
}

float Pokemon::attackRange(float x)
{
	return _gradient * (x - _interceptX) * (x - _interceptX) + _interceptY;
}