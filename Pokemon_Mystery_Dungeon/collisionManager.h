#pragma once
#include "singletonBase.h"
#include <vector>

class collisionManager : public singletonBase<collisionManager>
{
private:

	//�浹�ϴ� ��ü�� �ľ��ϱ�
	//�÷��̾�� ���ʹ�
	//�÷��̾�� ������

public:
	collisionManager() {};
	~collisionManager() {};

	void release();

};
