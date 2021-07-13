#pragma once
#include "Effect.h"
class EF_RockSlide :
	public Effect
{
private :

public :
	EF_RockSlide() {};
	~EF_RockSlide() {};

	virtual HRESULT init(float x, float y);
	virtual void release();
	virtual void update();
	virtual void render();

	virtual void controlFrame();
};

