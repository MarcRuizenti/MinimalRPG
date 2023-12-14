#pragma once
#include "MapPosition.h"

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

	void Initialize();
};