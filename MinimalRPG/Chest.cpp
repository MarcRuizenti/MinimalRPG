#include "Chest.h"

void Chests::Initialize() {

	position.X = rand() % 5;
	position.Y = rand() % 5;

	gold = 50 + rand() % (201 - 50);

	gear = new Gear;
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