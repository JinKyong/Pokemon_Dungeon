#pragma once
#include "Item.h"

class Ribbon : public Item
{
private:

public:
	Ribbon() {};
	~Ribbon() {};

	virtual HRESULT init(float x, float y, float angle);
	virtual void release() = 0;
	virtual void update() = 0;
	virtual void render(float x, float y);

	//아이템 사용
	void giveItem();
};