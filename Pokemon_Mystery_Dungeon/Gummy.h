#pragma once
#include "Item.h"
#include "PokemonType.h"

class Gummy : public Item
{
private:
	int _num;
	POKEMON_TYPE _type;

public:
	Gummy() {};
	~Gummy() {};

	virtual HRESULT init(float x, float y, float angle);
	virtual void release();
	virtual void update();
	virtual void render();

	//������ ���
	void eatItem(float value);
};