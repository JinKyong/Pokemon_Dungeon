#pragma once
#include "Effect.h"
class EF_WingAttack :
	public Effect
{
private :

public :
	EF_WingAttack() {};
	~EF_WingAttack() {};

	virtual HRESULT init(float x, float y, int damage, int skillScale, int atkType);
	virtual void release();
	virtual void update();
};

