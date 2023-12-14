#include "MainManager.h"

int main() {
	
	MainManager* mm = new MainManager;

	switch (mm->currentScene)
	{
	case DUNGEON:
		break;
	case COMBAT:
		break;
	case CHEST:
		break;
	case GAMEOVER:
		break;
	default:
		break;
	}
}