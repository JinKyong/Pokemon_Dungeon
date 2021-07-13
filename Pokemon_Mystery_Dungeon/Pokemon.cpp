#include "stdafx.h"
#include "Pokemon.h"

void Pokemon::controlFrame()
{
	_frameCount += TIMEMANAGER->getElapsedTime();

	if (_frameCount >= _count[_state]) {
		if (_frameX >= _currentImage->getMaxFrameX()) {
			if (_state == P_DEFAULT || _state == P_MOVE || _state == P_SLEEP)
				_frameX = 0;
			else if (_state == P_ATTACK) {
			}
			else
				changeState(P_DEFAULT);
		}
		else
			_frameX++;

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

	_state = state;
	_currentImage = _stateImage[_state];

	if (_state == P_SLEEP)
		_frameY = 0;

	_frameX = 0;
	_idleCount = 0;
	_frameCount = 0;
}