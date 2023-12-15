#include "GameFunctions.h"

int main() {
	srand(time(NULL));

	MainManager* mm = new MainManager;
	mm->Initialize();

	do {
		switch (mm->currentScene)
		{
		case DUNGEON:
			Dungeon(mm);
			break;
		case COMBAT:
			Combat(mm);
			break;
		case CHEST:
			Chest(mm);
			break;
		case GAMEOVER:
			GameOver(mm);
			break;
		default:
			break;
		}
	} while (!mm->gameIsFinish);
}