#pragma once
#include "MainManager.h"

void Dungeon(MainManager* mm);
void Combat(MainManager* mm);
void Chest(MainManager* mm);
void GameOver(MainManager* mm);
vector<vector<char>> CreateMap(MainManager* mm, int sizeX, int sizeY);
