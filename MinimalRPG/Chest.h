#pragma once
#include "MapPosition.h"
#include "Gear.h"

struct Chests
{
	MapPosition position;
	int gold;
	Gear* gear;
	bool potion;
	bool isLooted;

	void Initialize();
};
