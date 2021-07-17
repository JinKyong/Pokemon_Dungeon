#pragma once
#include "singletonBase.h"
#define STATUSWIDTH 206

class uiManager : public singletonBase<uiManager>
{
private:
	D2D1_RECT_F _screen;

	//여기 필요한 이미지 생성하고
	dImage* _back;

	dImage* _testKey[2];
	int _key;

	D2D1_RECT_F _status[4];
	D2D1_RECT_F _pokeNumRC;
	dImage* _testStat;
	dImage* _pokeNum;
	int _option;
	bool _isNull;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	void keySetting();
	void status();

	D2D1_RECT_F getScreen() { return _screen; }
};

