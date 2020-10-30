#include <iostream>
#include <ctime>
#include "player.h"
#include "opp.h"

using namespace std;

player::player()
{
	health = 1000;
	magic = 100;
	potions = 2;
	//damage = 0;

	weapon* equippedWeaponPTR = nullptr; 
	fireMagic* fireMagicPTR = nullptr;
	name = "";
	//enemy* enemyPTR = nullptr;//might not need
}

//this constructor and the string constructor below never get used, ignore these
player::player(weapon* weaponPTR)//, magicT* magicPTR)
{
	health = 1000;
	magic = 100;
	potions = 2;
	equippedWeaponPTR = weaponPTR;
	//equippedMagicPTR - magicPTR;
	name = "";
	//damage = equippedWeaponPTR->getDamage();
}

player::player(string userName)
{
	health = 100;
	magic = 100;
	potions = 2;
	equippedWeaponPTR = nullptr;
	name = userName;
	//damage = 0;
}

player::~player()
{
	delete equippedWeaponPTR;
}

//grab
int player::getHealth()
{
	return health;
}

int player::getMagic()
{
	return magic;
}

int player::getPotions()
{
	return potions;
}

int player::getDamage()
{
	return equippedWeaponPTR->getDamage();
}

string player::getWeaponType()
{
	return equippedWeaponPTR->getWeaponType();
}

string player::getName()
{
	return name;
}

int  player::getCritRate()
{
	return equippedWeaponPTR->getCritRate();
}

int player::getCritMultiply()
{
	return equippedWeaponPTR->getCritMult();
}

string player::getMagicType()
{
	if (!(fireMagicPTR == nullptr))
		return fireMagicPTR->getMagicType();
	else
		return "no magic type";
}

int player::getMagicHitRate()
{
	if (!(fireMagicPTR == nullptr))
	{
		return fireMagicPTR->getHitRate();
	}
}

int player::getMagicDamage()
{
	if (!(fireMagicPTR == nullptr))
		return fireMagicPTR->getDMG();
}

int player::getFireDOTdmg()
{
	return fireMagicPTR->getDOTdmg();
}


//set
void player::dealSelfDamage(int oppDMG)
{
	health = health - oppDMG;
}

/*
void player::setDamage(int wDamage)
{
	damage = wDamage;
}
*/

void player::setEquipWeapon(weapon* wPTR)
{
	equippedWeaponPTR = wPTR;
	//damage = equippedWeaponPTR->getDamage();
}

void player::setMagicEquip(fireMagic* mPTR) //make overloaded functions with different magictype PTRs
{
	fireMagicPTR = mPTR;
}

void player::setName(string userN)
{
	name = userN;
}

void player::setHealth(int num)
{
	health = num;
}

//gameplay

bool player::didItHit(int wHitRate)
{

	srand(time(0));
	int rngHold = rand() % 100; 
	int randNum = rand() % 100;

	//cout << "rngHold: " << rngHold << endl;
	//cout << "randNum: " << randNum << endl;

	if (randNum < wHitRate)
	{
		return true;
	}
	else if (randNum > wHitRate)
	{
		return false;
	}

}

bool player::critCheck(int critRate)
{
	srand(time(0));
	int rngHold = rand() % 100;
	int randNum = rand() % 100;

	if (randNum < critRate)
	{
		return true;
	}
	else if (randNum > critRate)
	{
		return false;
	}

}

bool player::attack()
{
	return didItHit(equippedWeaponPTR->getHitRate());
}



void player::attack(enemy* badguyPTR) //delete this maybe
{
	bool hit = didItHit(equippedWeaponPTR->getHitRate());

	cout << "You swing your " << getWeaponType() << " at the opponent." << endl;
	if (hit == true)
	{
		cout << "HIT" << endl;//"You hit the opponent." << endl;
		badguyPTR->dealSelfDamage(getDamage());
		cout << "Bad guy took " << getDamage() << " damage. He has " << badguyPTR->getHealth() << " health remaining." << endl;
	}
	else if (hit == false)
	{
		cout << "MISS" << endl;//"You did not hit the opponent." << endl;
	}
	else
	{
		cout << "some error in player.cpp, player::atacking()" << endl;
	}
}


bool player::didEnemyBurn()
{
	return fireMagicPTR->didFireStick();
}

//debug or testing

void player::display()
{
	cout << "Health: " << health << endl
		<< "Magic: " << magic << endl
		<< "Potions: " << potions << endl
		<< "Name: " << name << endl
		<< "Weapon type: " << equippedWeaponPTR->getWeaponType() << endl
		<< "Weapon dmg: " << equippedWeaponPTR->getDamage() << endl
		<< "Weapon crit rate: " << equippedWeaponPTR->getCritRate() << endl
		<< "Weapon crit multiplier: " << equippedWeaponPTR->getCritMult() << endl
		<< "Weapon hit percent chance: " << equippedWeaponPTR->getHitRate() << endl;
	if (!(fireMagicPTR == nullptr))
	{
		fireMagicPTR->display();
	}
	else
	{
		cout << "no magic equipped" << endl;
	}


		/*
	
		health = 100;
	magic = 100;
	potions = 2;
	equippedWeaponPTR = weaponPTR;
	name = "";
	//damage = equippedWeaponPTR->getDamage();
		
		*/
}