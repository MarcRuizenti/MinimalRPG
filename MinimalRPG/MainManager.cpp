#include "MainManager.h"

void MainManager::Initialize() {
	currentScene = DUNGEON;
	gameIsFinish = false;

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
	for (int i = 0; i < enemies.size(); i++ ) {
		for (int j = 0; j < enemies.size(); j++) {

		}
	}
	
	//Chest
}