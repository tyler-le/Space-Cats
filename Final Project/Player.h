#pragma once
#include <string>

class Player
{
private:
	std::string name;
	double money;

	int health;
	const int maxHealth = 100;

	int rocketHealth;
	const int maxRocketHealth = 100;

	int Food;
	const int maxFood = 100;

	int fuel;
	const int maxFuel = 100;

public:
	Player();

	Player(std::string);

	//name
	std::string getName();//accessor for name
	void setName(std::string n); //mutator for name

	//money
	double getMoney(); //accessor for money
	void setMoney(double m); //mutator for money


	//health
	int getHealth(); //accessor for health
	void setHealth(int h); //mutator for health
	int getmaxHealth();

	//rocket health
	int getRocketHealth(); //accessor for health
	void setRocketHealth(int h); //mutator for health
	int getmaxRocketHealth();

	//Food
	int getFood(); //accessor for Food
	void setFood(int s); //mutator for Food
	int getmaxFood();

	//fuel
	int getFuel(); //accessor for fuel
	void setFuel(int f); //mutator for fuel
	int getmaxFuel();

	// display status
	void displayStatus();

	//check death
	bool isDead();

	~Player();



};

