#include "Player.h"

void Player::Initialize() {
	position.X = 2;
	position.Y = 3;

	gold = 0;

	maxHealth = rand() % 21 + 90;
	health = maxHealth;

	maxStamina = 200 - maxHealth;
	stamina = maxStamina;

	maxAgility = 3;
	agility = maxAgility;

	maxPotion = 3; 
	potion = maxPotion;
}