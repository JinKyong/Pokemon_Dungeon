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
	//��ü Ÿ�� ����
	vector<PTILE>*	_allTileList;
	int _mapWidth;
	int _mapHeight;

	//��ü Ÿ�� ���� ����
	tileList	_vTotalList;
	tileIter	_viTotalList;

	//�� �� �ִ� Ÿ�� ���� ����
	tileList	_vOpenList;
	tileIter	_viOpenList;

	//���� ����� ��θ� ���� ����
	tileList	_vCloseList;
	tileIter	_viCloseList;

	//���� ���
	tileList	_vPathList;

	//����, ��, ���� Ÿ��
	Atile*		_startTile;
	Atile*		_endTile;
	Atile*		_currentTile;

public:
	PathFinder();
	~PathFinder();

	HRESULT init();
	void release();
	void update();

	//Ÿ�� ���� �Լ�
	void setTiles(Player* player);
	void setTiles(Player* startPlayer, Player* destPlayer);
	//�� �� �ִ� ���� ã�� ����� �Լ�
	vector<Atile*> addOpenList(Atile* currentTile);
	//�� ã�� �Լ�
	void findPath(Atile* currentTile);





	tileList& getPathList() { return _vPathList; }
};