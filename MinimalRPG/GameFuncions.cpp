#include "GameFunctions.h"
#include "MostrarMapa.h"
#include "Move.h"
#include "CombatLogic.h"

void Dungeon(MainManager* mm) {
	system("cls");

	int sizeX = 5;
	int sizeY = 5;
	string input;

	cout << "------ DUNGEON ------" << endl << endl;
	
	cout << "E -> Enemy  P -> Player  C -> Chest" << endl << endl;

	if (mm->p->agility == 0) {
		for (int i = 0; i < mm->enemies.size(); i++) {
			mm->enemies[i]->position.X = rand() % 5;
			mm->enemies[i]->position.Y = rand() % 5;
		}
		mm->MoveEnemy();
		mm->p->agility = mm->p->maxAgility;
	}


	cout << "Health: " << mm->p->health << " / " << mm->p->maxHealth << endl;
	cout << "Postions: " << mm->p->potion << " / " << mm->p->maxPotion << endl;
	cout << "Moves: " << mm->p->agility << " / " << mm->p->maxAgility << endl << endl;

	

	MostrarMapa(CreateMap(mm, sizeX, sizeY), sizeX, sizeY);

	cout << "_______________________" << endl << endl;

	cout << "W A S D -> Move" << endl;
	cout << "p -> Postions" << endl << endl;
	

	cout << "Enter your action: ";
	cin >> input;
	cout << endl;

	for (int i = 0; i < input.size(); i++) {
		if (input[i] >= 'a' && input[i] <= 'z') {
			input[i] -= ' ';
		}
	}

	if (input == "W" || input == "A" || input == "S" || input == "D") {
		Move(mm, input, sizeX, sizeY);
		mm->p->agility -= 1;
	}
	else if (input == "P") {
		if (mm->p->potion <= 0) {
			cout << "You haven't potions" << endl;
		}
		else {
			if (mm->p->health >= mm->p->maxHealth){
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
	}
	else {
		cout << "Icorect input" << endl << endl;
	}

	for (int i = 0; i < mm->c.size(); i++) {
		if (mm->p->position.X == mm->c[i]->position.X && mm->p->position.Y == mm->c[i]->position.Y && !mm->c[i]->isLooted) {
			mm->currentScene = CHEST;
		}
	}

	for (int i = 0; i < mm->enemies.size(); i++) {
		if (mm->p->position.X == mm->enemies[i]->position.X && mm->p->position.Y == mm->enemies[i]->position.Y && !mm->enemies[i]->isDead) {
			mm->currentScene = COMBAT;
		}
	}

	bool allDead = true;

	for (int i = 0; i < mm->enemies.size(); i++) {
		if (!mm->enemies[i]->isDead) {
			allDead = false;
		}
	}

	bool allLooted = true;

	for (int i = 0; i < mm->c.size(); i++) {
		if (!mm->c[i]->isLooted) {
			allLooted = false;
		}
	}

	if (allDead && allLooted) {
		mm->currentScene = GAMEOVER;
	}
	system("pause");
}
void Combat(MainManager* mm) {
	
	while (mm->currentScene == COMBAT) {
		system("cls");
		int enemy;
		for (int i = 0; i < mm->enemies.size(); i++) {
			if (mm->p->position.X == mm->enemies[i]->position.X && mm->p->position.Y == mm->enemies[i]->position.Y) {
				enemy = i;
			}
		}

		cout << "------ COMBAT ------" << endl << endl;

		cout << "-- Enemy --" << endl << endl;

		if (mm->enemies[enemy]->health == mm->enemies[enemy]->healthMax) {
			cout << "[==========] ";
		}
		else if (mm->enemies[enemy]->health > (mm->enemies[enemy]->healthMax * 90) / 100) {
			cout << "[========= ] ";
		}
		else if (mm->enemies[enemy]->health > (mm->enemies[enemy]->healthMax * 80) / 100) {
			cout << "[========  ] ";
		}
		else if (mm->enemies[enemy]->health > (mm->enemies[enemy]->healthMax * 70) / 100) {
			cout << "[=======   ] ";
		}
		else if (mm->enemies[enemy]->health > (mm->enemies[enemy]->healthMax * 60) / 100) {
			cout << "[======    ] ";
		}
		else if (mm->enemies[enemy]->health > (mm->enemies[enemy]->healthMax * 50) / 100) {
			cout << "[=====     ] ";
		}
		else if (mm->enemies[enemy]->health > (mm->enemies[enemy]->healthMax * 40) / 100) {
			cout << "[====      ] ";
		}
		else if (mm->enemies[enemy]->health > (mm->enemies[enemy]->healthMax * 30) / 100) {
			cout << "[===       ] ";
		}
		else if (mm->enemies[enemy]->health > (mm->enemies[enemy]->healthMax * 20) / 100) {
			cout << "[==        ] ";
		}
		else if (mm->enemies[enemy]->health > (mm->enemies[enemy]->healthMax * 10) / 100) {
			cout << "[=         ] ";
		}
		else if (mm->enemies[enemy]->health < (mm->enemies[enemy]->healthMax * 10) / 100) {
			cout << "[~         ] ";
		}
		cout << "? HP" << endl;
		
		if (mm->enemies[enemy]->stamina == mm->enemies[enemy]->staminaMax) {
			cout << "[>>>>>>>>>>] ";
		}
		else if (mm->enemies[enemy]->stamina > (mm->enemies[enemy]->staminaMax * 90) / 100) {
			cout << "[>>>>>>>>> ] ";
		}
		else if (mm->enemies[enemy]->stamina > (mm->enemies[enemy]->staminaMax * 80) / 100) {
			cout << "[>>>>>>>>  ] ";
		}
		else if (mm->enemies[enemy]->stamina > (mm->enemies[enemy]->staminaMax * 70) / 100) {
			cout << "[>>>>>>>   ] ";
		}
		else if (mm->enemies[enemy]->stamina > (mm->enemies[enemy]->staminaMax * 60) / 100) {
			cout << "[>>>>>>    ] ";
		}
		else if (mm->enemies[enemy]->stamina > (mm->enemies[enemy]->staminaMax * 50) / 100) {
			cout << "[>>>>>     ] ";
		}
		else if (mm->enemies[enemy]->stamina > (mm->enemies[enemy]->staminaMax * 40) / 100) {
			cout << "[>>>>      ] ";
		}
		else if (mm->enemies[enemy]->stamina > (mm->enemies[enemy]->staminaMax * 30) / 100) {
			cout << "[>>>       ] ";
		}
		else if (mm->enemies[enemy]->stamina > (mm->enemies[enemy]->staminaMax * 20) / 100) {
			cout << "[>>        ] ";
		}
		else if (mm->enemies[enemy]->stamina > (mm->enemies[enemy]->staminaMax * 10) / 100) {
			cout << "[>         ] ";
		}
		else if (mm->enemies[enemy]->stamina < (mm->enemies[enemy]->staminaMax * 10) / 100) {
			cout << "[<         ] ";
		}
		else if (mm->enemies[enemy]->stamina == 0) {
			cout << "[          ] ";
		}
		cout << "? Stamina" << endl << endl;

		cout << "----------------" << endl << endl;

		cout << "-- Player --" << endl << endl;

		if (mm->p->health == mm->p->maxHealth) {
			cout << "[==========] ";
		}
		else if (mm->p->health > (mm->p->maxHealth * 90) / 100) {
			cout << "[========= ] ";
		}
		else if (mm->p->health > (mm->p->maxHealth * 80) / 100) {
			cout << "[========  ] ";
		}
		else if (mm->p->health > (mm->p->maxHealth * 70) / 100) {
			cout << "[=======   ] ";
		}
		else if (mm->p->health > (mm->p->maxHealth * 60) / 100) {
			cout << "[======    ] ";
		}
		else if (mm->p->health > (mm->p->maxHealth * 50) / 100) {
			cout << "[=====     ] ";
		}
		else if (mm->p->health > (mm->p->maxHealth * 40) / 100) {
			cout << "[====      ] ";
		}
		else if (mm->p->health > (mm->p->maxHealth * 30) / 100) {
			cout << "[===       ] ";
		}
		else if (mm->p->health > (mm->p->maxHealth * 20) / 100) {
			cout << "[==        ] ";
		}
		else if (mm->p->health > (mm->p->maxHealth * 10) / 100) {
			cout << "[=         ] ";
		}
		else if (mm->p->health < (mm->p->maxHealth * 10) / 100) {
			cout << "[~         ] ";
		}
		cout << mm->p->health << " / " << mm->p->maxHealth << endl;

		if (mm->p->stamina == mm->p->maxStamina) {
			cout << "[>>>>>>>>>>] ";
		}
		else if (mm->p->stamina > (mm->p->maxStamina * 90) / 100) {
			cout << "[>>>>>>>>> ] ";
		}
		else if (mm->p->stamina > (mm->p->maxStamina * 80) / 100) {
			cout << "[>>>>>>>>  ] ";
		}
		else if (mm->p->stamina > (mm->p->maxStamina * 70) / 100) {
			cout << "[>>>>>>>   ] ";
		}
		else if (mm->p->stamina > (mm->p->maxStamina * 60) / 100) {
			cout << "[>>>>>>    ] ";
		}
		else if (mm->p->stamina > (mm->p->maxStamina * 50) / 100) {
			cout << "[>>>>>     ] ";
		}
		else if (mm->p->stamina > (mm->p->maxStamina * 40) / 100) {
			cout << "[>>>>      ] ";
		}
		else if (mm->p->stamina > (mm->p->maxStamina * 30) / 100) {
			cout << "[>>>       ] ";
		}
		else if (mm->p->stamina > (mm->p->maxStamina * 20) / 100) {
			cout << "[>>        ] ";
		}
		else if (mm->p->stamina > (mm->p->maxStamina * 10) / 100) {
			cout << "[>         ] ";
		}
		else if (mm->p->stamina < (mm->p->maxStamina * 10) / 100) {
			cout << "[<         ] ";
		}
		else if (mm->p->stamina == 0) {
			cout << "[          ] ";
		}
		cout << mm->p->stamina << " / " << mm->p->maxStamina << endl << endl;

		cout << "________________________________________" << endl << endl;
		cout << "A -> Attack" << endl;
		cout << "D -> Defend" << endl;
		cout << "R -> Rest" << endl;
		cout << "P -> Potion" << endl << endl;

		string input;

		cout << "Enter your action: ";
		cin >> input;
		cout << endl;

		for (int i = 0; i < input.size(); i++) {
			if (input[i] >= 'a' && input[i] <= 'z') {
				input[i] -= ' ';
			}
		}

		if (input == "A" || input == "D" || input == "R" || input == "P") {
			CombatLogic(mm, input, enemy);
		}
		else {
			cout << "Icorect input" << endl << endl;
		}

		if (mm->p->health <= 0) {
			mm->currentScene = GAMEOVER;
		}
		else if (mm->enemies[enemy]->health <= 0) {
			mm->currentScene = DUNGEON;
			mm->enemies[enemy]->isDead = true;
		}
		system("pause");
	}
	
}
void Chest(MainManager* mm) {
	system("cls");
	
	int chest;
	for (int i = 0; i < mm->c.size(); i++) {
		if (mm->p->position.X == mm->c[i]->position.X && mm->p->position.Y == mm->c[i]->position.Y) {
			chest = i;
		}
	}

	cout << "------ CHEST ------" << endl << endl;

	cout << " > You open the chest and it contains the following: " << endl << endl;

	int gold = rand() % 151 + 50;

	cout << "        > " << gold << "gold!" << endl;
	cout << "        > The Chest contains Gear!" << endl;
	cout << "                > " << mm->c[chest]->gear->name;

	vector<int> stats;
	stats.push_back(mm->c[chest]->gear->hp);
	stats.push_back(mm->c[chest]->gear->stamina);
	stats.push_back(mm->c[chest]->gear->agility);

	vector<string> nameStats;
	nameStats.push_back("HP");
	nameStats.push_back(" Stamina");
	nameStats.push_back(" Agility");

	for (int i = 0; i < stats.size(); i++) {
		if (stats[i] < 0) {
			cout << " " << stats[i] << nameStats[i];
		}
		else if (stats[i] > 0) {
			cout << " +" << stats[i] << nameStats[i];
		}
	}

	cout << endl << endl;

	if (mm->c[chest]->potion) {
		cout << "        > The Chest contains a potion!" << endl;
		if (mm->p->potion == mm->p->maxPotion)
			cout << "                > You alredy have max potions!" << endl << endl;
		else
			mm->p->potion += 1;
	}

	mm->p->health += mm->c[chest]->gear->hp;
	mm->p->maxHealth += mm->c[chest]->gear->hp;

	mm->p->stamina += mm->c[chest]->gear->stamina;
	mm->p->maxStamina += mm->c[chest]->gear->stamina;

	mm->p->agility += mm->c[chest]->gear->agility;
	mm->p->maxAgility += mm->c[chest]->gear->agility;

	mm->p->gears.push_back(mm->c[chest]->gear);
	mm->c[chest]->isLooted = true;

	system("pause");
	mm->currentScene = DUNGEON;
}
void GameOver(MainManager* mm) {
	system("cls");
	cout << "Game Over" << endl;
	system("pause");
}
