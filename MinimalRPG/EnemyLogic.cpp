#include "EnemyLogic.h"


char SelectAtackEnemy(MainManager* mm) {
	char temp;

	if (mm->currentEnemy->health < (mm->currentEnemy->healthMax * 30) / 100 && mm->currentEnemy->stamina < (mm->currentEnemy->staminaMax * 30) / 100) {
		temp = 'D';
	}
	else if (mm->currentEnemy->stamina < (mm->currentEnemy->staminaMax * 20) / 100){
		temp = 'R';
	}
	else {
		temp = 'A';
	}

	return temp;
}