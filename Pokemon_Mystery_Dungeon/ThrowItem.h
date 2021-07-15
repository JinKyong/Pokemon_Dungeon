#pragma once
#include "Item.h"

class ThrowItem : public Item
{
private:

public:
	ThrowItem() {};
	~ThrowItem() {};

	virtual HRESULT init(float x, float y, float angle);
	virtual void release() = 0;
	virtual void update();
	virtual void render(float x, float y);
};
