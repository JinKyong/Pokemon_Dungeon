#pragma once
#include "singletonBase.h"
#include <vector>

class collisionManager : public singletonBase<collisionManager>
{
private:

	//충돌하는 객체들 파악하기
	//플레이어랑 에너미
	//플레이어랑 아이템

public:
	collisionManager() {};
	~collisionManager() {};

	void release();

};
