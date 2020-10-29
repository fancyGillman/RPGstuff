#pragma once
#include <iostream>
#include <ctime>
#include "opp.h"
#include "weapon.h"
#include "magic.h"
using namespace std;


class player
{
private:
	
	int health;
	int magic;
	int potions;
	//int damage;
	weapon* equippedWeaponPTR;
	magicT* equippedMagicPTR;
	string name;
	//enemy* enemyPTR;//might not need these

public:
	player();

	player(weapon* weaponPTR); //for weapon

	player(string); //for name
	
	~player();
					
					
	//grab
	int getHealth();

	int getMagic();

	int getPotions();

	int getDamage();

	string getWeaponType();

	string getName();

	int getCritRate();

	int getCritMultiply();

	//set
	void dealSelfDamage(int);

	void setDamage(int);

	void setEquipWeapon(weapon*);

	void setMagicEquip(magicT*);

	void setName(string userN);

	void setHealth(int);

	//gameplay 

	bool attack();

	void attack(enemy*); //delete maybe

	bool didItHit(int);

	bool critCheck(int);

	//debug or testing
	void display();

};