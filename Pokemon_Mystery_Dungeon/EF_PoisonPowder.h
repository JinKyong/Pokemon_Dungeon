#pragma once
#include "Effect.h"
class EF_PoisonPowder :
	public Effect
{
private :

public :
	EF_PoisonPowder() {};
	~EF_PoisonPowder() {};

	virtual HRESULT init(float x, float y);
	virtual void release();
	virtual void update();
	virtual void render();

	virtual void controlFrame();
};

