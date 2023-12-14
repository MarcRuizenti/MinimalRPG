#include "Functions.h"

int main() {
	
	MainManager* mm = new MainManager;

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
}