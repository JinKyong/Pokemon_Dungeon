#pragma once
#include "gameNode.h"

enum EFFECTNUMBER
{
	EF_FIREBLAST,
	EF_GUST,
	EF_LIGHTNING,
	EF_ROCKSLIDE
};

class Effect : public gameNode
{
protected :
	RECT _body;
	dImage* _img;
	float _x, _y;
	float _count;
	bool _off;

public :
	Effect() {};
	~Effect() {};

	virtual HRESULT init(float x, float y) = 0;
	virtual void release() = 0;
	virtual void update() = 0;
	virtual void render() = 0;
	
	virtual void controlFrame() = 0;

	bool getOff() { return _off; }
};

