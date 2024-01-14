#pragma once
#include "MapPosition.h"

enum gears {RICHARDSBLESSING, SHOESPOCHAS, BERSERKPOWDER, RICHARDCURSE};

struct Gear
{
	string name;
	int goldValue;
	int hp;
	int stamina;
	int agility;

	void Initialize();

};
