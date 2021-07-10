#pragma once
#include "Scene.h"

class testScene : public Scene
{
private:
	float _x, _y;
	RECT _rc;

	dImage* _back;
	dImage* _moveImg;

	int _frameX;
	int _frameY;

	int _count;

	float _angle;
	bool _rotate;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	void changeScene();
	void controlFrame();
};

