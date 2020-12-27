#include <iostream>
#include "lightMagic.h"

lightMagic::lightMagic()
{
	setDMG(dmg);
	setCritRate(critRate);
	setHitRate(hitRate);
	setMPcost(MPcost);
	setMagicType(magicType);
}


//GET/////////////////////////





//END GET/////////////////////

//gameplay////////////////////

bool lightMagic::didEnemyParalyze()
{
	srand(time(0));
	int rngHold = rand() % 100;
	int randNum = rand() % 100;

	//cout << "rngHold: " << rngHold << endl;
	//cout << "randNum: " << randNum << endl;

	if (randNum < paralyzeChance) 
	{
		//cout << "fire dot hit" << endl;
		return true;
	}
	else if (randNum > paralyzeChance)
	{
		//cout << "fire dot did not hit" << endl;
		return false;
	}
}


//end gameplay////////////////



//debug


void lightMagic::display()
{
	cout << "MagicType: " << magicGen::getMagicType() << endl;
	cout << "magic DMG: " << magicGen::getDMG() << endl;
	cout << "magic CritRate: " << magicGen::getCritRate() << endl;
	cout << "magic critMultiplier: " << magicGen::get_mCritMultiply() << endl;
	cout << "magic HitRate: " << magicGen::getHitRate() << endl;
	cout << "MPcost: " << magicGen::getMPcost() << endl;
	cout << "ParalyzeChance: " << paralyzeChance << endl;
}