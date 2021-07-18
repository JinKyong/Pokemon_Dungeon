#pragma once
#include "Effect.h"
class EF_LeafBlade :
	public Effect
{
private :

public :
	EF_LeafBlade() {};
	~EF_LeafBlade() {};

	virtual HRESULT init(float x, float y);
	virtual void release();
	virtual void update();
};

