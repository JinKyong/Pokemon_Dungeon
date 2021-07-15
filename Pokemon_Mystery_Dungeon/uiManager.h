#pragma once
#include "singletonBase.h"
class uiManager : public singletonBase<uiManager>
{
private:
	D2D1_RECT_F _screen;

	dImage* _testImage;
	//���� �ʿ��� �̹��� �����ϰ�

public:
	HRESULT init();
	void release();
	void update();
	void render();

	D2D1_RECT_F getScreen() { return _screen; }
};

