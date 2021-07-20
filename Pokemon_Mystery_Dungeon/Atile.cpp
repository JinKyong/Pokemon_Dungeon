#include "stdafx.h"
#include "Atile.h"

Atile::Atile()
	: _totalCost(0), _costFromStart(0),
	_costToGoal(0), _parentNode(NULL),
	_idX(0), _idY(0), _isOpen(true)
{
}

Atile::~Atile()
{
}

HRESULT Atile::init(int x, int y)
{
	_isOpen = true;

	_idX = x;
	_idY = y;

	_center = PointMake(_idX * TILEWIDTH + (TILEWIDTH / 2),
		_idY * TILEHEIGHT + (TILEHEIGHT / 2));

	return S_OK;
}

void Atile::release()
{

}

void Atile::update()
{
}

void Atile::render()
{
}
