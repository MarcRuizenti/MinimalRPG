#include "Player.h"

void Player::Initialize() {
	position.X = rand() % 5;
	position.Y = rand() % 5;

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