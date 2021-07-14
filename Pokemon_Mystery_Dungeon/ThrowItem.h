#pragma once
#include "Item.h"

class ThrowItem : public Item
{
private:

public:
	ThrowItem() {};
	~ThrowItem() {};

	virtual HRESULT init(float x, float y);
	virtual void release() = 0;
	virtual void update() = 0;
	virtual void render(float x, float y);

	//아이템 던지기
	void throwItem(float x, float y, float angle);
	void itemMove(float x, float y, float angle);
};

