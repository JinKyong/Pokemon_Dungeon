#pragma once
#include "Pokemon.h"

class Flareon : public Pokemon
{
public:
	Flareon();
	~Flareon();

	HRESULT init();
	void release();
};

