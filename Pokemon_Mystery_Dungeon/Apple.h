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


	//������ ���
	void eatItem();

	//������ ������
	void throwItem(float x, float y, float angle);
	void itemMove(float x, float y, float angle);
};