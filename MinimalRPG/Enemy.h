#pragma once
#include "Player.h"

struct Enemy
{
	int potitionX;
	int potitionY;
	bool isDead;
	int health;
	int healthMax;
	int stamina;
	int staminaMax;
};