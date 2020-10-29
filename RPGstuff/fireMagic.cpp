#include <iostream>
#include "fireMagic.h"


using namespace std;

fireMagic::fireMagic()
{
	setDMG(20);
	setCritRate(15);
	setHitRate(50);
	setMPcost(15);
	
}







//get
int fireMagic::getDOTrate()
{
	return DOTrate;
}



//gameplay functions
bool fireMagic::didDOTtick()
{

	srand(time(0));
	int rngHold = rand() % 100;
	int randNum = rand() % 100;

	//cout << "rngHold: " << rngHold << endl;
	//cout << "randNum: " << randNum << endl;

	if (randNum < DOTrate)
	{
		//cout << "fire dot hit" << endl;
		return true;
	}
	else if (randNum > DOTrate)
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
	cout << "DMG: " << magicGen::getDMG() << endl;
	cout << "CritRate: " << magicGen::getCritRate() << endl;
	cout << "HitRate: " << magicGen::getHitRate() << endl;
	cout << "MPcost: " << magicGen::getMPcost() << endl;
	cout << "DOTrate: " << DOTrate << endl;
	cout << "DOTdmg: " << DOTdmg << endl;
}