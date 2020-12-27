#pragma once
#include <iostream>
#include <ctime>
#include <string>
#include "magicGen.h"

using namespace std;

class iceMagic : public magicGen
{
private:
	int dmg = 0;
	int critRate = 15;
	int hitRate = 60;
	int MPcost = 20; 
	string magicType = "ice";

	int freezeChance = 25;


public:

	iceMagic();


	//SET///////////////

	//END SET///////////

	//GET///////////////
	int getFreezeChance();
		



	//END GET///////////

	//gameplay//////////

	bool didEnemyFreeze();


	//end gameplay//////



	//debug
	void display();



};

/*
class iceMagic : public magicGen
{
private:

	int freezeChance = 25;

public:
	iceMagic();






	int getFreezeChance();





	bool didEnemyFreeze();




	void display();
};

*/