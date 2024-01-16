#include "Enemy.h"

void Enemy::Initialize() {

	position.X = rand() % 5;
	position.Y = rand() % 5;

	isDead = false;

	healthMax = 60 + rand() % (91 - 60);
	health = healthMax;

	staminaMax = 60 + rand() % (91 - 60);
	stamina = staminaMax;

}