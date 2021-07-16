#pragma once
#include "Item.h"

class Glass : public Item
{
	Glass() {};
	~Glass() {};

	virtual HRESULT init(float x, float y, float angle);
	virtual void release();
	virtual void update();
	virtual void render(float x, float y);

	//아이템 사용
	void giveItem();
};