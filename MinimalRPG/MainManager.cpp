#include "MainManager.h"

void MainManager::Initialize() {
	currentScene = DUNGEON;
	gameIsFinish = false;

	//Player
	p = new Player;
	p->Initialize();

	//Enemies
	MoveEnemies();

	//Chest
}