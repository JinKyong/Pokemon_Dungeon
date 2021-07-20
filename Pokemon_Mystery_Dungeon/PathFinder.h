#pragma once
#include "Atile.h"
#include <vector>

class Player;

class PathFinder

{
private:
	typedef vector<Atile*>				tileList;
	typedef vector<Atile*>::iterator	tileIter;

private:
	//전체 타일 벡터
	vector<PTILE>*	_allTileList;
	int _mapWidth;
	int _mapHeight;

	//전체 타일 담을 벡터
	tileList	_vTotalList;
	tileIter	_viTotalList;

	//갈 수 있는 타일 담을 벡터
	tileList	_vOpenList;
	tileIter	_viOpenList;

	//가장 가까운 경로를 담을 벡터
	tileList	_vCloseList;
	tileIter	_viCloseList;

	//시작, 끝, 현재 타일
	Atile*		_startTile;
	Atile*		_endTile;
	Atile*		_currentTile;

public:
	PathFinder();
	~PathFinder();

	HRESULT init(Player* player);
	void release();
	void update();

	//타일 셋팅 함수
	void setTiles();
	//갈 수 있는 길을 찾아 담아줄 함수
	vector<Atile*> addOpenList(Atile* currentTile);
	//길 찾는 함수
	void findPath(Atile* currentTile);





	tileList getCloseList() { return _vCloseList; }
};