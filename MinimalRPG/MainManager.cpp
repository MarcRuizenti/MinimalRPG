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

	}
	MoveEnemies();
	
	//Chest
}