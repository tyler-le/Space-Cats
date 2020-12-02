#include "GameEvents.h"
extern Global global;
//extern Player p;
//extern DeveloperTesting dev;


GameEvents::GameEvents()
{
}


GameEvents::~GameEvents()
{
}


void GameEvents::runGameEvent(Player* p) 
{
	int roll;
	roll = global.randomRoll(12, 1); //passes a random numer 1-12 into roll

	switch (roll)
	{
	case 1:
		event1(p);
		break;

	case 2:
		event2(p);
		break;

	case 3:
		event3(p);
		break;

	case 4:
		event4(p);
		break;

	case 5:
		event5(p);
		break;

	case 6:
		event6(p);
		break;

	case 7:
		event7(p);
		break;

	case 8:
		event8(p);
		break;

	case 9:
		event9(p);
		break;

	case 10:
		event10(p);
		break;

	case 11:
		event11(p);
		break;

	case 12:
		event12(p);
		break;
	}
}

void GameEvents::event1(Player* p)
{
	global.clearScreen();
	cout << "Oh no! There is a space dog in sight. What do you want to do, " << p->getName() << "?" << endl;
	cout << endl << "1. Attack it!" << endl;
	cout << "2. Avoid it!" << endl;

	
	cin >> decision;
	checkDecision(decision, 2);

	switch (decision)
	{
	case 1:
		if (global.randomRoll(100, 1) < 50)
		{	
			global.clearScreen();
			cout << "Attacking..." << endl;
			system("PAUSE");
			cout << endl << "The attack was a success! You've defeated the Space Dog." << endl;
			system("PAUSE");
			cout << endl << "You looted the space dog and found $50" << endl;
			p->setMoney(p->getMoney() + 50);
			checkStats(p);
			cout << "You now have: $" << p->getMoney() << endl;
		}
		else
		{
			global.clearScreen();
			cout << "Attacking..." << endl;
			system("PAUSE");
			cout << endl << "The attack was a failure! The Space Dog defeated you. You lost 20 health." << endl;
			p->setHealth(p->getHealth() - 20);
			checkStats(p);
			cout << "Your health is now: " << p->getHealth() << "/" << p->getmaxHealth() << " hp" << endl;
		}
		break;

	case 2:

		if (global.randomRoll(100, 1) < 50)
		{
			global.clearScreen();
			cout << "Avoiding..." << endl;
			system("PAUSE");
			cout << endl << "Nice job, " << p->getName() <<"! You successfully avoided the space dog!" << endl;
		}

		else
		{
			global.clearScreen();
			cout << "Avoiding..." << endl;
			system("PAUSE");
			cout << endl << "Bad luck! The space dog spotted you and has attacked! You lost 25 health." << endl;
			p->setHealth(p->getHealth() - 20);
			checkStats(p);
			cout << "Your health is now: " << p->getHealth() << "/" << p->getmaxHealth() << " hp" << endl;
		}
		break;
	}
}

void GameEvents::event2(Player* p)
{
	global.clearScreen();
	cout << "Your rocket has ran into a large asteroid! What's the decision, " << p->getName() << "?" << endl;
	cout << endl;
	cout << "1. Take it to a space mechanic." << endl;
	cout << "2. Ignore it and risk the chance of more problems." << endl;

	
	cin >> decision;

	checkDecision(decision, 2);

	switch (decision)
	{
	case 1:
		global.clearScreen();
		cout << "Going to space mechanic..." << endl;
		system("PAUSE");
		cout << endl << "You took it to a mechanic and he repaired your rocket!" << endl;
		cout << "You were charged: $100" << endl;
		p->setMoney(p->getMoney() - 100);
		system("PAUSE");
		checkStats(p);
		cout << endl << "You now have: $" << p->getMoney() << endl;
		break;

	case 2:
		if (global.randomRoll(100, 1) < 50)
		{
			global.clearScreen();
			cout << "Ignoring the asteroid..." << endl;
			system("PAUSE");
			cout << endl << "Your rocket is heavily damaged. Your rocket lost 20 health." << endl;
			p->setRocketHealth(p->getRocketHealth() - 20); 
			checkStats(p);
			cout << "Your rocket health is now: " << p->getRocketHealth() << "/" << p->getmaxRocketHealth() << " rocket hp" << endl;
		}

		else
		{
			global.clearScreen();
			cout << "Ignoring the asteroid..." << endl;
			system("PAUSE");

			cout << endl << "Your rocket broke down!" << endl;
			system("PAUSE");
			cout << endl << "You had the space mechanic fix it and he charged you: $200" << endl;
			p->setMoney(p->getMoney() - 200);
			checkStats(p);
			cout << "You now have: $" << p->getMoney() << endl;
		}
		break;
	}
}

void GameEvents::event3(Player* p)
{
	global.clearScreen();
	cout << "Forecasts call for a heavy meteor storm. Rest at the nearest planet or plow through the storm?" << endl;
	cout << endl;
	cout << "1. Rest at the nearest planet." << endl;
	cout << "2. Plow through the storm." << endl;

	
	cin >> decision;
	checkDecision(decision, 2);

	switch (decision)
	{
	case 1:
		if (global.randomRoll(100, 1) < 50)
		{
			global.clearScreen();
			cout << "Resting at the nearest planet..." << endl;
			system("PAUSE");

			cout << endl << "You have entered a planet infested with Space Dogs and they are attacking!" << endl;
			system("PAUSE");

			cout << endl << "The Space Dogs have attacked successfully. You lost 10 health." << endl;

			p->setHealth(p->getHealth() - 10);
			checkStats(p);
			cout << "Your health is now: " << p->getHealth() << "/" << p->getmaxHealth() << " hp" << endl;
		}

		else
		{
			global.clearScreen();
			cout << "Resting at the nearest planet..." << endl;
			system("PAUSE");
			
			cout << endl << "You have successfully rested. You gained 10 health." << endl;
			p->setHealth(p->getHealth() + 10);
			checkStats(p);
			cout << "Your health is now: " << p->getHealth() << "/" << p->getmaxHealth() << " hp" << endl;
		}
		break;

	case 2: 
		if (global.randomRoll(100, 1) < 50)
		{
			global.clearScreen();
			cout << "Plowing through the storm..." << endl;
			system("PAUSE");

			cout << endl << "A meteor has hit a hole in your rocket, " << p->getName() << "!" << endl;

			system("PAUSE");

			cout << endl << "Some of your food flew out of the hole. You lost 10 pounds of food." << endl;
			p->setFood(p->getFood() - 10);
			checkStats(p);
			cout << "You now have: " << p->getFood() << "/" << p->getmaxFood() << " pounds of food left." << endl;

			system("PAUSE");

			cout << endl << "Your rocket has been severely weakened. You lost 20 rocket health." << endl;
			p->setRocketHealth(p->getRocketHealth() - 20); 
			checkStats(p);
			cout << "Your rocket health is now: " << p->getRocketHealth() << "/" << p->getmaxRocketHealth() << " rocket hp" << endl;
		}

		else
		{
			global.clearScreen();
			cout << "Plowing through the storm..." << endl;
			system("PAUSE");
			
			cout << endl << "You have successfully navigated through the meteor storm. Nice job!" << endl;
		}
		break;
	}
}

void GameEvents::event4(Player* p)
{
	global.clearScreen();
	cout << "You stumble upon a mythical creature that only asks you, left or right. What do you do?" << endl;
	cout << endl;

	cout << "1. Go left." << endl;
	cout << "2. Go right." << endl;
	cout << "3. Ignore him." << endl;

	
	cin >> decision;

	checkDecision(decision, 3);

	switch (decision)
	{
	case 1:
		if (global.randomRoll(100, 1) < 50)
		{
			global.clearScreen();
			cout << "Going left..." << endl;
			system("PAUSE");

			cout << endl << "IT'S A TRAP! IT'S A TRAP!! A gang of Space Dogs were waiting for you." << endl;
			system("PAUSE");

			cout << endl << "The Space Dogs have looted you! They stole $100." << endl;
			p->setMoney(p->getMoney() - 100);
			checkStats(p);
			cout << "You now have: $" << p->getMoney() << endl;
		}
		else
		{
			global.clearScreen();
			cout << "Going left..." << endl;
			system("PAUSE");

			cout << endl << "The mythical creature has led you to an area of fortunes! Explore it." << endl;
			system("PAUSE");
\
			cout << endl << "You loot a total of $100 in treasures." << endl;
			p->setMoney(p->getMoney() + 100);
			checkStats(p);
			cout << "You now have: $" << p->getMoney() << endl;
		}
		break;

	case 2:
		if (global.randomRoll(100, 1) < 50)
		{
			global.clearScreen();
			cout << "Going right..." << endl;
			system("PAUSE");

			cout << endl << "IT'S A TRAP! IT'S A TRAP!! A gang of Space Dogs were waiting for you." << endl;
			system("PAUSE");

			cout << endl << "The Space Dogs have looted you! They stole $100." << endl;
			p->setMoney(p->getMoney() - 100);
			checkStats(p);
			cout << "You now have: $" << p->getMoney() << endl;
		}
		else
		{
			global.clearScreen();
			cout << "Going right..." << endl;
			system("PAUSE");
	
			cout << endl << "The mythical creature has led you to an area of fortunes! Explore it." << endl;
			system("PAUSE");
		
			cout << endl << "You loot a total of $100 in treasures." << endl;
			p->setMoney(p->getMoney() + 100);
			checkStats(p);
			cout << "You now have: $" << p->getMoney() << endl;
		}
		break;

	case 3:
		if (global.randomRoll(100, 1) < 50)
		{
			global.clearScreen();
			cout << "Ignoring the mythical creature..." << endl;
			system("PAUSE");

			cout << endl << "You encounter a wall of space rocks." << endl;
			cout << "You must turn back and go around." << endl;
			system("PAUSE");

			cout << endl << "Because you turned back, you lost 10 gallons of fuel." << endl;
			p->setFuel(p->getFuel() - 10);
			checkStats(p);

			system("PAUSE");
	
			cout << endl << "You now have: " << p->getFuel() << "/" << p->getmaxFuel() << " gallons of fuel." << endl;
		}
		else
		{
			global.clearScreen();
			cout << "Ignoring the mythical creature..." << endl;
			system("PAUSE");
	
			cout << endl << "Impressive! You saw through his plan of trying to hide the secret fortunes!" << endl;
			system("PAUSE");
			
			cout << endl << "You loot it and find $100." << endl;
			p->setMoney(p->getMoney() + 100);
			cout << "You now have: $" << p->getMoney() << endl;

		}
		break;
	}
}

void GameEvents::event5(Player* p)
{
	global.clearScreen();
	cout << "You passed a planet, would you like to explore?" << endl;
	cout << endl;
	cout << "1. Yes." << endl;
	cout << "2. No." << endl;

	
	cin >> decision;
	checkDecision(decision, 2);

	switch (decision)
	{
	case 1:
		if (global.randomRoll(100, 1) < 50)
		{
			global.clearScreen();
			cout << "Exploring..." << endl;
			system("PAUSE");
			
			cout << endl << "Great decision, " << p->getName() << "!" << endl;
			cout << "You found treasure and sold it for $200!" << endl;
			p->setMoney(p->getMoney() + 200);
			cout << endl << "You now have: $" << p->getMoney() << endl;
		}

		else
		{
			global.clearScreen();
			cout << "Exploring..." << endl;
			system("PAUSE");
		
			cout << endl << "While you were out exploring... Space Dogs raided your rocket. You lost 15 pounds of food." << endl;
			p->setFood(p->getFood() - 15);
			checkStats(p);
			cout << endl << "You now have: " << p->getFood() << "/" << p->getmaxFood() << " pounds of food left." << endl; 
		}

		break;

	case 2:
		if (global.randomRoll(100, 1) < 50)
		{
			global.clearScreen();
			cout << "Continuing..." << endl;
			system("PAUSE");
			
			cout << endl << "Instead of exploring, you decided to rest. You gain 10 hp" << endl;
			p->setHealth(p->getHealth() + 10);
			checkStats(p);
			cout << endl << "Your health is now: " << p->getHealth() << "/" << p->getmaxHealth() << endl;
		}

		else
		{
			global.clearScreen();
			cout << "Continuing..." << endl;
			system("PAUSE");
		
			cout << endl << "As you pass, you notice the entire planet is gold plated. You also realize that those weren't mountains." << endl;
			system("PAUSE");

			cout << endl << "They were piles of gold." << endl;
		}
		break;
	}
}

void GameEvents::event6(Player* p)
{
	global.clearScreen();
	cout << "A pack Space Dogs have surrounded you. Fight or bribe them off?" << endl;
	cout << endl;
	cout << "1. Fight" << endl;
	cout << "2. Bribe" << endl;

	
	cin >> decision;
	checkDecision(decision, 2);

	switch (decision)
	{
	case 1:
		if (global.randomRoll(100, 1) < 50)
		{
			global.clearScreen();
			cout << "Fighting..." << endl;
			system("PAUSE");
			global.clearScreen();
			cout << "Nice job! You've successfully fought them off and raided their camp-> " << endl;
			system("PAUSE");

			cout << endl << "You found 15 pounds of food." << endl;
			p->setFood(p->getFood() + 15);
			checkStats(p);
			cout << endl;
			cout << "You now have: " << p->getFood() << " pounds of food." << endl;
		}

		else
		{
			global.clearScreen();
			cout << "Fighting..." << endl;
			system("PAUSE");
			global.clearScreen();
			cout << "Poor luck! You've failed to fight off the Space Dogs. " << endl;
			system("PAUSE");
			cout << endl;
			cout << "You lost 20 hp." << endl;
			p->setHealth(p->getHealth() - 20);
			checkStats(p);
			cout << endl;
			cout << "You now have: " << p->getHealth() << " hp." << endl;
		}
		break;
	case 2:
		global.clearScreen();
		cout << "Bribing..." << endl;
		system("PAUSE");
		global.clearScreen();
		cout << "You guys struck a deal for $200. " << endl;
		system("PAUSE");

		p->setMoney(p->getMoney() - 200);
		checkStats(p);
		cout << endl << "You now have: $" << p->getMoney() << endl;
		
		break;

	}

}

void GameEvents::event7(Player* p)
{
	global.clearScreen();
	cout << "You've been pulled over by the Space Police. Pull over?" << endl;
	cout << endl;

	cout << "1. Fly away" << endl;
	cout << "2. Pull over." << endl;
	
	cin >> decision;
	checkDecision(decision, 2);

	switch (decision)
	{
	case 1:
		if (global.randomRoll(100, 1) < 50)
		{
			global.clearScreen();
			cout << "Flying away..." << endl;
			system("PAUSE");
			
			cout << endl << "You've successfully evaded the police but you hit some meteors during the process." << endl;
			system("PAUSE");
			
			cout << endl << "Your rocket lost 15 health." << endl;
			p->setRocketHealth(p->getRocketHealth() - 15);
			checkStats(p);
			cout << "You now have " << p->getRocketHealth() << " rocket hp." << endl;
		}
		else
		{
			global.clearScreen();
			cout << "Flying away..." << endl;
			system("PAUSE");
			
			cout << endl << "You've failed to evaded the police. You must pay $200 to get out of jail." << endl;
			system("PAUSE");
			
			cout << endl << "You paid $200." << endl;
			p->setMoney(p->getMoney() - 200);
			checkStats(p);
			cout << endl << "You now have $" << p->getMoney() << "." << endl;
		}
		break;

	case 2:
		if (global.randomRoll(100, 1) < 50)
		{
			global.clearScreen();
			cout << "Pulling over..." << endl;
			system("PAUSE");
			
			cout << endl << "The Space Cop gave you a speeding ticket." << endl;
			system("PAUSE");
			
			cout << endl << "The ticket was $150." << endl;
			p->setMoney(p->getMoney() - 150);
			checkStats(p);
			cout << endl << "You now have: $" << p->getMoney() << endl;
		}
		else
		{
			global.clearScreen();
			cout << "Pulling over..." << endl;
			system("PAUSE");
			
			cout << endl << "He tells you that he's a big fan of your Space Adventure blog. He wants to donate money to you as help for your travels." << endl;
			system("PAUSE");
			
			cout << endl << "He gives you $75" << endl;
			p->setMoney(p->getMoney() + 75);
			checkStats(p);
			cout << endl << "You now have: $" << p->getMoney() << endl;
		}
		break;
	}
}

void GameEvents::event8(Player* p)
{
	global.clearScreen();
	cout << "You have a nasty case of the wretched Hairball. Do you want to visit a doctor?" << endl;
	cout << endl;
	cout << "1. Visit a doctor." << endl;
	cout << "2. Deal with the hairballs." << endl;


	
	cin >> decision;
	checkDecision(decision, 2);

	switch (decision)
	{
	case 1:
		global.clearScreen();
		cout << "Visiting doctor..." << endl;
		system("PAUSE");
		
		cout << endl << "The doctor cured you. You are fine but the bill was $150." << endl;
		p->setMoney(p->getMoney() - 150);
		checkStats(p);
		cout << endl << "You now have: $" << p->getMoney() << endl;

		break;

	case 2:


		if (global.randomRoll(100, 1) > 50)
		{
			global.clearScreen();
			cout << "You chose to deal with the hairball..." << endl;
			system("PAUSE");

			cout << endl << "You coughed up an enormous hairball! You lost 10 hp" << endl;
			system("PAUSE");

			p->setHealth(p->getHealth() - 10);
			checkStats(p);
			cout << endl << "You now have: " << p->getHealth() << " hp." << endl;
		}

		else
		{
			global.clearScreen();
			cout << "You chose to deal with the hairball..." << endl;
			system("PAUSE");
		
			cout << endl << "All is fine! You dealth with the hairball sickness and are ready to continue your mission." << endl;
		}
		break;
	}
}

void GameEvents::event9(Player* p)
{
	global.clearScreen();
	cout << "Enemy space rocket sighted!" << endl;
	cout << endl;
	cout << "1. Attack." << endl;
	cout << "2. Flee." << endl;

	
	cin >> decision;
	checkDecision(decision, 2);

	switch (decision)
	{
	case 1:
		if (global.randomRoll(100, 1) > 50)
		{
			global.clearScreen();
			cout << "Attacking..." << endl;
			system("PAUSE");

			cout << endl << "Attack successful!" << endl;
			system("PAUSE");

			cout << endl << "You took one of their crew members hostage and sold him for $50." << endl;

			p->setMoney(p->getMoney() + 50);
			cout <<endl<< "You now have: $" << p->getMoney() << endl;
		}
		else
		{
			global.clearScreen();
			cout << "Attacking..." << endl;
			system("PAUSE");

			cout << endl << "Attack unsuccessful!" << endl;
			system("PAUSE");
			cout << endl << "You lost 15 rocket hp during the battle." << endl;
			p->setRocketHealth(p->getRocketHealth() - 15);
			checkStats(p);
			cout << endl << "You now have: " << p->getHealth() << " hp." << endl;
		}
		break;

	case 2:
		if (global.randomRoll(100, 1) > 50)
		{
			global.clearScreen();
			cout << "Attempting to flee the enemy rocket..." << endl;
			system("PAUSE");

			cout << endl << "You've successfully fleed the enemy rocket but burned up a lot of fuel in the process." << endl;
			system("PAUSE");

			cout << endl << "You lost 15 gallons of fuel." << endl;
			p->setFuel(p->getFuel() - 15);
			checkStats(p);
			cout << endl << "You now have " << p->getFuel() << " gallons of fuel." << endl;
		}

		else
		{
			global.clearScreen();
			cout << "Attempting to flee the enemy rocket..." << endl;
			system("PAUSE");

			cout << endl << "The enemy space rocket has caught up to you." << endl;
			system("PAUSE");

			cout << endl << "They heavily damage your rocket." << endl;
			cout << endl << "You lost 25 rocket hp" << endl;
			p->setRocketHealth(p->getRocketHealth() - 25);
			checkStats(p);
			cout << endl << "You now have: " << p->getRocketHealth() << " rocket hp." << endl;
		}
		break;

	}
}


void GameEvents::event10(Player* p)
{
	global.clearScreen();
	cout << "You found a rat in your food!" << endl;
	cout << endl;
	cout << "1. Continue eating!" << endl;
	cout << "2. Throw out some of your food!" << endl;

	
	cin >> decision;
	checkDecision(decision, 2);

	switch (decision)
	{
	case 1:
		if (global.randomRoll(100, 1) > 50)
		{
			global.clearScreen();
			cout << "Continuing to eat..." << endl;
			system("PAUSE");

			cout << endl << "You got very sick. Your food was contaminated" << endl;
			system("PAUSE");

			cout << endl << "You lost 20 health." << endl;

			p->setHealth(p->getHealth() - 20);
			checkStats(p);
			cout << endl << "You now have " << p->getHealth() << " hp." << endl;
		}
		else
		{
			global.clearScreen();
			cout << "Continuing to eat..." << endl;
			system("PAUSE");

			cout << endl << "You love rats but haven't had one since your mission!" << endl;
			system("PAUSE");

			cout << endl << "You eat the rat. The extra protein gives you an extra 5 health." << endl;
			p->setHealth(p->getHealth() + 5);
			checkStats(p);
			cout << endl << "You now have " << p->getHealth() << " hp." << endl;
		}
		break;

	case 2:
		global.clearScreen();
		cout << "Throwing out some of your food..." << endl;
		system("PAUSE");

		cout << endl << "You threw out half of your food until the signs of rats was no more." << endl;
		system("PAUSE");

		cout << endl << "You lost " << (p->getFood() / 2) << " pounds of food." << endl;
		p->setFood((p->getFood() / 2));
		checkStats(p);
		cout << endl << "You now have " << p->getFood() << " pounds of food." << endl;
		
		break;

	}

}

void GameEvents::event11(Player* p)
{
	global.clearScreen();
	cout << "You are about to cross paths with an unknown spaceship-> Keep going or turn away?" << endl;
	cout << endl;
	cout << "1. Keep going." << endl;
	cout << "2. Turn away." << endl;

	
	cin >> decision;
	checkDecision(decision, 2);

	switch (decision)
	{
	case 1:
		if (global.randomRoll(100, 1) > 50)
		{
			global.clearScreen();
			cout << "Continuing..." << endl;
			system("PAUSE");

			cout << endl << "They are just a friendly traveler. " << endl;
			system("PAUSE");

			cout << endl << "They want to give you 10 pounds of food from their planet." << endl;

			cout << endl << "You take their food and thank them." << endl;

			p->setFood(p->getFood() + 10);
			checkStats(p);
			cout << endl << "You now have " << p->getFood() << " pounds of food" << endl;
		}
		else
		{
			global.clearScreen();
			cout << "Continuing..." << endl;
			system("PAUSE");

			cout << endl << "They are enemy travelers! " << endl;
			system("PAUSE");

			cout << endl << "The unknown species attacks your ship!" << endl;
			system("PAUSE");

			cout << endl << "You lose 15 rocket hp." << endl;

			p->setRocketHealth(p->getRocketHealth() -15);
			checkStats(p);
			cout << endl << "You now have " << p->getRocketHealth() << " rocket hp." << endl;
		}
		break;

	case 2:
		if (global.randomRoll(100, 1) > 50)
		{
			global.clearScreen();
			cout << "Turning away..." << endl;
			system("PAUSE");

			cout << endl << "Successfully avoided the unknown ship!" << endl;
			system("PAUSE");

			cout << endl << "Due to your inconvenient rerouting, you lost 15 gallons of fuel." << endl;
			p->setFuel(p->getFuel() - 15);
			checkStats(p);
			cout << endl << "You now have " << p->getFuel() << " gallons of fuel." << endl;
		}

		else
		{
			global.clearScreen();
			cout << "Turning away..." << endl;
			system("PAUSE");

			cout << endl << "Evasion unsuccessful!" << endl;
			system("PAUSE");

			cout << endl << "The unknown ship has caught up to you and are attacking." << endl;
			system("PAUSE");

			cout << endl << "You lose 20 rocket hp" << endl;
			p->setRocketHealth(p->getRocketHealth() - 20);
			checkStats(p);
			cout << endl << "You now have: " << p->getRocketHealth() << " rocket hp." << endl;
		}
		break;

	}
}

void GameEvents::event12(Player* p)
{
	global.clearScreen();
	cout << "You found an abandoned space port. Would you like to explore?" << endl;
	cout << endl;
	cout << "1. Explore." << endl;
	cout << "2. Ignore." << endl;

	
	cin >> decision;
	checkDecision(decision, 2);

	switch (decision)
	{
	case 1:
		if (global.randomRoll(100, 1) > 50)
		{
			global.clearScreen();
			cout << "Exploring..." << endl;
			system("PAUSE");


			cout << endl << "You found a hidden treasure! You open it. " << endl;
			system("PAUSE");

			cout << endl << "Inside the treasure, you find $100." << endl;

			p->setMoney(p->getMoney() + 100);
			cout << endl << "You now have $" << p->getMoney() << "." << endl;
		}
		else
		{
			global.clearScreen();
			cout << "Exploring..." << endl;
			system("PAUSE");

			cout << endl << "There is a gang of enemy Space Dogs here! " << endl;
			system("PAUSE");

			cout << endl << "They chase you down and attack!" << endl;
			system("PAUSE");

			cout << endl << "You lose 15 hp." << endl;

			p->setHealth(p->getHealth() - 15);
			checkStats(p);
			cout << endl << "You now have " << p->getHealth() << " hp." << endl;
		}
		break;

	case 2:
		if (global.randomRoll(100, 1) > 50)
		{
			global.clearScreen();
			cout << "Ignoring..." << endl;
			system("PAUSE");

			cout << endl << "Nice job! The space port was a dealdly area to be in." << endl;
			system("PAUSE");

			cout << endl << "You've successfully evaded death. You gain 5 hp." << endl;
			p->setHealth(p->getHealth() + 5);
			checkStats(p);
			cout << endl << "You now have " << p->getHealth() << " hp." << endl;
		}

		else
		{
			global.clearScreen();
			cout << "Ignoring..." << endl;
			system("PAUSE");

			cout << endl << "The space port was a land of riches!" << endl;
			system("PAUSE");

			cout << endl << "You missed out on your chances of striking rich." << endl;
			system("PAUSE");
		}
		break;

	}
}

void GameEvents::checkDecision(int decision, int max) //event4 has 3 options but the rest have 2
{
	while (decision > max)
	{
		cout << "Invalid input. Try again." << endl;
		cin >> decision;
		cin.clear();
	}
}

void GameEvents::checkStats(Player* p) //this is to check if stats go under 0 or over max, this will fix that.
{
	if (p->getMoney() < 0)
	{
		p->setMoney(0);
	}


	if (p->getHealth() < 0)
	{
		p->setHealth(0);
	}
	if (p->getHealth() > p->getmaxHealth())
	{
		p->setHealth(p->getmaxHealth());
	}


	if (p->getFood() < 0)
	{
		p->setFood(0);
	}
	if (p->getFood() > p->getmaxFood())
	{
		p->setFood(p->getmaxFood());
	}


	if (p->getFuel() < 0)
	{
		p->setFuel(0);
	}
	if (p->getFuel() > p->getmaxFuel())
	{
		p->setFuel(p->getmaxFuel());
	}


	if (p->getRocketHealth() < 0)
	{
		p->setRocketHealth(0);
	}
	if (p->getRocketHealth() > p->getmaxRocketHealth())
	{
		p->setRocketHealth(p->getmaxRocketHealth());
	}
}

