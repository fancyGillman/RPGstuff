#pragma once
#include <iostream>

using namespace std;

class magicGen 
{
private:
	int dmg;
	int critRate;
	int hitRate;
	int MPcost;
	
public:
	




	//set
	void setDMG(int);

	void setCritRate(int);

	void setHitRate(int);

	void setMPcost(int);

	//get

	int getDMG();

	int getCritRate();

	int getHitRate();

	int getMPcost();

};