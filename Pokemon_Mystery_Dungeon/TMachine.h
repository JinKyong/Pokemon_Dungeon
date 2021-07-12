#pragma once
#include "Item.h"

class TMachine : public Item
{
private:

public:
	TMachine() {};
	~TMachine() {};

	virtual HRESULT init(float x, float y);
	virtual void release() = 0;
	virtual void update() = 0;
	virtual void render(float x, float y) = 0;

	//������ ���
	virtual void useItem();
	virtual void throwItem(float x, float y, float angle) = 0;

	virtual void itemMove(float x, float y, float angle) = 0;
};