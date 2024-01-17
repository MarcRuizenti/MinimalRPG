#pragma once
#include "Player.h"
#include "Enemy.h"
#include "Chest.h"

enum Scene { DUNGEON, COMBAT, CHEST, GAMEOVER };

struct MainManager
{
	Scene currentScene;
	bool gameIsFinish;

	Player* p;

	vector<Chests*> c;
	Chests* currentChest;

	vector<Enemy*> enemies;
	Enemy* currentEnemy;
	

	void Initialize();
	void MoveEnemy();
	void PositionChest();
};
