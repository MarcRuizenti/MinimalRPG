#pragma once
#include "MainManager.h"
#include "MostrarMapa.h"
#include "Move.h"
#include "CombatLogic.h"
#include "H&SBar.h"

void Dungeon(MainManager* mm);
void Combat(MainManager* mm);
void Chest(MainManager* mm);
void GameOver(MainManager* mm);
vector<vector<char>> CreateMap(MainManager* mm, int sizeX, int sizeY);
