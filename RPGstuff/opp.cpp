#include <iostream>
#include "opp.h"
#include <ctime>

using namespace std;


enemy::enemy()
{
	health = 1000;
	magic = 100;
	potions = 2;
	name = "bad guy"; //set up something for rng list of names
	equippedWeaponPTR = new weapon(25, 50, 2, 85, "Sword");
	damage = equippedWeaponPTR->getDamage();
	isBurned = false;
	isFrozen = false;
	freezeCounter = 0;
}

enemy::~enemy()
{
	delete equippedWeaponPTR;
}

//enemy::enemy()
//{
//
//}

//grab
int enemy::getHealth()
{
	return health;
}

int enemy::getMagic()
{
	return magic;
}

int enemy::getPotions()
{
	return potions;
}

int enemy::getDamage()
{
	return equippedWeaponPTR->getDamage();
}

string enemy::getName()
{
	return name;
}

string enemy::getWeaponType()
{
	return equippedWeaponPTR->getWeaponType();
}

bool enemy::getIsBurned()
{
	return isBurned;
}

bool enemy::getIsFrozen()
{
	return isFrozen;
}
//set

void enemy::dealSelfDamage(int oppDMG)
{
	health = health - oppDMG;
}

void enemy::setDamage(int wDamage)
{
	damage = wDamage;
}

void enemy::setEquipWeapon(weapon& w)
{
	damage = w.getDamage();
	//equippedWeaponPTR = ; //remove?
}

void enemy::setHealth(int num)
{
	health = num;
}

void enemy::setIsBurned(bool b)
{
	isBurned = b;
}

void enemy::setIsFrozen(bool b)
{
	isFrozen = b;
}

void enemy::setFreezeCounter()
{
	freezeCounter = 5;
}
//gameplay

bool enemy::didItHit(int wHitRate)
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

bool enemy::attack()
{
	return didItHit(equippedWeaponPTR->getHitRate());
}
