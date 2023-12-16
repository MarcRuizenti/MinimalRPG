#include "GameFunctions.h"
#include "MostrarMapa.h"

void Dungeon(MainManager* mm) {
	system("cls");

	int sixeX = 5;
	int sixeY = 5;
	string input;

	cout << "------ DUNGEON ------" << endl << endl;
	
	cout << "E -> Enemy  P -> Player  C -> Chest" << endl << endl;

	cout << "Health: " << mm->p->health << " / " << mm->p->maxHealth << endl;
	cout << "Postions: " << mm->p->potion << " / " << mm->p->maxPotion << endl;
	cout << "Moves: " << mm->p->agility << " / " << mm->p->maxAgility << endl << endl;

	MostrarMapa(CreateMap(mm, sixeX, sixeY), sixeX, sixeY);

	cout << "_______________________" << endl << endl;

	cout << "W A S D -> Move" << endl;
	cout << "p -> Postions" << endl << endl;
	

	cout << "Enter your action: ";
	cin >> input;


	if (input == "W" || input == "A" || input == "S" || input == "D") {

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
