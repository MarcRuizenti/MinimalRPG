#include "EnemyLogic.h"


char SelectAtackEnemy(MainManager* mm, int enemy) {
	char temp;

	if (mm->enemies[enemy]->health < (mm->enemies[enemy]->healthMax * 30) / 100 && mm->enemies[enemy]->stamina < (mm->enemies[enemy]->staminaMax * 30) / 100) {
		temp = 'D';
	}
	else if (mm->enemies[enemy]->stamina < (mm->enemies[enemy]->staminaMax * 20) / 100){
		temp = 'R';
	}
	else {
		temp = 'A';
	}

	return temp;
}