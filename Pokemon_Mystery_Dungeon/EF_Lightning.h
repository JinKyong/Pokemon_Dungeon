#pragma once
#include "Effect.h"
class EF_Lightning :
	public Effect
{
private :

public :
	EF_Lightning() {};
	~EF_Lightning() {};

	virtual HRESULT init(float x, float y);
	virtual void release();
	virtual void update();
	virtual void render();

	virtual void controlFrame();
};

