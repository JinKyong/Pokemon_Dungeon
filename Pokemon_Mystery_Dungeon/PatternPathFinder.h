#pragma once
#include "Pattern.h"
#include "PathFinder.h"

class PatternPathFinder : public Pattern
{
private:
	PathFinder* _pathfinder;

public:
	virtual HRESULT init(Player* player);
	virtual void release();
	virtual void update();
	virtual void render();

	vector<Atile*> getCloseList() { return _pathfinder->getCloseList(); }
};

