#pragma once
#include "Item.h"

class Scope : public Item
{
	Scope() {};
	~Scope() {};

	virtual HRESULT init(float x, float y);
	virtual void release() = 0;
	virtual void update() = 0;
	virtual void render(float x, float y);

	//아이템 사용
	void giveItem();
};

