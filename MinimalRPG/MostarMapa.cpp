#include "MostrarMapa.h"

void MostrarMapa(vector<vector<char>> map, int sizeX, int sizeY) {
	cout << " ___  ___  ___  ___  ___" << endl;
	for (int i = 0; i < sizeY; i++) {
		cout << "|   ||   ||   ||   ||   |" << endl;
		for (int j = 0; j < sizeX; j++) {
			

			if (j != sizeX - 1) {
				cout << "| " << map[i][j] << " |";
			}
			else {
				cout << "| " << map[i][j] << " |" << endl;
			}
			
		}
		cout << "|___||___||___||___||___|" << endl;
	}
}