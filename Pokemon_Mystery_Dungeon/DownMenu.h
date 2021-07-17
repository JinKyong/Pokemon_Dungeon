#pragma once
#include "KeyNDirect.h"

class DownMenu
{
protected:
	dImage* _back;
	dImage* _border;
	dImage* _arrow;

	float _tuningX;
	float _tuningY;

	int _index;

public:
	virtual HRESULT init() = 0;
	virtual void release() = 0;
	virtual void update() = 0;
	virtual void render();
};

