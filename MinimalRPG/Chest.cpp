#include "Chest.h"

void Chests::Initialize() {

	position.X = rand() % 5;
	position.Y = rand() % 5;

	gold = rand() % 50 + 151;

	gear->Initialize();
	
	int probabilityPotion = rand() % 4 + 1;
	if (probabilityPotion == 4) {
		potion = true;
	}
	else {
		potion = false;
	}

	isLooted = false;

}