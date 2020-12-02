#include "Global.h"
using namespace std;

Global::Global()
{
}

void Global::titleScreen()
{
	std::cout << "__________" << std::endl;
	std::cout << std::endl << "SPACE CATS" << std::endl;
	std::cout << "__________" << std::endl;
	cout << endl;
}

void Global::clearScreen()
{
	system("CLS");
	std::cin.clear();
}

void Global::pressAnyKeyToContinue()
{
	std::cin.ignore(1000, '\n');
	std::cout << std::endl << "--Press enter to continue--" << std::endl;
	std::cin.get();
	std::cin.clear();
}


int Global::randomRoll(int max, int min)
{
	int randNum = 0;
	randNum = min + rand() % (max - min);
	return randNum; 
}


void Global::gameDescription()
{
	std::cout << "You are part of a nearly extinct species, the Space Cat." << std::endl;
	std::cout << "You will be traveling on a solo mission to defend your existence." << std::endl;
	std::cout << "Your goal is to withstand 12 rounds of critical decision making and make it to your desired planet, Terra Prime." << std::endl;
	std::cout << "If you do run out, you lose the game and the last of your kind will perish." << std::endl;
	std::cout << "If you do manage to survive, you will save your kind and live on as a hero." << std::endl;
	std::cout << std::endl << "Created by: Tyler Le" << std::endl;
	pressToGoBack();

}

void Global::pressToGoBack()
{
	int goBack;
	std::cout << std::endl << "--Press 0 to go back--" << std::endl;
	std::cin >> goBack;

	do
	{
		if (goBack == 0)
		{
			clearScreen();
			mainMenu();
		}

		else
		{
			std::cout << "Input invalid! Please try again." << std::endl;
			std::cin.clear();
			std::cin >> goBack;
		}

	} while (true);
}

void Global::storyOpening()
{

	cout << "Hello Captain! Thank you for joining us on this spectacular journey through space." << endl;
	system("PAUSE");
	clearScreen();

	cout << "You are in the year 3005 and will be pioneering on a solo mission to reach a new home planet, Terra Prime." << endl;
	system("PAUSE");
	clearScreen();

	cout << "Many obstacles will impede your mission, such as meteor showers, complications with your rocket, and most" << endl;
	cout << "importantly, Space Dogs." << endl;
	system("PAUSE");
	clearScreen();

	cout << "It is up to you to save the rest of us, no matter the cost." << endl;
	cout << "The choice is yours." << endl << endl;
	
	system("PAUSE");
	clearScreen();

	char choice = ' ';
	while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N')
	{
		cout << "Continue? (Y/N)" << endl;
		cin >> choice;
		if (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N')
		{
			cout << "Oops! Invalid input. Try again!" << endl;
		}
	}
	if (choice == 'n' || choice == 'N')
	{
		exit(0);
	}
}



Global::~Global()
{
}




