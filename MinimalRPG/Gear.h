#pragma once
#include "MapPosition.h"

enum gears {RICHARDHATRED, SWIFTBOOTS, WHITEPOWDER, RADEVMUG};

struct Gear
{
	//string name;
	int goldValue;
	int hp;
	int stamina;
	int agility;

	void Initialize();

};
