#pragma once
#include "Effect.h"
class EF_Bind :
	public Effect
{
private :

public :
	EF_Bind() {};
	~EF_Bind() {};

	virtual HRESULT init(float x, float y, int damage, int skillScale, int atkType);
	virtual void release();
	virtual void update();
};

