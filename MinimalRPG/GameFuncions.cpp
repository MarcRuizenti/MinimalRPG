#include "GameFunctions.h"
#include "MostrarMapa.h"
#include "Move.h"

void Dungeon(MainManager* mm) {
	system("cls");

	int sizeX = 5;
	int sizeY = 5;
	string input;

	cout << "------ DUNGEON ------" << endl << endl;
	
	cout << "E -> Enemy  P -> Player  C -> Chest" << endl << endl;

	cout << "Health: " << mm->p->health << " / " << mm->p->maxHealth << endl;
	cout << "Postions: " << mm->p->potion << " / " << mm->p->maxPotion << endl;
	cout << "Moves: " << mm->p->agility << " / " << mm->p->maxAgility << endl << endl;

	MostrarMapa(CreateMap(mm, sizeX, sizeY), sizeX, sizeY);

	cout << "_______________________" << endl << endl;

	cout << "W A S D -> Move" << endl;
	cout << "p -> Postions" << endl << endl;
	

	cout << "Enter your action: ";
	cin >> input;

	for (int i = 0; i < input.size(); i++) {
		if (input[i] >= 'a' && input[i] <= 'z') {
			input[i] -= ' ';
		}
	}

	if (input == "W" || input == "A" || input == "S" || input == "D") {
		Move(mm, input, sizeX, sizeY);
	}
	else if (input == "P") {

	}
	else {
		cout << "Icorect input" << endl << endl;
	}

	system("pause");
}
void Combat(MainManager* mm) {

}
void Chest(MainManager* mm) {

}
void GameOver(MainManager* mm) {

}
