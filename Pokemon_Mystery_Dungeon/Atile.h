#pragma once
#include "tileInfo.h"

class Atile
{
private:
	int _idX;
	int _idY;

	POINT _center;

	//F = G + H 
	//F == �� �Ÿ� ��� (TotalCost)
	//G == ���������κ��� ���� ������ ��κ��(CostFromStart)
	//H == ������κ��� ���������� ��κ��(CostToGoal)

	float _totalCost;
	float _costFromStart;
	float _costToGoal;

	bool _isOpen;//�����ִ� Ÿ������ ����

	Atile* _parentNode; //���� ���� Ÿ�� (��� ���ŵǴ� Ÿ��)
	string _attribute;

public:
	Atile();
	~Atile();

	HRESULT init(int x, int y);

	//============ ���� ���� ������ & ������ ===============

	int getIdX() { return _idX; }
	void setIdX(int x) { _idX = x; }
	int getIdY() { return _idY; }
	void setIdY(int y) { _idY = y; }

	void setCenter(POINT center) { _center = center; }
	POINT getCenter() { return _center; }

	void setAttribute(string str) { _attribute = str; }
	string getAttribute() { return _attribute; }

	void setTotalCost(float totalCost) { _totalCost = totalCost; }
	float getTotalCost() { return _totalCost; }

	void setCostFromStart(float costFromStart) { _costFromStart = costFromStart; }
	float getCostFromStart() { return _costFromStart; }

	void setCostToGoal(float costToGoal) { _costToGoal = costToGoal; }
	float getCostToGoal() { return _costToGoal; }

	void setParentNode(Atile* t) { _parentNode = t; }
	Atile* getParentNode() { return _parentNode; }

	void setIsOpen(bool isOpen) { _isOpen = isOpen; }
	bool getIsOpen() { return _isOpen; }
};

