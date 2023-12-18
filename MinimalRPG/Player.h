#pragma once
#include "MapPosition.h"
#include "Gear.h"

struct Player
{
	MapPosition position;
	int gold;

	int health;
	int maxHealth;

	int stamina;
	int maxStamina;

	int agility;
	int maxAgility;

	int potion;
	int maxPotion;

	vector<Gear*> gears;

	void Initialize();
};