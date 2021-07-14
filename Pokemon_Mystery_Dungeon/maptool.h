#pragma once
#include "gameNode.h"
#include "tileNode.h"
#include <vector>


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

class maptool : public gameNode
{

private:
	HWND _btnSave;
	HWND _btnLoad;
	HWND _btnRandom;
	HWND _btnTerrainDraw;
	HWND _btnObjectDraw;
	HWND _btnEraser;


	tagCurrentTile _currentTile;
	tagSampleTile _sampleTile[SAMPLETILEX * SAMPLETILEY];
	tagTile _tiles[TILEX * TILEY];

	//dungeon* Dungeon;
	dImage* _maptile;
	dImage* _object;
	int _pos[2];

	int type;

public:
	maptool();
	~maptool();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	virtual void setup();
	virtual void setMap();

	virtual void save();
	virtual void load();

	TERRAIN terrainSelect(int frameX, int frameY);
	OBJECT objSelect(int frameX, int frameY);


};

//class dungeon
//{
//private:
//	vector<Body>						_vRoom;
//	vector<Body>::iterator				_viRoom;
//	vector<Body>						_vExit;
//	vector<Body>::iterator				_viExit;
//	vector<Body>					_vCorridor;
//	vector<Body>::iterator			_viCorridor;
//
//	int _width;
//	int _height;
//	
//
//
//	tagCurrentTile _currentTile;
//	tagSampleTile _sampleTile[SAMPLETILEX * SAMPLETILEY];
//	tagTile _tiles[TILEX * TILEY];
//	
//public:
//	HRESULT init(int width, int height);
//	void release();
//	void update();
//	void render();
//
//	void setFeature(int maxFeature);
//	void setRoom(int Feature, int x, int y, Direction dir);
//	void setCorridor(int Feature, int x, int y, Direction dir);
//	void setExit(int x, int y, Direction dir);
//	void placeObject(char tile);
//	bool placeRect(Body& body);
//
//
//
//
//	vector<tagRoom>					getVRoom() { return _vRoom; }
//	vector<tagRoom>::iterator		getVIRoom() { return _viRoom; }
//	vector<tagExit>					getVExit() { return _vExit; }
//	vector<tagExit>::iterator		getVIExit() { return _viExit; }
//	vector<tagCorridor>				getVCorridor() { return _vCorridor; }
//	vector<tagCorridor>::iterator	getVICorridor() { return _viCorridor; }
//};