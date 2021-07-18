#pragma once
#include "Scene.h"
#include "ItemManager.h"

#define MAPWIDTH	41
#define MAPHEIGHT	41

class testMapScene : public Scene
{
private:

	int _width;
	int _height;

	Player* _pokemon1;
	Player* _pokemon2;
	Player* _pokemon3;

	ItemManager* _im;

public:

	HRESULT init(Player *player);
	void release();
	void update();
	void render();
	void changeScene();
};

