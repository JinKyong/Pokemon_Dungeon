#include "stdafx.h"
#include "Pathfinder.h"
#include "Player.h"

PathFinder::PathFinder()
{
}

PathFinder::~PathFinder()
{
}

HRESULT PathFinder::init(Player * player)
{
	release();

	_allTileList = TILEMANAGER->getvTile();
	_mapWidth = TILEMANAGER->getWidth();
	_mapHeight = TILEMANAGER->getHeight();

	_startTile = new Atile;
	_startTile->init(player->getX(), player->getY());
	_startTile->setAttribute("start");

	//�� �������� ����
	vector<RECT>* rooms = TILEMANAGER->getvRoom();
	int roomNum = RND->getInt(rooms->size());

	_endTile = new Atile;
	_endTile->init(RND->getFromIntTo((*rooms)[roomNum].left, (*rooms)[roomNum].right),
		RND->getFromIntTo((*rooms)[roomNum].top, (*rooms)[roomNum].bottom));
	_endTile->setAttribute("end");

	setTiles();

	return S_OK;
}

void PathFinder::release()
{
	//��ü���� �����ֱ�
	_viTotalList = _vTotalList.begin();
	for (; _viTotalList != _vTotalList.end();) {
		if (*_viTotalList)	SAFE_DELETE(*_viTotalList);
		_viTotalList = _vTotalList.erase(_viTotalList);
	}


	//���� Ŭ����
	_vTotalList.clear();
	_vOpenList.clear();
	_vCloseList.clear();
}

void PathFinder::update()
{
	findPath(_currentTile);
}

void PathFinder::setTiles()
{
	//���� Ÿ���� ����Ÿ�Ϸ�
	_currentTile = _startTile;

	//Ÿ�� ����
	for (int i = 0; i < _mapHeight; i++) {
		for (int j = 0; j < _mapWidth; j++) {
			if (j == _startTile->getIdX() && i == _startTile->getIdY())
			{
				_vTotalList.push_back(_startTile);
				continue;
			}
			if (j == _endTile->getIdX() && i == _endTile->getIdY())
			{
				_vTotalList.push_back(_endTile);
				continue;
			}

			Atile* node = new Atile;
			node->init(j, i);
			_vTotalList.push_back(node);
		}
	}
}

vector<Atile*> PathFinder::addOpenList(Atile * currentTile)
{
	int startX = currentTile->getIdX() - 1;
	int startY = currentTile->getIdY() - 1;
	int endX = currentTile->getIdX() + 1;
	int endY = currentTile->getIdY() + 1;

	//����ó��
	if (startX < 0)
		startX = 0;
	if (startY < 0)
		startY = 0;
	if (endX >= _mapWidth)
		endX = _mapWidth - 1;
	if (endY >= _mapHeight)
		endY = _mapHeight - 1;

	for (int i = startY; i <= endY; ++i)
	{
		for (int j = startX; j <= endX; ++j)
		{
			int index = i * _mapWidth + j;
			Atile* node = _vTotalList[index];

			//����ó��
			if (!node->getIsOpen()) continue;
			if (node->getAttribute() == "start") continue;
			if ((*_allTileList)[index]->obj <= OBJ_BLOCK8) continue;

			//���� Ÿ�� ��� �������ش�
			node->setParentNode(_currentTile);

			//�ֺ� Ÿ���� �����ϸ鼭 üũ�ߴ��� ������ �˼��ְ� ������ �Ұ� ����
			bool addObj = true;

			for (_viOpenList = _vOpenList.begin(); _viOpenList != _vOpenList.end(); ++_viOpenList)
			{
				//�̹� �ִ� �ִ�
				if (*_viOpenList == node)
				{
					addObj = false;
					break;
				}
			}

			//�̹� üũ�� �ִ� �ǳʶڴ�
			if (!addObj) continue;

			//���� �ִ� Ÿ���� ���¸���Ʈ ���Ϳ� ����ش�
			_vOpenList.push_back(node);
		}
	}

	return _vOpenList;
}

void PathFinder::findPath(Atile * currentTile)
{
	//���ϱ� ���� ������ ��κ���� �����صд�
	float tempTotalCost = 5000;
	Atile* tempTile = nullptr;

	//���¸���Ʈ ���� �ȿ���, ���� ���� ��θ� �̾Ƴ���
	for (int i = 0; i < addOpenList(currentTile).size(); ++i)
	{
		//H �� ����
		_vOpenList[i]->setCostToGoal(
			abs(_endTile->getIdX() - _vOpenList[i]->getIdX()) * TILEWIDTH +
			abs(_endTile->getIdY() - _vOpenList[i]->getIdY()) * TILEHEIGHT);

		//
		POINT center1 = _vOpenList[i]->getParentNode()->getCenter();
		POINT center2 = _vOpenList[i]->getCenter();

		//Ÿ�� ���� ���̿� ���̰� (Ÿ�ϻ�����)���� ũ��? ũ�� �밢��, �ƴϸ� �����¿�
		_vOpenList[i]->setCostFromStart((getDistance(center1.x, center1.y, center2.x, center2.y) > TILEWIDTH) ? 1.414 * TILEWIDTH : TILEWIDTH);

		//�� ��κ�� == �� �� �ִ� Ÿ�� �� �߿��� �� ��� ����
		_vOpenList[i]->setTotalCost(_vOpenList[i]->getCostToGoal() +
			_vOpenList[i]->getCostFromStart());

		//�׷��� �̾Ƴ� �� ��κ����� ������ ��κ��� �����ؼ�,
		//���� ���� ���� ��� �̾Ƴ���
		if (tempTotalCost > _vOpenList[i]->getTotalCost())
		{
			tempTotalCost = _vOpenList[i]->getTotalCost();
			tempTile = _vOpenList[i];
		}

		bool addObj = true;
		for (_viOpenList = _vOpenList.begin(); _viOpenList != _vOpenList.end(); ++_viOpenList)
		{
			if (*_viOpenList == tempTile)
			{
				addObj = false;
				break;
			}
		}

		_vOpenList[i]->setIsOpen(false);
		if (!addObj) continue;

		_vOpenList.push_back(tempTile);
	}

	//�������� �����ϸ� �ߴ�
	if (tempTile->getAttribute() == "end")
		return;


	//�ִ� ��θ� �̾�����
	_vCloseList.push_back(tempTile);

	for (_viOpenList = _vOpenList.begin(); _viOpenList != _vOpenList.end(); ++_viOpenList)
	{
		//�̾Ƴ� �ִ� ��δ� ���¸���Ʈ���� ������Ų��
		if (*_viOpenList == tempTile)
		{
			_viOpenList = _vOpenList.erase(_viOpenList);
			break;
		}
	}

	_currentTile = tempTile;

	//�Լ��ȿ��� �Ȱ��� �Լ��� ȣ�� �ϴ°� ����Լ�
	//����Լ��� �ݵ�� ������ �� �ִµ�
	//�� �� ȣ��� Stack�޸𸮰� ���̴µ�, 1.2�ް� �̻� �����Ǹ�
	//���ÿ����÷ο� ������ �����
	findPath(_currentTile);
}
