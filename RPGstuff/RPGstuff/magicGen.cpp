#include "magicGen.h"

using namespace std;



//set

void magicGen::setDMG(int n)
{
	dmg = n;
}

void magicGen::setCritRate(int n)
{
	critRate = n;
}

void magicGen::setHitRate(int n)
{
	hitRate = n;
}

void magicGen::setMPcost(int n)
{
	MPcost = n;
}

void magicGen::setMagicType(string n)
{
	magicType = n;
}

//get
int magicGen::getDMG()
{
	return dmg;
}

int magicGen::getCritRate()
{
	return critRate;
}

int magicGen::getHitRate()
{
	return hitRate;
}

int magicGen::getMPcost()
{
	return MPcost;
}

int magicGen::get_mCritMultiply()
{
	return mCritMultiply;
}

string magicGen::getMagicType()
{
	return magicType;
}