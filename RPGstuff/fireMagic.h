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
	int DOTrate = 25;
	int DOTdmg = 10;

	//enemy* enemyPTR = nullptr;


public:

	fireMagic();




	//set
	

	




	//get
	int getDOTrate();

	//gameplay functions
	bool didDOTtick();

	void dealDOTdmg(enemy*);



	//debug
	void display();

};