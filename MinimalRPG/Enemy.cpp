#include "Enemy.h"

void Enemy::Initialize() {

	position.X = rand() % 5;
	position.Y = rand() % 5;

	isDead = false;

	healthMax = rand() % 60 + 31;
	health = healthMax;

	staminaMax = rand() % 60 + 31;
	stamina = staminaMax;

}