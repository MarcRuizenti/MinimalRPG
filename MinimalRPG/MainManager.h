#pragma once
#include "Player.h"
#include "Enemy.h"

enum Scene { DUNGEON, COMBAT, CHEST, GAMEOVER };

struct MainManager
{
	Scene currentScene;
	bool gameIsFinish;

	Player* p;
	vector<Enemy*> enemies;
	

	void Initialize();
	void MoveEnemies();
};
