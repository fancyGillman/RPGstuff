#include <iostream>
#include <ctime>
#include "weapon.h"

weapon::weapon()
{
	damage = 0;
	critRate = 0;
	critMultiplier = 0;
	hitRate = 0;
	weaponType = "";
}

weapon::weapon(int num, int critR, int critM, int hitR, string type)
{
	damage = num;
	critRate = critR;
	critMultiplier = critM;
	hitRate = hitR;
	weaponType = type;
}

int weapon::getDamage()
{
	return damage;
}

int weapon::getCritRate()
{
	return critRate;
}

int weapon::getCritMult()
{
	return critMultiplier;
}

int weapon::getHitRate()
{
	return hitRate;
}

string weapon::getWeaponType()
{
	return weaponType;
}

//make sword axe and club