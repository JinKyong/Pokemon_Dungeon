#pragma once
#include "Effect.h"
class EF_Gust :
	public Effect
{
private :

public :
	EF_Gust() {};
	~EF_Gust() {};

	virtual HRESULT init(float x, float y);
	virtual void release();
	virtual void update();
};

