#pragma once
#include "Item.h"

class Apple : public Item
{
private:

public:
	Apple() {};
	~Apple() {};

	virtual HRESULT init(float x, float y);
	virtual void release() = 0;
	virtual void update() = 0;
	virtual void render(float x, float y);


	//아이템 사용
	//아이템 사용
	void eatItem();
};