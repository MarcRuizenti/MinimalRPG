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
	vector<Chest*> c;
	vector<Enemy*> enemies;
	

	void Initialize();
	void MoveEnemy();
	void ChestPosition();
};
