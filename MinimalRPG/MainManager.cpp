#include "MainManager.h"

void MainManager::Initialize() {
	currentScene = DUNGEON;
	gameIsFinish = false;

	//Player
	p = new Player;
	p->Initialize();

	//Chest
	c.resize(2);
	for (int i = 0; i < c.size(); i++) {
		Chests* temp = new Chests;
		temp->Initialize();
		c[i] = temp;
	}

	int cambios;
	do {
		cambios = 0;
		if (c[0]->gear == c[1]->gear) {
			c[0]->gear->Initialize();
			cambios++;
		}
	} while (cambios != 0);
	PositionChest();
	
	//Enemies
	int rando = rand() % 3 + 5;
	enemies.resize(rando);
	for (int i = 0; i < enemies.size(); i++) {
		Enemy* temp = new Enemy;
		temp->Initialize();
		enemies[i] = temp;
	}
	cout << rando << endl << endl;
	MoveEnemy();
	
	
}

void MainManager::MoveEnemy() {
	int cambio = 0;
	do {
		cambio = 0;
		for (int i = 0; i < enemies.size(); i++) {
			for (int j = 0; j < enemies.size(); j++) {
				if (i != j) {
					if (enemies[i]->position.X == enemies[j]->position.X && enemies[i]->position.Y == enemies[j]->position.Y) {
						enemies[i]->position.X = rand() % 5;
						enemies[i]->position.Y = rand() % 5;
						cambio++;
					}
					if (enemies[i]->position.X == p->position.X && enemies[i]->position.Y == p->position.Y) {
						enemies[i]->position.X = rand() % 5;
						enemies[i]->position.Y = rand() % 5;
						cambio++;
					}
					for (int k = 0; k < c.size(); k++) {
						if (enemies[i]->position.X == c[k]->position.X && enemies[i]->position.Y == c[k]->position.Y) {
							enemies[i]->position.X = rand() % 5;
							enemies[i]->position.Y = rand() % 5;
							cambio++;
						}
					}
				}
			}
		}
	} while (cambio != 0);
}

void MainManager::PositionChest() {
	int cambio = 0;
	do {
		cambio = 0;
		for (int i = 0; i < c.size(); i++) {
			for (int j = 0; j < c.size(); j++) {
				if (i != j) {
					if (c[i]->position.X == c[j]->position.X && c[i]->position.Y == c[j]->position.Y) {
						c[i]->position.X = rand() % 5;
						c[i]->position.Y = rand() % 5;
						cambio++;
					}
					if (c[i]->position.X == p->position.X && c[i]->position.Y == p->position.Y) {
						c[i]->position.X = rand() % 5;
						c[i]->position.Y = rand() % 5;
						cambio++;
					}
				}
			}
		}
	} while (cambio != 0);
	{

	}
}
