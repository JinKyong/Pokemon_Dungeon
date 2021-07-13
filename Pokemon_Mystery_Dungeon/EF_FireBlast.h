#pragma once
#include "Effect.h"
class EF_FireBlast :
	public Effect
{
private :

public :
	EF_FireBlast() {};
	~EF_FireBlast() {};

	virtual HRESULT init(float x, float y);
	virtual void release();
	virtual void update();
	virtual void render();

	virtual void controlFrame();
};

