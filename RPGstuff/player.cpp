#include "player.h"

using namespace std;

player::player()
{
	health = 1000;
	magic = 100;
	potions = 2;
	//damage = 0;
	

	weapon* equippedWeaponPTR = nullptr; 
	fireMagic* fireMagicPTR = nullptr;
	iceMagic* iceMagicPTR = nullptr;
	name = "";
	//enemy* enemyPTR = nullptr;//might not need
}

//this constructor and the string constructor below never get used, ignore these
player::player(weapon* weaponPTR)//, magicT* magicPTR)
{
	health = 1000;
	magic = 100;
	potions = 2;
	equippedWeaponPTR = weaponPTR;
	//equippedMagicPTR - magicPTR;
	name = "";
	//damage = equippedWeaponPTR->getDamage();
}

player::player(string userName)
{
	health = 100;
	magic = 100;
	potions = 2;
	equippedWeaponPTR = nullptr;
	name = userName;
	//damage = 0;
}

player::~player()
{
	delete equippedWeaponPTR;
	delete fireMagicPTR;
}

//grab
int player::getHealth()
{
	return health;
}

int player::getMagic()
{
	return magic;
}

int player::getPotions()
{
	return potions;
}

int player::getDamage()
{
	return equippedWeaponPTR->getDamage();
}

string player::getWeaponType()
{
	return equippedWeaponPTR->getWeaponType();
}

string player::getName()
{
	return name;
}

int  player::getCritRate()
{
	return equippedWeaponPTR->getCritRate();
}

int player::getCritMultiply()
{
	return equippedWeaponPTR->getCritMult();
}

string player::getMagicType()
{
	if (!(fireMagicPTR == nullptr))
		return fireMagicPTR->getMagicType();
	else if (!(iceMagicPTR == nullptr))
		return iceMagicPTR->getMagicType();
	else
		return "no magic type";
}

int player::getMagicHitRate()
{
	if (!(fireMagicPTR == nullptr))
	{
		return fireMagicPTR->getHitRate();
	}
	else if (!(iceMagicPTR == nullptr))
		return iceMagicPTR->getHitRate();
}

int player::getMagicDamage()
{
	if (!(fireMagicPTR == nullptr))
		return fireMagicPTR->getDMG();
	else if (!(iceMagicPTR == nullptr))
		return iceMagicPTR->getDMG();
}

int player::getFireDOTdmg()
{
	return fireMagicPTR->getDOTdmg();
}

int player::getMagicCritRate()
{
	if (!(fireMagicPTR == nullptr))
		return fireMagicPTR->getCritRate();
	else if (!(iceMagicPTR == nullptr))
		return iceMagicPTR->getCritRate();
}

int player::getMPcost()
{
	return MPcost;
}

int player::get_mCritMultiply()
{
	if (!(fireMagicPTR == nullptr))
		return fireMagicPTR->get_mCritMultiply();
	else if (!(iceMagicPTR == nullptr))
		return iceMagicPTR->get_mCritMultiply();
}

/////END OF GETS/////////////////////////////////////////////////////////////////////////////////

//START OF SETS///////////////////////////////////////////////////////////////////////////////////
void player::dealSelfDamage(int oppDMG)
{
	health = health - oppDMG;
}

/*
void player::setDamage(int wDamage)
{
	damage = wDamage;
}
*/

void player::setEquipWeapon(weapon* wPTR)
{
	equippedWeaponPTR = wPTR;
	//damage = equippedWeaponPTR->getDamage();
}

void player::setMagicEquip(fireMagic* fPTR) //make overloaded functions with different magictype PTRs
{
	fireMagicPTR = fPTR;
	
	setMPcost(fPTR->getMPcost());
}

void player::setMagicEquip(iceMagic* iPTR)
{
	iceMagicPTR = iPTR;

	setMPcost(iPTR->getMPcost());
}

void player::setName(string userN)
{
	name = userN;
}

void player::setHealth(int num)
{
	health = num;
}

void player::setMPcost(int n)
{
	MPcost = n;
}

//gameplay

int player::minusMagic()
{
	 magic = magic - MPcost;

	 if (magic < 0)
		 magic = 0;

	 return magic;
}

bool player::didItHit(int wHitRate)
{

	srand(time(0));
	int rngHold = rand() % 100; 
	int randNum = rand() % 100;

	//cout << "rngHold: " << rngHold << endl;
	//cout << "randNum: " << randNum << endl;

	if (randNum < wHitRate)
	{
		return true;
	}
	else if (randNum > wHitRate)
	{
		return false;
	}

}

bool player::critCheck(int critRate)
{
	srand(time(0));
	int rngHold = rand() % 100;
	int randNum = rand() % 100;

	if (randNum < critRate)
	{
		return true;
	}
	else if (randNum > critRate)
	{
		return false;
	}

}

bool player::attack()
{
	return didItHit(equippedWeaponPTR->getHitRate());
}



void player::attack(enemy* badguyPTR) //delete this maybe
{
	bool hit = didItHit(equippedWeaponPTR->getHitRate());

	cout << "You swing your " << getWeaponType() << " at the opponent." << endl;
	if (hit == true)
	{
		cout << "HIT" << endl;//"You hit the opponent." << endl;
		badguyPTR->dealSelfDamage(getDamage());
		cout << "Bad guy took " << getDamage() << " damage. He has " << badguyPTR->getHealth() << " health remaining." << endl;
	}
	else if (hit == false)
	{
		cout << "MISS" << endl;//"You did not hit the opponent." << endl;
	}
	else
	{
		cout << "some error in player.cpp, player::atacking()" << endl;
	}
}


bool player::didEnemyBurn()
{
	return fireMagicPTR->didFireStick();
}

bool player::didEnemyFreeze()
{
	return iceMagicPTR->didEnemyFreeze();
}

//debug or testing

void player::display()
{
	cout << "Health: " << health << endl
		<< "Magic: " << magic << endl
		<< "Potions: " << potions << endl
		<< "Name: " << name << endl
		<< "Weapon type: " << equippedWeaponPTR->getWeaponType() << endl
		<< "Weapon dmg: " << equippedWeaponPTR->getDamage() << endl
		<< "Weapon crit rate: " << equippedWeaponPTR->getCritRate() << endl
		<< "Weapon crit multiplier: " << equippedWeaponPTR->getCritMult() << endl
		<< "Weapon hit percent chance: " << equippedWeaponPTR->getHitRate() << endl;
	if (!(fireMagicPTR == nullptr))
	{
		fireMagicPTR->display();
	}
	else if (!(iceMagicPTR == nullptr))
	{
		iceMagicPTR->display();
	}
	else
	{
		cout << "no magic equipped" << endl;
	}


		/*
	
		health = 100;
	magic = 100;
	potions = 2;
	equippedWeaponPTR = weaponPTR;
	name = "";
	//damage = equippedWeaponPTR->getDamage();
		
		*/
}