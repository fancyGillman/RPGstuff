#pragma once
#include <iostream>
#include <string>


using namespace std;

class weapon
{
private:
	int damage;
	int hitRate; //should change some of these to floats
	int critRate;
	int critMultiplier;
	string weaponType;

public:
	weapon();

	weapon(int, int, int, int, string);

	//grab
	int getDamage();

	int getCritRate();

	int getCritMult();

	int getHitRate();

	string getWeaponType();
	//set
};