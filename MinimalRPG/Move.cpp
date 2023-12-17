#include "MainManager.h"

void Move(MainManager* mm, string input, int sizeX, int sizeY) {
	if (input == "W") {
		if (mm->p->position.Y - 1 < 0) {
			cout << "Te salres del mapa" << endl;
			return;
		}
		else {
			mm->p->position.Y -= 1;
		}
	}
	else if (input == "A") {
		if (mm->p->position.X - 1 < 0) {
			cout << "Te salres del mapa" << endl;
		}
		else{
			mm->p->position.X -= 1;
		}
	}
	else if (input == "S"){
		if (mm->p->position.Y + 1 > sizeY) {
			cout << "Te salres del mapa" << endl;
		}
		else {
			mm->p->position.Y += 1;
		}
	}
	else if (input == "D") {
		if (mm->p->position.X + 1 > sizeX) {
			cout << "Te salres del mapa" << endl;

		}
		else {
			mm->p->position.X += 1;
		}
	}
}