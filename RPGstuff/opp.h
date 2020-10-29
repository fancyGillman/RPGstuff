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


	//set

	void dealSelfDamage(int);
	

	void setDamage(int);
	

	void setEquipWeapon(weapon&);
	
	void setHealth(int);

	//gameplay

	bool attack();

	bool didItHit(int);

};