#include "CombatLogic.h"
#include "EnemyLogic.h"

void CombatLogic(MainManager* mm, string input, int enemy) {
	char enemyatack = SelectAtackEnemy(mm, enemy);
	int enemyAttackStamina = (mm->enemies[enemy]->stamina * 20) / 100 + rand() + mm->enemies[enemy]->stamina - ((mm->enemies[enemy]->stamina * 20) / 100) + 1;
	
	if (input == "A") {
		bool valid = false;
		int attackPlayerStamina;

		do {
			cout << "Eneter the attack value " << "(Max " << mm->p->stamina << "): ";
			cin >> attackPlayerStamina;
			cout << endl;

			valid = mm->p->stamina > attackPlayerStamina && attackPlayerStamina >= 0;

			if (!valid) {
				cout << "The number is incorrect, try again" << endl << endl;
			}

		} while (!valid);

		if (enemyatack == 'A') {
			if (enemyAttackStamina < attackPlayerStamina) {
				mm->enemies[enemy]->health -= attackPlayerStamina;
				mm->enemies[enemy]->stamina -= enemyAttackStamina;
				mm->p->stamina -= attackPlayerStamina;
			}
			else {
				mm->enemies[enemy]->stamina -= enemyAttackStamina;
				mm->p->health -= enemyAttackStamina;
				mm->p->stamina -= attackPlayerStamina;
			}
		}
		else if (enemyatack == 'R') {
			mm->p->stamina -= attackPlayerStamina;
			mm->enemies[enemy]->health == mm->enemies[enemy]->healthMax;
			mm->enemies[enemy]->health -= attackPlayerStamina;

		}
		else if (enemyatack == 'D') {
			mm->enemies[enemy]->health -= attackPlayerStamina - ((attackPlayerStamina * 75) / 100);
			mm->enemies[enemy]->stamina += (mm->enemies[enemy]->staminaMax * 25) / 100;
			mm->p->stamina -= attackPlayerStamina;
		}
	}
	else if (input == "D") {

		if (enemyatack == 'A') {
			mm->enemies[enemy]->stamina -= enemyAttackStamina;
			mm->p->health -= enemyAttackStamina - ((enemyAttackStamina * 75) / 100);
			mm->p->health += (mm->p->maxStamina * 25) / 100;
		}
		else if (enemyatack == 'R') {
			mm->enemies[enemy]->health == mm->enemies[enemy]->healthMax;
			mm->p->stamina += (mm->p->maxStamina * 25) / 100;
		}
		else if (enemyatack == 'D') {
			mm->enemies[enemy]->stamina += (mm->enemies[enemy]->staminaMax * 25) / 100;
			mm->p->stamina += (mm->p->maxStamina * 25) / 100;
		}
	}
	else if (input == "R") {

		if (enemyatack == 'A') {
			mm->enemies[enemy]->stamina -= enemyAttackStamina;
			mm->p->health -= enemyAttackStamina;
			mm->p->health == mm->p->maxHealth;
		}
		else if (enemyatack == 'R') {
			mm->enemies[enemy]->health == mm->enemies[enemy]->healthMax;
			mm->p->health == mm->p->maxHealth;
		}
		else if (enemyatack == 'D') {
			mm->enemies[enemy]->stamina += (mm->enemies[enemy]->staminaMax * 25) / 100;
			mm->p->health == mm->p->maxHealth;
		}
	}
}