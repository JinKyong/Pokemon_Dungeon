#pragma once
#include "Scene.h"
#include "ItemManager.h"

#define MAPWIDTH	151
#define MAPHEIGHT	151

class testMapScene : public Scene
{
private:
	Player* _pokemon1;
	Player* _pokemon2;
	Player* _pokemon3;

public:

	HRESULT init(Player *player);
	void release();
	void update();
	void render();
	void changeScene();
};

