#pragma once
#include "Scene.h"

class titleScene : public Scene
{
public:
	HRESULT init(Player* player);
	void release();
	void update();
	void render();

	void changeScene();
};

