#pragma once
#include "Item.h"

class Apple : public Item
{
private:

public:
	Apple() {};
	~Apple() {};

	virtual HRESULT init(float x, float y, float angle);
	virtual void release();
	virtual void update();

	//아이템 사용
	void eatItem(float value);

	//get-set

};