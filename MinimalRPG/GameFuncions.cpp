#include "GameFunctions.h"
#include "MostrarMapa.h"
#include "Move.h"

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

	}
	else {
		cout << "Icorect input" << endl << endl;
	}

	for (int i = 0; i < mm->c.size(); i++) {
		if (mm->p->position.X == mm->c[i]->position.X && mm->p->position.Y == mm->c[i]->position.Y) {
			mm->currentScene = CHEST;
		}
	}

	for (int i = 0; i < mm->enemies.size(); i++) {
		if (mm->p->position.X == mm->enemies[i]->position.X && mm->p->position.Y == mm->enemies[i]->position.Y) {
			mm->currentScene = COMBAT;
		}
	}

	system("pause");
}
void Combat(MainManager* mm) {
	cout << "cOMABAT" << endl;

	system("pause");
	mm->currentScene = DUNGEON;
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

	if (mm->c[chest]->gear->hp < 0) {
		cout << " " << mm->c[chest]->gear->hp << "HP";
	}
	else if (mm->c[chest]->gear->hp > 0){
		cout << " +" << mm->c[chest]->gear->hp << "HP";
	}
	
	if (mm->c[chest]->gear->stamina < 0) {
		cout << " " << mm->c[chest]->gear->stamina << " Stamina";
	}
	else if (mm->c[chest]->gear->stamina > 0) {
		cout << " +" << mm->c[chest]->gear->stamina << " Stamina";
	}

	if (mm->c[chest]->gear->agility < 0) {
		cout << " " << mm->c[chest]->gear->agility << " Agility";
	}
	else if (mm->c[chest]->gear->agility > 0) {
		cout << " +" << mm->c[chest]->gear->agility << " Agility";
	}

	cout << endl;

	
	mm->p->gears.push_back(mm->c[chest]->gear);
	mm->c[chest]->isLooted = true;
	system("pause");
	mm->currentScene = DUNGEON;
}
void GameOver(MainManager* mm) {

}
