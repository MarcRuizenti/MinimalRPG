#include "Gear.h"


void Gear::Initialize() {

	gears randomGear = (gears)(rand() % 4);


	switch (randomGear)
	{
	case RICHARDSBLESSING:
		name = "Richard’s blessing";
		goldValue = 200;
		hp = 20;
		haveHp = true;

		stamina = 40;
		haveStamina = true;

		agility = 1;
		haveAgility = true;

		break;
	case SHOESPOCHAS:
		name = "Shoes pochas";
		goldValue = 10;
		hp = -10;
		haveHp = true;

		stamina = -5;
		haveStamina = true;

		agility = 1;
		haveAgility = true;
		break;
	case BERSERKPOWDER:
		name = "Berserk Powder";
		goldValue = 150;
		hp = -20;
		haveHp = true;

		stamina = 20;
		haveStamina = true;

		agility = 1;
		haveAgility = true;
		break;
	case RICHARDCURSE:
		name = "Richard's curse";
		goldValue = -300;
		hp = -20;
		haveHp = true;

		stamina = -40;
		haveStamina = true;

		agility = -1;
		haveAgility = true;
		break;
	default:
		break;
	}
}