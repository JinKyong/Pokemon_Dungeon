#pragma once
#include "Item.h"

class Scope : public Item
{
	Scope() {};
	~Scope() {};

	virtual HRESULT init(float x, float y, float angle);
	virtual void release();
	virtual void update();

	//������ ���
	void giveItem();
};