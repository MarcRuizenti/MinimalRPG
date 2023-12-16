#include "GameFunctions.h"
#include "MostrarMapa.h"

void Dungeon(MainManager* mm) {
	system("cls");

	int sixeX = 5;
	int sixeY = 5;


	cout << "------ DUNGEON ------" << endl << endl;
	
	cout << "E -> Enemy  P -> Player  C -> Chest" << endl << endl;

	cout << "Health: " << mm->p->health << " / " << mm->p->maxHealth << endl;
	cout << "Potions: " << mm->p->position << " / " << mm->p->maxPotion << endl;
	cout << "Moves: " << mm->p->agility << " / " << mm->p->maxAgility << endl << endl;

	
	MostrarMapa(CreateMap(mm, sixeX, sixeY), sixeX, sixeY);

	cout << "W A S D -> Move" << endl;
	cout << "p -> Postions" << endl;
	

	system("pause");
}
void Combat(MainManager* mm) {

}
void Chest(MainManager* mm) {

}
void GameOver(MainManager* mm) {

}
