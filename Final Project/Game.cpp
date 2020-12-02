#include "Game.h"
extern Global global;
//Player p;
//extern DeveloperTesting dev;
extern GameEvents gameEvents;
using namespace std;

Game::Game()
{
}

/*
BUG!! Need to learn how to allocate memory. The object needs to only live while in the startGame function. How to do?
Pointer to object? How do I use it outside of this function, like in gameEvents?
*/

void Game::startGame()
{
	global.storyOpening();
	global.clearScreen();
	Player * p = new Player();
	//pass the pointer into the function (Player* p) or (*p)
	//access with the -> operator

	//Player p;
	playerSetup(p);

	//loop to run 12 rounds
	for (int i = 0; i < 12; i++)
	{
		system("PAUSE");
		global.clearScreen();

		cout << "Round " << i+1 << " / 12" << endl;
		cout << "Next Stop: " << destination[i] << endl;
		cout << 12 - i << " stops from Terra Prime." << endl << endl;


		supplies(p);
		gameEvents.runGameEvent(p);


		system("PAUSE");
		global.clearScreen();


		cout << "During this round, you: " << endl;
		cout << endl;


		int foodUsed = global.randomRoll(10, 2);
		cout << "Ate " << foodUsed << " pounds of food." << endl; 
		p->setFood(p->getFood() - foodUsed);
		gameEvents.checkStats(p);

		int fuelUsed = global.randomRoll(10, 2);
		cout << "Used " << fuelUsed << " gallons of fuel." << endl << endl; 
		p->setFuel(p->getFuel() - fuelUsed);
		gameEvents.checkStats(p);


		if (isDead(p) == true)
		{
			system("PAUSE");
			endStoryLose(p);
			
		}
	} 

	if (isDead(p) == false)
	{
		system("PAUSE");
		endStoryWin(p);
	}
	
}

bool Game::isDead(Player *p)
{
	if (p->getHealth()<=0 || p->getFood() <=0 || p->getFuel()<=0 || p->getRocketHealth()<=0)
	{
		return true;
	}

	else
	{
		return false;
	}
}


void Game::playerSetup(Player* p)
{
	string name;
	cout << "State your name, warrior. ";
	cin.ignore();
	getline(cin, name);

	p->setName(name);
	global.clearScreen();

	cout << "Hello, " << p->getName() << endl;
	cout << endl;
	p->displayStatus();
	cout << endl;
}

void Game::supplies(Player* p)
{
	p->displayStatus();
	cout << endl;
	char choice = ' ';
	while ( char(tolower(choice)) != 'y' && char(tolower(choice)) != 'n' )//((choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N') 
	{
		cout << "Would you like to visit the shop? (Y/N)" << endl;
		cout << "If no, you will continue traveling." << endl;
		cout << endl;
		cin >> choice;

		if (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N')
		{
			cout << "Oops! That was a bad input. Try again!" << endl;
		}
	}

	if (p->getMoney() < 5)
	{
		cout << endl << "Entry to shop denied! You only have $" << p->getMoney() << "." << endl;
		system("PAUSE");
	}

	else if (choice == 'y' || choice == 'Y')
	{
		bool isDone = false;

		global.clearScreen();

		while (isDone == false)
		{
			global.clearScreen();
			printShop();
			isDone = buyItems(p);
		}
		cout << "\n\n\n";
	}

	else
	{
		global.clearScreen();
		cout << "Continuing to next round..." << endl;
		system("PAUSE");
	}
}



void Game::printShop() //should i put a description along w/ item and cost?
{
	cout << "SPACE CATS SHOP" << endl;
	cout << endl;
	
	cout << "Item";
	cout << setw(32) << "Cost\n" << setw(8);
	cout << "-----------------------------------\n";

	
	for (int i = 0; i < numOfItems; i++)
	{
		cout << left << i + 1 << ". " << setw(20) << shopItems[i];
		cout << right << setw(10) <<"$" <<shopPrices[i];
		cout << endl;
	}
}


bool Game::buyItems(Player* p)
{
	int input;
	cout << endl << endl;
	p->displayStatus();
	cout << endl;
	cout << endl << "What would you like to buy? (Enter 1-4). Enter 0 to go continue next round. ";
	cin >> input;
	cout << endl;

	if (input == 0) //to quit
	{
		global.clearScreen();
	
		cout << "Continuing to next round..." << endl;
		system("PAUSE");
		return true; //finishes program
	}

	if (input - 1 < 0 || input - 1 >= numOfItems) //input validation
	{
		cout << "That was a bad input!\n";
		cout << endl;
		system("PAUSE");
		return false;
	}


	switch (input)
	{
	case 1:
		buyArmor(p);
		break;

	case 2:
		buyFuel(p);
		break;

	case 3:
		buyFood(p);
		break;

	case 4:
		buyRocketArmor(p);
		break;
	}

	cout << endl;

	system("PAUSE");
	return false;
}


void Game::buyArmor(Player* p)
{
	int numOfArmor, price;

	if (p->getHealth() < (p->getmaxHealth()))
	{
		cout << endl;

		cout << "How much armor would you like to buy? ";
		cin >> numOfArmor;
		cout << endl;

		price = numOfArmor * 10;

		if (price > p->getMoney())
		{
			cout << "What? You don't have enough money!" << endl;
		}

		else
		{
			p->setHealth(p->getHealth() + numOfArmor); //adds x hp

			if (p->getHealth() > p->getmaxHealth()) //validation so you can't do 101/100 on armor
			{
				cout << "Error! You have bought more than the max amount of armor." << endl;
				p->setHealth((p->getHealth() - numOfArmor)); //removes x health points
				cout << "Health points: " << p->getHealth() << "/" << p->getmaxHealth();
			}

			else
			{
				cout << "You have bought " << numOfArmor << " piece(s) of armor for $" << price << endl;
				p->setMoney(p->getMoney() - price);

				cout << "You now have: $" << p->getMoney() << endl;


				cout << "Your health is now: " << p->getHealth() << "/" << p->getmaxHealth() << "." << endl;
			}
		}
	}

	else
	{
		cout << "You're not allowed to buy armor! You already have " << p->getHealth() << "/" << p->getmaxHealth() << " hp->" << endl;
	}
}


void Game::buyFuel(Player* p)
{
	int numOfGallons, price;

	if (p->getFuel() < p->getmaxFuel())
	{
		cout << endl;

		cout << "How many gallons of fuel would you like to buy? ";
		cin >> numOfGallons;
		cout << endl;

		price = numOfGallons * 5;

		if (price > p->getMoney())
		{
			cout << "What? You don't have enough money!" << endl;
		}

		else
		{
			p->setFuel((p->getFuel() + numOfGallons)); //adds 1 gallon

			if (p->getFuel() > p->getmaxFuel())
			{
				cout << "Error! You have bought more than the max amount of armor." << endl;
				p->setFuel((p->getFuel() - numOfGallons)); //removes x fuel 
				cout << "Fuel: " << p->getFuel() << "/" << p->getmaxFuel() << " gallons." << endl;
			}

			else
			{
				cout << "You have bought " << numOfGallons << " gallon(s) of fuel $" << price << endl;
				p->setMoney(p->getMoney() - price);
				cout << "You now have: $" << p->getMoney() << endl;
				cout << "Your fuel level is now " << p->getFuel() << "/" << p->getmaxFuel() << "." << endl;
			}
		}
	}

	else
	{
		cout << "You're not allowed to buy fuel! Your fuel level is already " << p->getFuel() << "/" << p->getmaxFuel();
	}
}


void Game::buyFood(Player* p)
{
	int numOfFood, price;

	if (p->getFood() < p->getmaxFood())
	{
		cout << endl;

		cout << "How many pounds of food would you like to buy? ";
		cin >> numOfFood;
		cout << endl;

		price = numOfFood * 5;


		if (price > p->getMoney())
		{
			cout << "What? You don't have enough money!" << endl;
		}

		else
		{
			p->setFood((p->getFood() + numOfFood)); //adds x Food points

			if (p->getFood() > p->getmaxFood())
			{
				cout << "Error! You have bought more than the max amount of food." << endl;
				p->setFood((p->getFood() - numOfFood)); //removes x Food points
				cout << "Food points: " << p->getFood() << "/" << p->getmaxFood();
			}

			else
			{
				cout << "You have bought " << numOfFood << " pound(s) of food for $" << price << endl;
				p->setMoney(p->getMoney() - price);

				cout << "You now have: $" << p->getMoney() << endl;
				cout << "Your food level is now " << p->getFood() << "/" << p->getmaxFood() << endl;
			}
		}
	}

	else
	{
		cout << "You're not allowed to buy food! Your food level is already " << p->getFood() << "/" << p->getmaxFood() << endl;
	}
}


void Game::buyRocketArmor(Player* p)
{
	int numOfArmor, price;

	if (p->getRocketHealth() < (p->getmaxRocketHealth()))
	{
		cout << endl;

		cout << "How much rocket armor would you like to buy? ";
		cin >> numOfArmor;
		cout << endl;

		price = numOfArmor * 10;

		if (price > p->getMoney())
		{
			cout << "What? You don't have enough money!" << endl;
		}

		else
		{
			p->setRocketHealth(p->getRocketHealth() + numOfArmor); //adds x rocket hp

			if (p->getRocketHealth() > p->getmaxRocketHealth()) //validation so you can't do 101/100 on rocket armor
			{
				cout << "Error! You have bought more than the max amount of rocket armor." << endl;
				p->setRocketHealth((p->getRocketHealth() - numOfArmor)); //removes x health points
				cout << "Rocket health points: " << p->getRocketHealth() << "/" << p->getmaxRocketHealth();
			}

			else
			{
				cout << "You have bought " << numOfArmor << " piece(s) of rocket armor for $" << price << endl;
				p->setMoney(p->getMoney() - price);

				cout << "You now have: $" << p->getMoney() << endl;


				cout << "Your rocket health is now: " << p->getRocketHealth() << "/" << p->getmaxRocketHealth() << endl;
			}
		}
	}

	else
	{
		cout << "You're not allowed to buy rocket armor! You already have " << p->getRocketHealth() << "/" << p->getmaxRocketHealth() << " rocket hp->" << endl;
	}
}


void Game::endStoryWin(Player* p)
{
	global.clearScreen();
	cout << "Congratulations, " << p->getName() << "! You win!" << endl;

	system("PAUSE");
	global.clearScreen();
	cout << "You've reached your destination, Terra Prime! You've saved your species and found a new planet to inhabit." << endl;
	system("PAUSE");
	global.clearScreen();
	//delete p;
	mainMenu();
}

void Game::endStoryLose(Player* p)
{
	global.clearScreen();
	p->displayStatus();
	cout << "Sorry, " << p->getName() << "! You lose!" << endl;

	system("PAUSE");
	global.clearScreen();

	cout << "You were not able to survive long enough to finish the mission." << endl;
	system("PAUSE");
	global.clearScreen();
	//delete p;
	mainMenu();
}


Game::~Game()
{
}
