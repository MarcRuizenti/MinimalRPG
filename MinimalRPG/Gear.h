#pragma once
#include "MapPosition.h"

enum gears {RICHARDSBLESSING, SHOESPOCHAS, BERSERKPOWDER, RICHARDCURSE};

struct Gear
{
	string name;
	int goldValue;

	int hp;
	bool haveHp;

	int stamina;
	bool haveStamina;

	int agility;
	bool haveAgility;

	void Initialize();

};
