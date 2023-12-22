#include "CombatLogic.h"
#include "EnemyLogic.h"

void CombatLogic(MainManager* mm, string input, int enemy) {
	char enemyatack = SelectAtackEnemy(mm, enemy);

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
			int enemyAttackStamina = (mm->enemies[enemy]->stamina * 20) / 100 + rand() + mm->enemies[enemy]->stamina - ((mm->enemies[enemy]->stamina * 20) / 100) + 1;

			if (enemyAttackStamina < attackPlayerStamina) {
				mm->enemies[enemy]->health -= attackPlayerStamina;
				mm->enemies[enemy]->stamina -= enemyAttackStamina;
				mm->p->stamina -= attackPlayerStamina;
			}
		}
		else if (enemyatack == 'R') {
			
		}
		else if (enemyatack == 'D') {

		}
	}
	else if (input == "D") {

	}
	else if (input == "R") {

	}
}