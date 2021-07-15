#pragma once
#include "Effect.h"
class EF_SleepPowder :
	public Effect
{
private :

public :
	EF_SleepPowder() {};
	~EF_SleepPowder() {};

	virtual HRESULT init(float x, float y);
	virtual void release();
	virtual void update();
	virtual void render();

	virtual void controlFrame();
};

