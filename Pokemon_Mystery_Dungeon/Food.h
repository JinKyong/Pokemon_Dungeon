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
	FOODTYPE _concType; //음식타입 (item의 type과 헷갈리지 않게 작명)

	//??? _gummyType;	//구미별 속성을 공통enum에서 불러오고 싶은데 이부분 보류할게여

public:
	Food() {};
	~Food() {};

	virtual HRESULT init(float x, float y);
	virtual void release() = 0;
	virtual void update() = 0;
	virtual void render(float x, float y) = 0;


	//아이템 사용
	virtual void eatItem();

	virtual void throwItem(float x, float y, float angle) = 0;

	virtual void itemMove(float x, float y, float angle) = 0;
};