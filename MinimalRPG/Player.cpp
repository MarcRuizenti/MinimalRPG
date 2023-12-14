#include "Player.h"

void Player::Initialize() {
	position.X = 3;
	position.Y = 2;

	gold = 0;

	maxHealth = rand() % 90 + 21;
	health = maxHealth;

	maxStamina = 200 - maxHealth;
	stamina = maxStamina;

	maxAgility = 3;
	agility = maxAgility;

	maxPotion = 3; 
	potion = maxPotion;
}