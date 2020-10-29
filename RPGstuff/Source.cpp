#include <iostream>
#include <string>
#include <ctime>
#include "player.h"
#include "opp.h"
#include "magic.h"
using namespace std;

//name character
//select a weapon, 3 different weapons with different stats
//select magic type, 3 different types
//	fire does dot every turn
//	ice freezes for X amount of time, random between 1-5 or whatever
//	lightning does dmg, high crit chance i guess
// 
//set up turn based thing
//set up specific weapon classes as subclasses of weapon, easier to manage stats etc, do this after "completing" this, making this more streamlined can be a new project
//
//
//
//
//
//most of these functions should get moved into a gameplay class, player and opp classes are redundant

void playerAttack(player* playerPTR, enemy* enemyPTR)
{
	cout << playerPTR->getName() << " swings their " << playerPTR->getWeaponType() << " at " << enemyPTR->getName() << "." << endl;

	if (playerPTR->attack())
	{
		
		if (playerPTR->critCheck(playerPTR->getCritRate()))
		{
			cout << "Critical Hit!" << endl;
			cout << playerPTR->getName() << " hit " << enemyPTR->getName() << "." << endl;
			enemyPTR->dealSelfDamage((playerPTR->getDamage() * playerPTR->getCritMultiply())); 

			if (enemyPTR->getHealth() < 0)
			{
				enemyPTR->setHealth(0);
			}

			cout << enemyPTR->getName() << " took " << playerPTR->getDamage() * playerPTR->getCritMultiply() << " damage. They have " << enemyPTR->getHealth() << " health remaining." << endl; 
		}
		else
		{
			cout << playerPTR->getName() << " hit " << enemyPTR->getName() << "." << endl;
			enemyPTR->dealSelfDamage(playerPTR->getDamage());

			if (enemyPTR->getHealth() < 0)
			{
				enemyPTR->setHealth(0);
			}

			cout << enemyPTR->getName() << " took " << playerPTR->getDamage() << " damage. They have " << enemyPTR->getHealth() << " health remaining." << endl;
		}

		
	}
	else if (!playerPTR->attack())
	{
		cout << playerPTR->getName() << " did not hit " << enemyPTR->getName() << "." << endl;
	}
	else
	{
		cout << "some error in void playerAttack() in source.cpp";
	}
}

void enemyAttack(player* playerPTR, enemy* enemyPTR)
{
	cout << enemyPTR->getName() << " swings their " << enemyPTR->getWeaponType() << " at " << playerPTR->getName() << "." << endl;

	if (enemyPTR->attack())
	{
		cout << enemyPTR->getName() << " hit " << playerPTR->getName() << "." << endl;
		//put crit check here?
		playerPTR->dealSelfDamage(enemyPTR->getDamage());

		if (playerPTR->getHealth() < 0)
		{
			playerPTR->setHealth(0);
		}

		cout << playerPTR->getName() << " took " << enemyPTR->getDamage() << " damage. They have " << playerPTR->getHealth() << " health remaining." << endl;
	}
	else if (!enemyPTR->attack())
	{
		cout << enemyPTR->getName() << " did not hit " << playerPTR->getName() << "." << endl;
	}
	else
	{
		cout << "some error in void playerAttack() in source.cpp";
	}
}


void battle(player* playerPTR, enemy* enemyPTR)
{
	int turnCounter = 1;
	int userChoice;

	cout << playerPTR->getName() << " is fighting " << enemyPTR->getName() << "." << endl;



	while (playerPTR->getHealth() > 0 && enemyPTR->getHealth() > 0) //test this
	{
		cout << endl << "Turn #" << turnCounter << endl << endl;
		cout << "What would you like to do?" << endl;
		cout << "1. Attack" << endl; //add more options, display stats somewhere
		cin >> userChoice;
		cout << endl; //add input validation

		if (userChoice == 1)
		{
			playerAttack(playerPTR, enemyPTR); //add a check to break loop if someone hits zero

			if (enemyPTR->getHealth() <= 0)
			{
				break;
			}
		}

		enemyAttack(playerPTR, enemyPTR);

		if (playerPTR->getHealth() <= 0)
		{
			break;
		}

		turnCounter++;
	}

	if (enemyPTR->getHealth() <= 0)
	{
		cout << playerPTR->getName() << " has killed " << enemyPTR->getName() << "." << endl;
	}
	else if (playerPTR->getHealth() <= 0)
	{
		cout << enemyPTR->getName() << " has killed " << playerPTR->getName() << "." << endl;
	}
	else
	{
		cout << "some error in void battle() in source.cpp" << endl;
	}
}


void nameCharacter(player* playerPTR) //gonna have scoping problems
{
	string userName;

	cout << "Please name your character: ";
	cin >> userName;
	
	playerPTR->setName(userName);

	//player* player1PTR = new player(userName); //declare outside this function

	

	//return player1PTR;
}

void weaponSelect(player* playerPTR)
{
	int userChoice;
	cout << "Please choose a weapon." << endl << "1. Sword" << endl << "2. Axe" << endl << "3. Club" << endl;
	cin >> userChoice;
	//setup input validation                   int dmg, int critR, int critM, int hitR, string type

	if (userChoice == 1)
	{
		weapon* swordPTR = new weapon(25, 50, 2, 85, "Sword"); 
		playerPTR->setEquipWeapon(swordPTR);
	}
	else if (userChoice == 2)
	{
		weapon* axePTR = new weapon(50, 65, 3, 75, "Axe"); // change stats
		playerPTR->setEquipWeapon(axePTR);
	}
	else if (userChoice == 3)
	{
		weapon* clubPTR = new weapon(75, 25, 2, 50, "Club"); // change stats
		playerPTR->setEquipWeapon(clubPTR);
	}
	else
	{
		cout << "invalid choice" << endl;
	}
}

void magicSelect(player* playerPTR)
{
	int userChoice;
	cout << "Please choose a magic type." << endl << "1. Fire" << endl << "2. Ice" << endl << "3. Lightning" << endl;
	cin >> userChoice;
	//setup input validation

	if (userChoice == 1)
	{
		
	}
	else if (userChoice == 2)
	{
		
	}
	else if (userChoice == 3)
	{
		
	}
	else
	{
		cout << "invalid choice" << endl;
	}

}

void menu(player* playerPTR, enemy* enemyPTR)
{
	int userChoice = 1;

	while (userChoice == 1)
	{
		cout << endl << "1. Fight" << endl << "2. Exit" << endl;
		cin >> userChoice; // add input validation

		if (userChoice == 1)
		{
			nameCharacter(playerPTR);
			weaponSelect(playerPTR);
			battle(playerPTR, enemyPTR);
		}
		else if (userChoice == 2)
		{
			break;
		}
		else
		{
			cout << endl << endl << "some error in menu function, line 176" << endl;
		}

	}
	
}


///////////MAIN MAIN FUNCTION DO NOT DELETE THIS 
/*
int main()
{
	/*
	weapon* swordPTR = new weapon(25, 50, 2, 85, "sword");
	player player1(swordPTR);
	
	enemy* badGuyPTR = new enemy;

	//new attack function
	player1.attack(badGuyPTR);



	//testing rng
	/*
	for (int i = 0; i < 500; i++)
	{
		player1.attacking(swordOBJ, badGuyOBJ);
		cout << endl << endl;
	}
	

	//delete swordPTR;
	//delete badGuyPTR;


	player* player1PTR = new player();
	enemy* enemy1PTR = new enemy();

	menu(player1PTR, enemy1PTR);


	//cout << endl << endl;
	//player1PTR->display();



	


	return 0;
}
*/

/////////////////////////////////////////////////////////////////////////
//MAGIC TEST AREA////////////////////////////////////////////////////////


int main()
{
	fireMagic fire;
	enemy* badguyPTR = new enemy;
	fire.display();
	cout << endl << endl;
	cout << "badguy health is: " << badguyPTR->getHealth() << endl;
	if (fire.didDOTtick())
	{
		fire.dealDOTdmg(badguyPTR);
		cout << "badguy health is now: " << badguyPTR->getHealth() << endl;
	}
	else
	{
		cout << "fire did not hit" << endl;
	}
	return 0;
}





//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////