#pragma once
#include "Effect.h"
class EF_IceFang :
	public Effect
{
private :

public :
	EF_IceFang() {};
	~EF_IceFang() {};

	virtual HRESULT init(float x, float y);
	virtual void release();
	virtual void update();
	virtual void render();

	virtual void controlFrame();
};

