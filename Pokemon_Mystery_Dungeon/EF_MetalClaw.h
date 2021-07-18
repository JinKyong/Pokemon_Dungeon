#pragma once
#include "Effect.h"
class EF_MetalClaw :
	public Effect
{
private :

public :
	EF_MetalClaw() {};
	~EF_MetalClaw() {};

	virtual HRESULT init(float x, float y);
	virtual void release();
	virtual void update();
};

