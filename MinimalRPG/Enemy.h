#pragma once
#include "MapPosition.h"

struct Enemy
{
	MapPosition position;
	bool isDead;
	int health;
	int healthMax;
	int stamina;
	int staminaMax;
};