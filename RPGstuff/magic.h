#pragma once
#include <string>
#include "fireMagic.h"
using namespace std;




//de;ete this file at some point
class magicT
{
private:
	
	int dmg;
	int critRate;
	int hitRate;



public:
	magicT();



	//set

	void setMagicDMG(int);

	void setCritRate(int);

	void setHitRate(int);




	//get
	int getMagicDMG();

	int getCritRate();

	int getHitRate();

};