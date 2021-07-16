#pragma once
#include "tileNode.h"
#include "gameNode.h"

class sampleMap:public gameNode
{
	tagTile _tile[TILEX*TILEY];
	DWORD _attribute[TILEX*TILEY];

	dImage* _Mapbase;
	dImage* _Obbase;
public:
	sampleMap();
	~sampleMap();
	
	HRESULT init();
	void release();
	void update();
	void render();
	void load();

	tagTile* getTile() { return _tile; }

	DWORD* getTileAttribute() { return _attribute; }

	
};

