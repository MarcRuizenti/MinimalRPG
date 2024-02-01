#include "CombatLogic.h"


void CombatLogic(MainManager* mm, string input) {
	char enemyatack = SelectAtackEnemy(mm);

	int minimDamage = (mm->currentEnemy->stamina * 20) / 100;
	int maxDamage = mm->currentEnemy->stamina;

	int enemyAttackStamina = minimDamage + rand() % ((maxDamage + 1) - minimDamage);
	
	if (input == "A") {
		bool valid = false;
		int attackPlayerStamina;

		do {
			cout << "Eneter the attack value " << "(Max " << mm->p->stamina << "): ";
			cin >> attackPlayerStamina;
			cout << endl;

			valid = mm->p->stamina >= attackPlayerStamina && attackPlayerStamina >= 0;

			if (!valid) {
				cout << "The number is incorrect, try again" << endl << endl;
			}

		} while (!valid);

		if (enemyatack == 'A') {
			if (enemyAttackStamina < attackPlayerStamina) {
				mm->currentEnemy->health -= attackPlayerStamina;
				mm->currentEnemy->stamina -= enemyAttackStamina;
				mm->p->stamina -= attackPlayerStamina;
				cout << "You strike with more force! the enemy receives " << attackPlayerStamina << " damage" << endl;
			}
			else {
				mm->currentEnemy->stamina -= enemyAttackStamina;
				mm->p->health -= enemyAttackStamina;
				mm->p->stamina -= attackPlayerStamina;
				cout << "The enemy strikes with more force! you receive " << enemyAttackStamina << " damage" << endl;
			}
		}
		else if (enemyatack == 'R') {
			mm->p->stamina -= attackPlayerStamina;
			mm->currentEnemy->stamina = mm->currentEnemy->staminaMax;
			mm->currentEnemy->health -= attackPlayerStamina;
			cout << "You attacked the enemy while he was resting, nice predict " << attackPlayerStamina << " damage" << endl;
		}
		else if (enemyatack == 'D') {
			mm->currentEnemy->health -= attackPlayerStamina - ((attackPlayerStamina * 75) / 100);
			if (mm->currentEnemy->stamina + (mm->currentEnemy->stamina * 25) / 100 > mm->currentEnemy->staminaMax) {
				mm->currentEnemy->stamina += mm->currentEnemy->staminaMax - mm->currentEnemy->stamina;
			}
			else {
				mm->currentEnemy->stamina += (mm->currentEnemy->staminaMax * 25) / 100;
			}
			cout << "You strike the enemy but he has defended himself, the enemy receive " << attackPlayerStamina - ((attackPlayerStamina * 75) / 100) << " damage" << endl;
			mm->p->stamina -= attackPlayerStamina;
			
		}
	}
	else if (input == "D") {

		if (enemyatack == 'A') {
			mm->currentEnemy->stamina -= enemyAttackStamina;
			mm->p->health -= enemyAttackStamina - ((enemyAttackStamina * 75) / 100);
			if (mm->p->stamina + (mm->p->maxStamina * 25) / 100 > mm->p->maxStamina) {
				mm->p->stamina += mm->p->maxStamina - mm->p->stamina;
			}
			else {
				mm->p->stamina += (mm->p->maxStamina * 25) / 100;
			}
			cout << "You defend the enemy blow, but receive " << enemyAttackStamina - ((enemyAttackStamina * 75) / 100) << " damage" << endl;
		}
		else if (enemyatack == 'R') {
			mm->currentEnemy->stamina = mm->currentEnemy->staminaMax;
			if (mm->p->stamina + (mm->p->maxStamina * 25) / 100 > mm->p->maxStamina) {
				mm->p->stamina += mm->p->maxStamina - mm->p->stamina;
			}
			else {
				mm->p->stamina += (mm->p->maxStamina * 25) / 100;
			}
			cout << "You defended yourself when the enemy was resting, he read your mind :( " << endl;
		}
		else if (enemyatack == 'D') {
			if (mm->currentEnemy->stamina + (mm->currentEnemy->stamina * 25) / 100 > mm->currentEnemy->staminaMax) {
				mm->currentEnemy->stamina += mm->currentEnemy->staminaMax - mm->currentEnemy->stamina;
			}
			else {
				mm->currentEnemy->stamina += (mm->currentEnemy->staminaMax * 25) / 100;
			}
			if (mm->p->stamina + (mm->p->maxStamina * 25) / 100 > mm->p->maxStamina) {
				mm->p->stamina += mm->p->maxStamina - mm->p->stamina;
			}
			else {
				mm->p->stamina += (mm->p->maxStamina * 25) / 100;
			}
			cout << "You both defend... EPIC METAPOD FIGHT " << endl;
		}
	}
	else if (input == "R") {

		if (enemyatack == 'A') {
			mm->currentEnemy->stamina -= enemyAttackStamina;
			mm->p->health -= enemyAttackStamina;
			mm->p->stamina = mm->p->maxStamina;
			cout << "You rest when the enemy hits you, striking for " << enemyAttackStamina << " damage" << endl;
		}
		else if (enemyatack == 'R') {
			mm->currentEnemy->stamina = mm->currentEnemy->staminaMax;
			mm->p->stamina = mm->p->maxStamina;
			cout << "You both rest, this is going to take a while... " << endl;
		}
		else if (enemyatack == 'D') {
			if (mm->currentEnemy->stamina + (mm->currentEnemy->stamina * 25) / 100 > mm->currentEnemy->staminaMax) {
				mm->currentEnemy->stamina += mm->currentEnemy->staminaMax - mm->currentEnemy->stamina;
			}
			else {
				mm->currentEnemy->stamina += (mm->currentEnemy->staminaMax * 25) / 100;
			}
			mm->p->stamina = mm->p->maxStamina;
			cout << "You rest when the enemy defend, 300 IQ play! " << endl;
		}
	}
	else if (input == "P") {
		if (enemyatack == 'A') {
			mm->currentEnemy->stamina -= enemyAttackStamina;
			mm->p->health -= enemyAttackStamina;
			
			if (mm->p->potion <= 0) {
				cout << "You haven't potions" << endl;
			}
			else {
				if (mm->p->health >= mm->p->maxHealth) {
					cout << "You have a max health" << endl << endl;
					mm->p->potion--;
				}
				else if (((mm->p->maxHealth * 40) / 100) + mm->p->health > mm->p->maxHealth) {
					mm->p->health += (mm->p->maxHealth - mm->p->health);
					mm->p->potion--;
				}
				else if (((mm->p->maxHealth * 40) / 100) + mm->p->health < mm->p->maxHealth) {
					mm->p->health += ((mm->p->maxHealth * 40) / 100);
					mm->p->potion--;
				}
			}

			cout << "You use potion when the enemy hits you, striking for " << enemyAttackStamina << " damage" << endl;
		}
		else if (enemyatack == 'R') {
			mm->currentEnemy->stamina = mm->currentEnemy->staminaMax;
			
			if (mm->p->potion <= 0) {
				cout << "You haven't potions" << endl;
			}
			else {
				if (mm->p->health >= mm->p->maxHealth) {
					cout << "You have a max health" << endl << endl;
					mm->p->potion--;
				}
				else if (((mm->p->maxHealth * 40) / 100) + mm->p->health > mm->p->maxHealth) {
					mm->p->health += (mm->p->maxHealth - mm->p->health);
					mm->p->potion--;
				}
				else if (((mm->p->maxHealth * 40) / 100) + mm->p->health < mm->p->maxHealth) {
					mm->p->health += ((mm->p->maxHealth * 40) / 100);
					mm->p->potion--;
				}
			}

			cout << "You use potion when the enemy is resting... why haven't you done the same? " << endl;
		}
		else if (enemyatack == 'D') {
			if (mm->currentEnemy->stamina + (mm->currentEnemy->stamina * 25) / 100 > mm->currentEnemy->staminaMax) {
				mm->currentEnemy->stamina += mm->currentEnemy->staminaMax - mm->currentEnemy->stamina;
			}
			else {
				mm->currentEnemy->stamina += (mm->currentEnemy->staminaMax * 25) / 100;
			}

			if (mm->p->potion <= 0) {
				cout << "You haven't potions" << endl;
			}
			else {
				if (mm->p->health >= mm->p->maxHealth) {
					cout << "You have a max health" << endl << endl;
					mm->p->potion--;
				}
				else if (((mm->p->maxHealth * 40) / 100) + mm->p->health > mm->p->maxHealth) {
					mm->p->health += (mm->p->maxHealth - mm->p->health);
					mm->p->potion--;
				}
				else if (((mm->p->maxHealth * 40) / 100) + mm->p->health < mm->p->maxHealth) {
					mm->p->health += ((mm->p->maxHealth * 40) / 100);
					mm->p->potion--;
				}
			}

			cout << "You use a potion when the enemy defend himself, WORTH IT " << endl;
		}
	}
}