#pragma once
#include "Effect.h"
class EF_DynamicPunch :
	public Effect
{
private :

public :
	EF_DynamicPunch() {};
	~EF_DynamicPunch() {};

	virtual HRESULT init(float x, float y);
	virtual void release();
	virtual void update();
};

