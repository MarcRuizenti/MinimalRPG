#include "Gear.h"


void Gear::Initialize() {

	gears randomGear = (gears)(rand() % 4);

	switch (randomGear)
	{
	case RICHARDHATRED:
		name = "Richard’s Hatred";
		goldValue = 200;
		hp = 20;
		stamina = 40;
		agility = 1;
		break;
	case SWIFTBOOTS:
		name = "Swift boots";
		goldValue = 10;
		hp = -10;
		stamina = -5;
		agility = 1;
		break;
	case WHITEPOWDER:
		name = "White Powder";
		goldValue = 150;
		hp = -20;
		stamina = 20;
		agility = 1;
		break;
	case RADEVMUG:
		name = "Radev’s Mug";
		goldValue = -300;
		hp = -20;
		stamina = -40;
		agility = -1;
		break;
	default:
		break;
	}
}