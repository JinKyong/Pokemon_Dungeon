#pragma once
#include "Effect.h"
class EF_Pound :
	public Effect
{
private :

public :
	EF_Pound() {};
	~EF_Pound() {};

	virtual HRESULT init(float x, float y);
	virtual void release();
	virtual void update();
};

