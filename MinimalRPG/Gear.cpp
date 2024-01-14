#include "Gear.h"


void Gear::Initialize() {

	gears randomGear = (gears)(rand() % 4);


	switch (randomGear)
	{
	case RICHARDSBLESSING:
		name = "Richard’s blessing";
		goldValue = 200;
		hp = 20;
		stamina = 40;
		agility = 1;
		break;
	case SHOESPOCHAS:
		name = "Shoes pochas";
		goldValue = 10;
		hp = -10;
		stamina = -5;
		agility = 1;
		break;
	case BERSERKPOWDER:
		name = "Berserk Powder";
		goldValue = 150;
		hp = -20;
		stamina = 20;
		agility = 1;
		break;
	case RICHARDCURSE:
		name = "Richard's curse";
		goldValue = -300;
		hp = -20;
		stamina = -40;
		agility = -1;
		break;
	default:
		break;
	}
}