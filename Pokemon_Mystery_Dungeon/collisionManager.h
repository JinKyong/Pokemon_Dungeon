#pragma once
#include "singletonBase.h"
#include <vector>

class collisionManager : public singletonBase<collisionManager>
{
private:

public:
	collisionManager() {};
	~collisionManager() {};

	void release();

};
