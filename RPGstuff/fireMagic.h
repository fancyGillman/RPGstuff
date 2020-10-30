#pragma once

#include <iostream>
#include <ctime>
#include "magicGen.h"
#include "opp.h"

using namespace std;

class fireMagic : public magicGen
{

private:
	//store dmg, crit rate, etc values here?
	int burnChance = 25;
	int DOTdmg = 10;
	string magicTypeF = "fire";
	//enemy* enemyPTR = nullptr;


public:

	fireMagic();




	//set
	

	




	//get
	int getBurnChance();

	int getDOTdmg();

	//gameplay functions

	void dealDOTdmg(enemy*);

	bool didFireStick();

	//debug
	void display();

};