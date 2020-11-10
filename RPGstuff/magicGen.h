#pragma once
#include <iostream>
//#include "opp.h"


using namespace std;

class magicGen 
{
private:
	int dmg;
	int critRate;
	int hitRate;
	int MPcost;
	int mCritMultiply = 2;
	string magicType;
	
public:
	




	//set
	void setDMG(int);

	void setCritRate(int);

	void setHitRate(int);

	void setMPcost(int);

	void setMagicType(string);
	//get

	int getDMG();

	int getCritRate();

	int getHitRate();

	int getMPcost();

	int get_mCritMultiply();

	string getMagicType();
};