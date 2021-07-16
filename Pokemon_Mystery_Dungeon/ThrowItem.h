#pragma once
#include "Item.h"

class ThrowItem : public Item
{
private:
	int _num;

public:
	ThrowItem() {};
	~ThrowItem() {};

	virtual HRESULT init(float x, float y, float angle);
	virtual void release();
	virtual void update();
	virtual void render();
};
