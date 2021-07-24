#pragma once
#include "Effect.h"
class EF_Gust :
	public Effect
{
private:

public:
	EF_Gust() {};
	~EF_Gust() {};

	virtual HRESULT init(float x, float y, int damage, int skillScale, int atkType, POKEMON_TYPE type);
	virtual void release();
	virtual void update();
};

