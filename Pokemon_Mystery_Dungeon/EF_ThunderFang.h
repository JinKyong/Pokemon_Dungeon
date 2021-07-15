#pragma once
#include "Effect.h"
class EF_ThunderFang :
	public Effect
{
private :

public :
	EF_ThunderFang() {};
	~EF_ThunderFang() {};

	virtual HRESULT init(float x, float y);
	virtual void release();
	virtual void update();
	virtual void render();

	virtual void controlFrame();
};

