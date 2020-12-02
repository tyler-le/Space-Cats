#pragma once
#include "Global.h"


class Game
{
private:
	static const int numOfItems = 4;
	static const int numOfShopPrices = 4;
	static const int numOfDest = 12;

	const std::string shopItems[numOfItems] = { "Armor (+1 hp)", "Fuel (+1 gal)","Food (+1 lb)", "Rocket Armor (+1 hp)" };
	const int shopPrices[numOfShopPrices] = { 10,5,5, 10 };
	const std::string destination[numOfDest] = { "Vogsphere","Coruscant","Worlorn","Krypton","Dagobah","Gallifrey","Annares","Nasqueron","Ego","Arrakis","Solaris","Terra Prime" };

public:
	Game();
	void startGame();
	bool isDead(Player* p);
	void playerSetup(Player* p);
	void supplies(Player* p);
	void printShop();
	bool buyItems(Player* p);
	void buyArmor(Player* p);
	void buyFuel(Player* p);
	void buyFood(Player* p);
	void buyRocketArmor(Player* p);
	void endStoryWin(Player* p);
	void endStoryLose(Player* p);
	~Game();
};

