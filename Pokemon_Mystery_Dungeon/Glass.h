#pragma once
#include "Item.h"

class Glass : public Item
{
	Glass() {};
	~Glass() {};

	virtual HRESULT init(float x, float y, float angle);
	virtual void release();
	virtual void update();

	//������ ���
	void giveItem();
};