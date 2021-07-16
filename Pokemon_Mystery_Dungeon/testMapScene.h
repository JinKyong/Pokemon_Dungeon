#pragma once
#include "Scene.h"
#include "sampleMap.h"

class testMapScene :
	public Scene
{
private:
	vector<tagTile>				_vTile;
	vector<tagTile>::iterator	_viTile;
	sampleMap* _sample;
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
	void mapset();
};

