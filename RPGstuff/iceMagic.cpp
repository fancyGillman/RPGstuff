#include <iostream>
#include "iceMagic.h"

iceMagic::iceMagic()
{
	setDMG(dmg);
	setCritRate(critRate);
	setHitRate(hitRate);
	setMPcost(MPcost);
	setMagicType(magicType);
}


//GET/////////////////////////
int iceMagic::getFreezeChance()
{
	return freezeChance;
}





//END GET/////////////////////

//gameplay////////////////////

bool iceMagic::didEnemyFreeze()
{
	srand(time(0));
	int rngHold = rand() % 100;
	int randNum = rand() % 100;

	//cout << "rngHold: " << rngHold << endl;
	//cout << "randNum: " << randNum << endl;

	if (randNum < freezeChance)
	{
		//cout << "fire dot hit" << endl;
		return true;
	}
	else if (randNum > freezeChance)
	{
		//cout << "fire dot did not hit" << endl;
		return false;
	}
}


//end gameplay////////////////



//debug


void iceMagic::display()
{
	cout << "MagicType: " << magicGen::getMagicType() << endl;
	cout << "magic DMG: " << magicGen::getDMG() << endl;
	cout << "magic CritRate: " << magicGen::getCritRate() << endl;
	cout << "magic critMultiplier: " << magicGen::get_mCritMultiply() << endl;
	cout << "magic HitRate: " << magicGen::getHitRate() << endl;
	cout << "MPcost: " << magicGen::getMPcost() << endl;
	cout << "FreezeChance: " << freezeChance << endl;
}