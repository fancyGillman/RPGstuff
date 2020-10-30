#include <iostream>
#include "fireMagic.h"


using namespace std;

fireMagic::fireMagic()
{
	setDMG(20);
	setCritRate(15);
	setHitRate(50);
	setMPcost(15);
	setMagicType(magicTypeF);
}



//get
int fireMagic::getBurnChance()
{
	return burnChance;
}

int fireMagic::getDOTdmg()
{
	return DOTdmg;
}


//gameplay functions
bool fireMagic::didFireStick()
{

	srand(time(0));
	int rngHold = rand() % 100;
	int randNum = rand() % 100;

	//cout << "rngHold: " << rngHold << endl;
	//cout << "randNum: " << randNum << endl;

	if (randNum < burnChance)
	{
		//cout << "fire dot hit" << endl;
		return true;
	}
	else if (randNum > burnChance)
	{
		//cout << "fire dot did not hit" << endl;
		return false;
	}

}

void fireMagic::dealDOTdmg(enemy* enemyPTR)
{
	enemyPTR->dealSelfDamage(getDMG());
}




//debug

void fireMagic::display()
{
	cout << "MagicType: " << magicGen::getMagicType() << endl;
	cout << "DMG: " << magicGen::getDMG() << endl;
	cout << "CritRate: " << magicGen::getCritRate() << endl;
	cout << "HitRate: " << magicGen::getHitRate() << endl;
	cout << "MPcost: " << magicGen::getMPcost() << endl;
	cout << "BurnChance: " << burnChance << endl;
	cout << "DOTdmg: " << DOTdmg << endl;
}