#pragma once
#include "Effect.h"
class EF_ShadowClaw :
	public Effect
{
private :

public :
	EF_ShadowClaw() {};
	~EF_ShadowClaw() {};

	virtual HRESULT init(float x, float y, int damage, int skillScale, int atkType);
	virtual void release();
	virtual void update();
};

