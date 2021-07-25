#pragma once
#include "Effect.h"
class EF_Waterfall :
	public Effect
{
private :

public :
	EF_Waterfall() {};
	~EF_Waterfall() {};

	virtual HRESULT init(float x, float y, int damage, int skillScale, int atkType);
	virtual void release();
	virtual void update();
};

