#include "CreateMap.h"

vector<vector<char>> CreateMap(MainManager* mm, int sizeX, int sizeY) {
	vector<vector<char>> temp;
	temp.resize(sizeY, vector<char>(sizeX));

	for (int i = 0; i < temp.size(); i++) {
		for (int j = 0; j < temp.size(); j++) {
			temp[i][j] = ' ';
		}
	}

	temp[mm->p->position.Y][mm->p->position.X] = 'P';

	for (int i = 0; i < mm->c.size(); i++) {
		if (!mm->c[i]->isLooted) 
			temp[mm->c[i]->position.Y][mm->c[i]->position.X] = 'C';
		
	}
			
	for (int i = 0; i < mm->enemies.size(); i++) {
		if (!mm->enemies[i]->isDead)
			temp[mm->enemies[i]->position.Y][mm->enemies[i]->position.X] = 'E';

	}
	
	return temp;
}