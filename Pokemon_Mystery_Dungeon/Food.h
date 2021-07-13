#pragma once
#include "Item.h"

#define GUMMY_MAX 17

enum FOODTYPE
{
	APPLE,
	GUMMY,
	//BERRIE,
	//MEDI,
	//SEED,
	ENDFOODTYPE
};

class Food : public Item
{
private:
	FOODTYPE _concType; //����Ÿ�� (item�� type�� �򰥸��� �ʰ� �۸�)

	//??? _gummyType;	//���̺� �Ӽ��� ����enum���� �ҷ����� ������ �̺κ� �����ҰԿ�

public:
	Food() {};
	~Food() {};

	virtual HRESULT init(float x, float y);
	virtual void release() = 0;
	virtual void update() = 0;
	virtual void render(float x, float y) = 0;


	//������ ���
	virtual void eatItem();

	virtual void throwItem(float x, float y, float angle) = 0;

	virtual void itemMove(float x, float y, float angle) = 0;
};