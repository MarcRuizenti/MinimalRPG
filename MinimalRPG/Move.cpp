#include "MainManager.h"

void Move(MainManager* mm, string input, int sizeX, int sizeY) {
	if (input == "W") {
		if (mm->p->position.X - 1 < 0) {
			cout << "Te salres del mapa" << endl;
			return;
		}
		else {
			mm->p->position.X -= 1;
		}
	}
	else if (input == "A") {

	}
	else if (input == "S"){

	}
	else if (input == "D") {

	}
}