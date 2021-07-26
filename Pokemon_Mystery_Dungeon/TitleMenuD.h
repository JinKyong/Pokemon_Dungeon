#pragma once
#include "DownMenu.h"

class TitleMenuD : public DownMenu
{
private:

public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

