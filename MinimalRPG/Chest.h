#pragma once
#include "MapPosition.h"
#include "Gear.h"

struct Chest
{
	MapPosition position;
	int gold;
	Gear* gear;
	bool potion;
	bool isLooted;

	void Initialize();

};
