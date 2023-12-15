#include "GameFunctions.h"
#include "MostrarMapa.h"

void Dungeon(MainManager* mm) {
	

	int sixeX = 5;
	int sixeY = 5;
	MostrarMapa(CreateMap(mm, sixeX, sixeY), sixeX, sixeY);

	system("pause");
}
void Combat(MainManager* mm) {

}
void Chest(MainManager* mm) {

}
void GameOver(MainManager* mm) {

}
