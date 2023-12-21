#include "EnemyLogic.h"


char SelectAtackEnemy(MainManager* mm, int enemy) {
	char temp;

	if (mm->enemies[enemy]->health < (mm->enemies[enemy]->health * 30) / 100 && mm->enemies[enemy]->stamina < (mm->enemies[enemy]->stamina * 30) / 100) {
		temp = 'D';
	}
	else if (mm->enemies[enemy]->stamina < (mm->enemies[enemy]->stamina * 20) / 100){
		temp = 'R';
	}
	else {
		temp = 'A';
	}

	return temp;
}