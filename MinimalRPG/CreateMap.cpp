#include "CreateMap.h"

vector<vector<char>> CreateMap(MainManager* mm, int sizeX, int sizeY) {
	vector<vector<char>> temp;
	temp.resize(sizeX, vector<char>(sizeY));

	for (int i = 0; i < sizeY; i++) {
		for (int j = 0; j < sizeX; j++) {
			temp[i][j] = ' ';
			if (i == mm->p->position.Y && j == mm->p->position.X) {
				temp[i][j] = 'P';
			}
			for (int k = 0; k < mm->c.size(); k++) {
				if (i == mm->c[k]->position.Y && j == mm->c[k]->position.X) {
					temp[i][j] = 'C';
				}
			}
			for (int k = 0; k < mm->enemies.size(); k++) {
				if (i == mm->enemies[k]->position.Y && j == mm->enemies[k]->position.X && !mm->enemies[k]->isDead) {
					temp[i][j] = 'E';
				}
			}

		}
	}
	return temp;
}