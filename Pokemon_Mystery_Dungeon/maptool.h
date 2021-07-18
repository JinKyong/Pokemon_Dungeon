#pragma once
#include "gameNode.h"
//·£´ý ·ë »ý¼º
struct tagRoom
{
	TERRAIN		terrain;
	OBJECT		obj;
	RECT		rc;
	int			terrainFrameX;
	int			terrainFrameY;
	int			objFrameX;
	int			objFrameY;
};
//·£´ý Å»Ãâ±¸
struct tagExit
{
	TERRAIN		terrain;
	OBJECT		obj;
	RECT		rc;
	int			terrainFrameX;
	int			terrainFrameY;
	int			objFrameX;
	int			objFrameY;
};
//·£´ý º¹µµ
struct tagCorridor
{
	TERRAIN		terrain;
	OBJECT		obj;
	RECT		rc;
	int			terrainFrameX;
	int			terrainFrameY;
	int			objFrameX;
	int			objFrameY;
};

struct Body
{
	int x;
	int y;
	int width;
	int height;
};

class Maptool :public gameNode
{

private:
	
	vector<tagTile*>					_vTile;
	vector<tagTile*>::iterator			_viTile;
	vector<tagSampleTile*>				_vSampleTile;
	vector<tagSampleTile*>::iterator	_viSampleTile;
	vector<DWORD*>						_vAttribute;
	vector<DWORD*>::iterator			_viAttribute;


	tagCurrentTile _currentTile;
	tagSampleTile _sampleTile[SAMPLETILEX * SAMPLETILEY];
	tagTile _tiles[TILEX * TILEY];
	DWORD _attribute[TILEX * TILEY];	//Å¸ÀÏ¼Ó¼º

	dImage* _maptile;
	dImage* _object;
	int _pos[2];

	int _ctrSelect;
	int type;

public:
	Maptool();
	~Maptool();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	virtual void setup();
	virtual void setMap();

	void minimap();

	dImage* getMaptile() { return _maptile; }
	dImage* getObject() { return _object; }
	
	int getType() { return type; }
	
	DWORD* getTileAttribute() { return _attribute; }
	TERRAIN terrainSelect(int frameX, int frameY);
	OBJECT objSelect(int frameX, int frameY);


};

