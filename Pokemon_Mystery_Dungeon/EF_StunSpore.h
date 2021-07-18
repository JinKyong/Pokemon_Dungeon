#pragma once
#include "Effect.h"
class EF_StunSpore :
	public Effect
{
private:

public:
	EF_StunSpore() {};
	~EF_StunSpore() {};

	virtual HRESULT init(float x, float y);
	virtual void release();
	virtual void update();
};

