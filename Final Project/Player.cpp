#include "Player.h"
#include <iostream>


Player::Player()
{
	name = "";
	money = 1000.00;

	const int maxHealth = 100;
	health = 50;

	const int maxFood = 100;
	Food = 50;

	const int maxFuel = 100;
	fuel = 50;

	const int maxRocketHealth = 100;
	rocketHealth = 50;

}


//name
Player::Player(std::string n)
{
	name = n;
}
std::string Player::getName()
{
	return name;
}
void Player::setName(std::string n)
{
	name = n;
}


//money
double Player::getMoney()
{
	return money;
}
void Player::setMoney(double m)
{
	money = m;
}


//health
int Player::getHealth()
{
	return health;
}
void Player::setHealth(int h)
{
	health = h;
}

int Player::getmaxHealth()
{
	return maxHealth;
}


//rocket health
int Player::getRocketHealth()
{
	return rocketHealth;
}

void Player::setRocketHealth(int r)
{
	rocketHealth = r;
}

int Player::getmaxRocketHealth()
{
	return maxRocketHealth;
}


//Food
int Player::getFood()
{
	return Food;
}

void Player::setFood(int s)
{
	Food = s;
}

int Player::getmaxFood()
{
	return maxFood;
}


//fuel
int Player::getFuel()
{
	return fuel;
}

void Player::setFuel(int f)
{
	fuel = f;
}

int Player::getmaxFuel()
{
	return maxFuel;
}


void Player::displayStatus()
{
	std::cout << "You currently have: " << std::endl << std::endl;
	std::cout << "Money: $" << getMoney() << std::endl;
	std::cout << "Armor: " << getHealth() << " / " << getmaxHealth() << " hp." << std::endl;
	std::cout << "Fuel: " << getFuel() << " / " << getmaxFuel() << " gallons." << std::endl;
	std::cout << "Food: " << getFood() << " / " << getmaxFood() << " pounds of food." << std::endl;
	std::cout << "Rocket Armor: " << getRocketHealth() << " / " << getmaxRocketHealth() << " rocket hp." << std::endl;
}

bool Player::isDead()
{
	if (getHealth() <= 0 || getFuel() <= 0 || getFood() <= 0)
	{
		return false; //this means you're dead
	}

	else
	{
		return true;
	}
}

//destructor
Player::~Player()
{

}
