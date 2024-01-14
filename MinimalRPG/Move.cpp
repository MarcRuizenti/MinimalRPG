#include "MainManager.h"

void Move(MainManager* mm, string input, int sizeX, int sizeY) {
	if (input == "W") {
		if (mm->p->position.Y - 1 < 0) {
			cout << "YOU CAN'T GO THERE, you have to defeat all the enemies :(" << endl;
			return;
		}
		else {
			mm->p->position.Y -= 1;
		}
	}
	else if (input == "A") {
		if (mm->p->position.X - 1 < 0) {
			cout << "YOU CAN'T GO THERE, you have to defeat all the enemies :(" << endl;
		}
		else{
			mm->p->position.X -= 1;
		}
	}
	else if (input == "S"){
		if (mm->p->position.Y + 1 > sizeY - 1) {
			cout << "YOU CAN'T GO THERE, you have to defeat all the enemies :(" << endl;
		}
		else {
			mm->p->position.Y += 1;
		}
	}
	else if (input == "D") {
		if (mm->p->position.X + 1 > sizeX - 1) {
			cout << "YOU CAN'T GO THERE, you have to defeat all the enemies :(" << endl;

		}
		else {
			mm->p->position.X += 1;
		}
	}
}