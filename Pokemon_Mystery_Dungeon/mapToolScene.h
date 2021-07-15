#pragma once
#include "maptool.h"
#include "Scene.h"
#include "gameNode.h"

class mapToolScene : public Scene
{
private:
	dImage* _maptiles;
	dImage* _objects;
	Maptool* _maptool;
	int _width;
	int _height;
	int x;
	int y;

public:
	HRESULT init(Player *player);
	void release();
	void update();
	void render();
	void changeScene();
};

