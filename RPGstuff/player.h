#pragma once
#include <iostream>
#include <ctime>
#include "opp.h"
#include "magicGen.h"
#include "iceMagic.h"
#include "fireMagic.h"
using namespace std;


class player
{
private:
	
	int health;
	int magic;
	int potions;

	int MPcost;

	//int damage;
	weapon* equippedWeaponPTR;
	fireMagic* fireMagicPTR;
	iceMagic* iceMagicPTR;
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

	string getMagicType();

	int getMagicHitRate();

	int getMagicDamage();

	int getFireDOTdmg();

	int getMagicCritRate();

	int getMPcost();

	int get_mCritMultiply();

	//set
	void dealSelfDamage(int);

	void setDamage(int);

	void setEquipWeapon(weapon*);

	void setMagicEquip(fireMagic*);

	void setMagicEquip(iceMagic*);

	void setName(string userN);

	void setHealth(int);

	void setMPcost(int);

	//gameplay 

	bool attack();

	void attack(enemy*); //delete maybe

	bool didItHit(int);

	bool critCheck(int);

	bool didEnemyBurn();

	bool didEnemyFreeze();

	int minusMagic();

	//debug or testing
	void display();

};