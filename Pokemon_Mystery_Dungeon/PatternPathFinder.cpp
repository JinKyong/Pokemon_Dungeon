#include "stdafx.h"
#include "PatternPathFinder.h"

HRESULT PatternPathFinder::init(Player * player)
{
	Pattern::init(player);

	_pathfinder = new PathFinder;
	_pathfinder->init(player);

	return S_OK;
}

void PatternPathFinder::release()
{
}

void PatternPathFinder::update()
{
	_pathfinder->update();
	_player->setPathList(_pathfinder->getCloseList());
}

void PatternPathFinder::render()
{

}