/*
CS181 - Fall 2018
Final Project
Tyler Le
05/12/2018
This is my final project, Space Cats.
*/

#include "Global.h"
using namespace std;

Global global;
Game game;
DeveloperTesting dev;
GameEvents gameEvents;

void mainMenu();

int main()
{
	//Player *p = new Player();
	srand((unsigned int)time(0));
	global.titleScreen();
	system("PAUSE");
	global.clearScreen();
	mainMenu();
	return 0;
}


void mainMenu()
{
	int choice;

	cout << endl << "S P A C E  C A T S" << endl;
	cout << endl << "You may:" << endl;
	cout << endl << "1. Start the journey!" << endl;
	cout << "2. Developer Testing!" << endl;
	cout << "3. Learn about the story!" << endl;
	cout << "4. Quit Game!" << endl; 


	do
	{
		cout << endl << "What is your choice?" << endl;
		cin >> choice;

		if (choice == 0 || choice >= 5)
			cout << "That's not an option. Try again." << endl;

	} while (choice == 0 || choice >= 5);

	global.clearScreen();


	switch (choice)
	{
	case 1:
		game.startGame();
		global.pressToGoBack(); 
		break;

	case 2:
		dev.devTest();
		global.pressToGoBack(); 
		break;

	case 3:
		global.gameDescription();
		break;

	case 4:
		exit(0);
		break;
	}
}
