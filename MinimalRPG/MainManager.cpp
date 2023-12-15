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

	PositionChest();
	
	//Enemies
	enemies.resize(rand() % 5 + 3);
	for (int i = 0; i < enemies.size(); i++) {
		Enemy* temp = new Enemy;
		temp->Initialize();
		enemies[i] = temp;
	}

	MoveEnemy();
	
	
}

void MainManager::MoveEnemy() {
	for (int i = 0; i < enemies.size(); i++) {
		for (int j = 0; j < enemies.size(); j++) {
			if (i != j) {
				if (enemies[i]->position.X == enemies[j]->position.X && enemies[i]->position.Y == enemies[j]->position.Y) {
					enemies[i]->position.X = rand() % 5;
					enemies[i]->position.Y = rand() % 5;
				}
				if (enemies[i]->position.X == p->position.X && enemies[i]->position.Y == p->position.Y) {
					enemies[i]->position.X = rand() % 5;
					enemies[i]->position.Y = rand() % 5;
				}
				for (int k = 0; k < c.size(); k++) {
					if (enemies[i]->position.X == c[k]->position.X && enemies[i]->position.Y == c[k]->position.Y) {
						enemies[i]->position.X = rand() % 5;
						enemies[i]->position.Y = rand() % 5;
					}
				}
			}
		}
	}
}

void MainManager::PositionChest() {
	for (int i = 0; i < c.size(); i++) {
		for (int j = 0; j < c.size(); j++) {
			if (i != j) {
				if (c[i]->position.X == c[j]->position.X && c[i]->position.Y == c[j]->position.Y) {
					c[i]->position.X = rand() % 5;
					c[i]->position.Y = rand() % 5;
				}
				if (c[i]->position.X == p->position.X && c[i]->position.Y == p->position.Y) {
					c[i]->position.X = rand() % 5;
					c[i]->position.Y = rand() % 5;
				}
			}
		}
	}
}