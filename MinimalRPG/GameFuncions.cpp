#include "GameFunctions.h"
#include "MostrarMapa.h"
#include "Move.h"
#include "CombatLogic.h"
#include "H&SBar.h"

void Dungeon(MainManager* mm) {
	system("cls");

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
		return;
	}

	int sizeX = 5;
	int sizeY = 5;
	string input;

	cout << "------ DUNGEON ------" << endl << endl;
	
	cout << "E -> Enemy  P -> Player  C -> Chest" << endl << endl;

	if (mm->p->agility <= 0) {
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

		ProgressBarHealth(mm->enemies[enemy]->health, mm->enemies[enemy]->healthMax);
		cout << "? HP" << endl;
		
		ProgressBarStamina(mm->enemies[enemy]->stamina, mm->enemies[enemy]->staminaMax);
		cout << "? Stamina" << endl << endl;

		cout << "----------------" << endl << endl;

		cout << "-- Player --" << endl << endl;
		
		ProgressBarHealth(mm->p->health, mm->p->maxHealth);
		cout << mm->p->health << " / " << mm->p->maxHealth << endl;

		ProgressBarStamina(mm->p->stamina, mm->p->maxStamina);
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

	cout << "        > " << gold << " gold!" << endl;
	cout << "        > The Chest contains Gear!" << endl;
	cout << "                > " << mm->c[chest]->gear->name;

	vector<int> stats;
	if (mm->c[chest]->gear->haveHp)
		stats.push_back(mm->c[chest]->gear->hp);
	if (mm->c[chest]->gear->haveStamina)
		stats.push_back(mm->c[chest]->gear->stamina);
	if (mm->c[chest]->gear->haveAgility)
		stats.push_back(mm->c[chest]->gear->agility);

	vector<string> nameStats;
	if (mm->c[chest]->gear->haveHp)
		nameStats.push_back("HP");
	if (mm->c[chest]->gear->haveStamina)
		nameStats.push_back(" Stamina");
	if (mm->c[chest]->gear->haveAgility)
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
		if (mm->p->potion == mm->p->maxPotion) {
			cout << "                > You alredy have max potions!" << endl << endl;

		}
		else
			mm->p->potion += 1;
	}

	mm->p->gold += gold;
	mm->p->gold += mm->c[chest]->gear->goldValue;

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
	if (mm->p->health <= 0) {
		cout << R"( .----------------.    .----------------.    .----------------.    .----------------.       
| .--------------. |  | .--------------. |  | .--------------. |  | .--------------. |      
| |    ______    | |  | |      __      | |  | | ____    ____ | |  | |  _________   | |      
| |  .' ___  |   | |  | |     /  \     | |  | ||_   \  /   _|| |  | | |_   ___  |  | |      
| | / .'   \_|   | |  | |    / /\ \    | |  | |  |   \/   |  | |  | |   | |_  \_|  | |      
| | | |    ____  | |  | |   / ____ \   | |  | |  | |\  /| |  | |  | |   |  _|  _   | |      
| | \ `.___]  _| | |  | | _/ /    \ \_ | |  | | _| |_\/_| |_ | |  | |  _| |___/ |  | |      
| |  `._____.'   | |  | ||____|  |____|| |  | ||_____||_____|| |  | | |_________|  | |      
| |              | |  | |              | |  | |              | |  | |              | |      
| '--------------' |  | '--------------' |  | '--------------' |  | '--------------' |      
 '----------------'    '----------------'    '----------------'    '----------------'       
 .----------------.    .----------------.    .----------------.    .----------------.       
| .--------------. |  | .--------------. |  | .--------------. |  | .--------------. |      
| |     ____     | |  | | ____   ____  | |  | |  _________   | |  | |  _______     | |      
| |   .'    `.   | |  | ||_  _| |_  _| | |  | | |_   ___  |  | |  | | |_   __ \    | |      
| |  /  .--.  \  | |  | |  \ \   / /   | |  | |   | |_  \_|  | |  | |   | |__) |   | |      
| |  | |    | |  | |  | |   \ \ / /    | |  | |   |  _|  _   | |  | |   |  __ /    | |      
| |  \  `--'  /  | |  | |    \ ' /     | |  | |  _| |___/ |  | |  | |  _| |  \ \_  | |      
| |   `.____.'   | |  | |     \_/      | |  | | |_________|  | |  | | |____| |___| | |      
| |              | |  | |              | |  | |              | |  | |              | |      
| '--------------' |  | '--------------' |  | '--------------' |  | '--------------' |      
 '----------------'    '----------------'    '----------------'    '----------------'  )" << endl;
		
		cout << "*Insert Mario scream when dies* " << endl << endl;
		
		cout << "YOU LOSE :(, the MEM run it's too much for you... Your final score is " << mm->p->gold << endl;

		system("pause");
	}
	else {
		cout << R"( .----------------.    .----------------.    .----------------. 
| .--------------. |  | .--------------. |  | .--------------. |
| |  ____  ____  | |  | |     ____     | |  | | _____  _____ | |
| | |_  _||_  _| | |  | |   .'    `.   | |  | ||_   _||_   _|| |
| |   \ \  / /   | |  | |  /  .--.  \  | |  | |  | |    | |  | |
| |    \ \/ /    | |  | |  | |    | |  | |  | |  | '    ' |  | |
| |    _|  |_    | |  | |  \  `--'  /  | |  | |   \ `--' /   | |
| |   |______|   | |  | |   `.____.'   | |  | |    `.__.'    | |
| |              | |  | |              | |  | |              | |
| '--------------' |  | '--------------' |  | '--------------' |
 '----------------'    '----------------'    '----------------' 
 .----------------.    .----------------.    .-----------------.
| .--------------. |  | .--------------. |  | .--------------. |
| | _____  _____ | |  | |     _____    | |  | | ____  _____  | |
| ||_   _||_   _|| |  | |    |_   _|   | |  | ||_   \|_   _| | |
| |  | | /\ | |  | |  | |      | |     | |  | |  |   \ | |   | |
| |  | |/  \| |  | |  | |      | |     | |  | |  | |\ \| |   | |
| |  |   /\   |  | |  | |     _| |_    | |  | | _| |_\   |_  | |
| |  |__/  \__|  | |  | |    |_____|   | |  | ||_____|\____| | |
| |              | |  | |              | |  | |              | |
| '--------------' |  | '--------------' |  | '--------------' |
 '----------------'    '----------------'    '----------------' )" << endl;

		cout << "*Insert epic music of Final Fantasy* " << endl << endl;

		cout << "CONGRATULATIONS, you complete the MEM run. Your final score is " << mm->p->gold << endl;

		system("pause");
	}
	
}
