#pragma once
#include <iostream>
#include <ctime>
#include <string>
#include "magicGen.h"

using namespace std;

class lightMagic : public magicGen
{
private:
	int dmg = 0;
	int critRate = 15;
	int hitRate = 60;
	int MPcost = 0;
	string magicType = "lightning";

	int paralyzeChance = 15;


public:

	lightMagic();


	//SET///////////////

	//END SET///////////

	//GET///////////////
	




	//END GET///////////

	//gameplay//////////

	bool didEnemyParalyze();
	


	//end gameplay//////



	//debug
	void display();



};