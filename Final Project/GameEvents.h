#pragma once
#include "Global.h"
using namespace std;


class GameEvents
{
private:
	int decision;
public:
	GameEvents();
	~GameEvents();
	void runGameEvent(Player* p);
	void event1(Player* p);
	void event2(Player* p);
	void event3(Player* p);
	void event4(Player* p);
	void event5(Player* p);
	void event6(Player* p);
	void event7(Player* p);
	void event8(Player* p);
	void event9(Player* p);
	void event10(Player* p);
	void event11(Player* p);
	void event12(Player* p);
	void checkDecision(int decision, int max);
	void checkStats(Player* p);
};

