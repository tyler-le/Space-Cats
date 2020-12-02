#pragma once
#include<iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <vector>
#include <cmath>
#include <fstream>

#include "Player.h"
#include "GameEvents.h"
#include "DeveloperTesting.h"
#include "Game.h"

void mainMenu();

class Global
{
private:

public:
	Global();
	void titleScreen();
	void clearScreen();
	void pressAnyKeyToContinue();
	int randomRoll(int max, int min);
	void gameDescription();
	void pressToGoBack();
	void storyOpening();
	~Global();
};
