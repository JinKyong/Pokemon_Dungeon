#pragma once
#include "Scene.h"

class testScene : public Scene
{
private:
	dImage* _back;
	Player* _testEnemy;

public:
	HRESULT init(Player* player);
	void release();
	void update();
	void render();

	void changeScene();
};