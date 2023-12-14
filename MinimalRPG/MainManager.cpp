#include "MainManager.h"

void MainManager::Initialize() {
	currentScene = DUNGEON;
	gameIsFinish = false;

	//Chest

	//Player
	p = new Player;
	p->Initialize();

	//Enemies
	enemies.resize(rand() % 5 + 3);
	for (int i = 0; i < enemies.size(); i++) {
		Enemy* tmp;
		tmp->Initialize();
		enemies.push_back(tmp);
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
			}
		}
	}
}