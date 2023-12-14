#pragma once
#include "Player.h"
#include "Enemy.h"

enum Scene { DUNGEON, COMBAT, CHEST, GAMEOVER };

struct MainManager
{
	Scene currentScene;
	Player* p;
	vector<Enemy*> enemies;
};
