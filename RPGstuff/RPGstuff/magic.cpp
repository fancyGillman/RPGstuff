#include <iostream>
#include "magic.h"

using namespace std;





//delete this file at some point
magicT::magicT()
{
	
	int dmg = 0;
	int critRate = 0;
	int hitRate = 0;
}

//magicT::~magicT()
//{
	//fill in later?
//}

//set

void magicT::setMagicDMG(int n)
{
	dmg = n;
}

void magicT::setCritRate(int n)
{
	critRate = n;
}

void magicT::setHitRate(int n)
{
	hitRate = n;
}

//get
int magicT::getMagicDMG()
{
	return dmg;
}

int magicT::getCritRate()
{
	return critRate;
}

int magicT::getHitRate()
{
	return hitRate;
}


//magicT::
