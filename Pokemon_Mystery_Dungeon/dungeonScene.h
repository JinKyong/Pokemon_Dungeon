#pragma once
#include "Scene.h"
#include "ItemManager.h"


class dungeonScene : public Scene
{
private:
	Player* _pokemon1;
	Player* _pokemon2;
	Player* _pokemon3;
	

	int _width;
	int _height;
	int _type;
public:

	HRESULT init(Player *player);
	void release();
	void update();
	void render();
	void changeScene();

};

