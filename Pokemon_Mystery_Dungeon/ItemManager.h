#pragma once
#include "Apple.h"

class ItemManager
{
private:
	Apple* _apple;

public:
	ItemManager() {};
	~ItemManager() {};

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void setItemDrop(float x, float y);
	Apple* getApple() { return _apple; } //뭔가 이게 아닌것같은데
};

