#pragma once
#include "Pokemon.h"

class Jolteon : public Pokemon
{

public:
	Jolteon();
	~Jolteon();

	HRESULT init();
	void release();
};

