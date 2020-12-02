#include "DeveloperTesting.h"
extern Global global;
extern GameEvents gameEvents;
extern Game game;
//Player *p = new Player;

DeveloperTesting::DeveloperTesting()
{

}


void DeveloperTesting::devTest()
{
	Player* p = new Player;
	std::cout << "Which would you like to test?" << std::endl;
	cout << endl;

	cout << "1. Random Roll" << endl;
	cout << "2. Test Random Game Event" << endl;
	cout << "3. Buy Supplies" << endl;
	cout << "4. Test Negative Stats" << endl;
	cout << "5. Test Player Intro" << endl;
	cout << "6. Press To Go Back" << endl;
	

	cin >> choice;

	//test different functionalities
	switch (choice)
	{
	case 1:
		global.clearScreen();
		cout << "Random number between 1 and 10: "<< global.randomRoll(10, 1) << endl;
		break;

	case 2:
		gameEvents.runGameEvent(p);
		break;

	case 3:
		game.supplies(p);
		break;

	case 4:
		global.clearScreen();
		cout << "This program ensures I don't get negative stats in the game." << endl << endl;
		cout << "You lost $5000" << endl;
		cout << "You lost 5000 hp->" << endl;
		cout << "You lost 5000 gallons of fuel." << endl;
		cout << "You lost 5000 pounds of food" << endl;
		cout << "You lost 5000 rocket hp" << endl << endl;
		p->setMoney(p->getMoney()-5000);
		p->setHealth(p->getHealth() - 5000);
		p->setFuel(p->getFuel() - 5000);
		p->setFood(p->getFood() - 5000);
		p->setRocketHealth(p->getRocketHealth() - 5000);
		p->displayStatus();

		cout << endl << "**USING CHECK STATS FUNCTION**" << endl;
		gameEvents.checkStats(p);
		p->displayStatus();
		cout << endl << "The end result should take whatever negative stat I have and set it to 0" << endl;
		break;

	case 5:
		game.playerSetup(p);
		break;

	case 6:
		cout << "This should return to main menu" << endl;
		global.pressToGoBack();
		break;

	}
}