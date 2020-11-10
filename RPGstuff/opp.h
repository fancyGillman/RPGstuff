#pragma once
#include <iostream>
#include "weapon.h"
using namespace std;

class enemy
{
private:
	int health;
	int magic;
	int potions;
	int damage;
	string name;
	weapon* equippedWeaponPTR;
	bool isBurned;
	bool isFrozen;
	int freezeCounter;

public:
	enemy();

	~enemy();

	//grab
	int getHealth();

	int getMagic();

	int getPotions();

	int getDamage();

	string getName();

	string getWeaponType();

	bool getIsBurned();

	bool getIsFrozen();
	//set

	void dealSelfDamage(int);
	

	void setDamage(int);
	

	void setEquipWeapon(weapon&);
	
	void setHealth(int);

	void setIsBurned(bool);

	void setIsFrozen(bool);

	void setFreezeCounter();

	//gameplay

	bool attack();

	bool didItHit(int);

};