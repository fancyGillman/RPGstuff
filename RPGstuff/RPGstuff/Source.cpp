#include <string>
#include "player.h"

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
//going to have to convert a lot of numbers to floats if i want any crit rates to be decimals
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

void playerMagicAttack(player* playerPTR, enemy* enemyPTR)
{
	cout << playerPTR->getName() << " used " << playerPTR->getMPcost() << " magic to shoot a " 
		<< playerPTR->getMagicType() << " ball at " << enemyPTR->getName() << ". " << endl
		<< playerPTR->minusMagic() << " magic remaining." << endl;

	if (playerPTR->didItHit(playerPTR->getMagicHitRate()))
	{
		if (playerPTR->critCheck(playerPTR->getMagicCritRate())) //crit check here
		{
			cout << "Critical hit!" << endl;

			cout << playerPTR->getName() << " hit " << enemyPTR->getName() << "." << endl;
			enemyPTR->dealSelfDamage(playerPTR->getMagicDamage() * 2); //probably should make crit dmg into a function or something

			if (enemyPTR->getHealth() < 0)
			{
				enemyPTR->setHealth(0);
			}

			cout << enemyPTR->getName() << " took " << playerPTR->getMagicDamage() * playerPTR->get_mCritMultiply() << " damage. They have " << enemyPTR->getHealth() << " health remaining." << endl;

			if (playerPTR->getMagicType() == "fire")
			{
				if (playerPTR->didEnemyBurn() && !(enemyPTR->getIsBurned()))
				{
					enemyPTR->setIsBurned(true);
					cout << enemyPTR->getName() << " was lit on fire!" << endl;
				}
			}
			else if (playerPTR->getMagicType() == "ice") 
			{
				if (playerPTR->didEnemyFreeze() && !(enemyPTR->getIsFrozen()))
				{
					enemyPTR->setIsFrozen(true);
					cout << enemyPTR->getName() << " was frozen!" << endl;
				}
			}
			else if (playerPTR->getMagicType() == "lightning")
			{
				if (playerPTR->didEnemyParalyze() && !(enemyPTR->getIsParalyzed()))
				{
					enemyPTR->setIsParalyzed(true);
					cout << enemyPTR->getName() << " was paralyzed!" << endl;
				}
			}
		}
		else
		{
			cout << playerPTR->getName() << " hit " << enemyPTR->getName() << "." << endl;
			enemyPTR->dealSelfDamage(playerPTR->getMagicDamage());

			if (enemyPTR->getHealth() < 0)
			{
				enemyPTR->setHealth(0);
			}

			cout << enemyPTR->getName() << " took " << playerPTR->getMagicDamage() << " damage. They have " << enemyPTR->getHealth() << " health remaining." << endl;

			if (playerPTR->getMagicType() == "fire")
			{
				if (playerPTR->didEnemyBurn() && !(enemyPTR->getIsBurned()))
				{ 
					enemyPTR->setIsBurned(true);
					cout << enemyPTR->getName() << " was lit on fire!" << endl;
				}

			}
			else if (playerPTR->getMagicType() == "ice")
			{
				if (playerPTR->didEnemyFreeze() && !(enemyPTR->getIsFrozen()))
				{
					enemyPTR->setIsFrozen(true);
					cout << enemyPTR->getName() << " was frozen!" << endl;
				}
			}
			else if (playerPTR->getMagicType() == "lightning")
			{
				if (playerPTR->didEnemyParalyze() && !(enemyPTR->getIsParalyzed()))
				{
					enemyPTR->setIsParalyzed(true);
					cout << enemyPTR->getName() << " was paralyzed!" << endl;
				}
			}

		}

	}
	else if (!(playerPTR->didItHit(playerPTR->getMagicHitRate())))
	{
		cout << playerPTR->getName() << " did not hit " << enemyPTR->getName() << "." << endl;
	}
	else
	{
		cout << "some error in void playerMagicAttack() in source.cpp";
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
		cout << "1. Attack" << endl << "2. " << playerPTR->getMagicType() << " magic attack   MP cost: " << playerPTR->getMPcost() << "    MP remaining: " << playerPTR->getMagic() << endl
			<< "3. Drink Magic Potion    Magic Potions: INSERT NUMBER HERE" << endl; //add more options, display stats somewhere
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
		else if (userChoice == 2)
		{
			if (playerPTR->getMagic() < playerPTR->getMPcost())
			{
				cout << "Not enough magic!" << endl;
				continue;
			}


			playerMagicAttack(playerPTR, enemyPTR);

			if (enemyPTR->getHealth() <= 0)
			{
				break;
			}
		}
		
		if (enemyPTR->getIsFrozen()) //freeze check
		{
			cout << enemyPTR->getName() << " is frozen!" << endl;
			enemyPTR->decrementFreezeCounter();
			//cout << "Freeze counter: " << enemyPTR->getFreezeCounter() << endl << endl;

			if (enemyPTR->getFreezeCounter() <= 0)
			{
				cout << enemyPTR->getName() << " has thawed out!" << endl;
				enemyPTR->setIsFrozen(false);
			}
				
		}

		if (enemyPTR->getIsParalyzed()) //paralysis check
		{
			cout << enemyPTR->getName() << " is paralyzed!" << endl;
			enemyPTR->decrementParalyzeCounter();

			if (enemyPTR->getParalyzeCounter() <= 0)
			{
				cout << enemyPTR->getName() << " is not paralyzed" << endl;
				enemyPTR->setIsParalyzed(false); //move the stuff that decrements paralysis into paralysisThisTurn
			}
		}
		

		if (!(enemyPTR->getIsFrozen()) && !(enemyPTR->paralysisThisTurn()))
			//enemyAttack(playerPTR, enemyPTR);
		







		if (playerPTR->getHealth() <= 0)
		{
			break;
		}

		if (enemyPTR->getIsBurned()) //burn check
		{
			enemyPTR->dealSelfDamage(playerPTR->getFireDOTdmg());
			cout << enemyPTR->getName() << " took " << playerPTR->getFireDOTdmg() << " burn damage. They have "
				<< enemyPTR->getHealth() << " health remaining." << endl;
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
		playerPTR->setMagicEquip(new fireMagic);
	}
	else if (userChoice == 2)
	{
		playerPTR->setMagicEquip(new iceMagic);
	}
	else if (userChoice == 3)
	{
		playerPTR->setMagicEquip(new lightMagic);
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
			magicSelect(playerPTR);
			
			//playerPTR->display();

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


int main()
{
	
	//weapon* swordPTR = new weapon(25, 50, 2, 85, "sword");
	//player player1(swordPTR);
	
	//enemy* badGuyPTR = new enemy;

	


	

	//delete swordPTR;
	//delete badGuyPTR;
	

	

	player* player1PTR = new player();
	enemy* enemy1PTR = new enemy();

	menu(player1PTR, enemy1PTR);


	//cout << endl << endl;
	//player1PTR->display();



	


	return 0;
}


/////////////////////////////////////////////////////////////////////////
//MAGIC TEST AREA////////////////////////////////////////////////////////

/*
int main()
{
	iceMagic* iceMagicPTR = new iceMagic;
	iceMagicPTR->display();


	return 0;
}
*/




//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////