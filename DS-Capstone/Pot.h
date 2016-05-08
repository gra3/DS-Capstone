#pragma once
#include "Player.h"
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Pot
{
public:
	Pot();
	~Pot(void);

	double ammount;
	string name;
	vector<Player*> ableToWin;
	vector<Player*> winners;
	vector<Player> sorted;
	void addToPot(double ammountIn);
	void rmFromPot(double ammountIn);
	void printPot();
	void addEligiblePlayer(Player* playerIn);
	bool rmEligiblePlayer(int playerNum);
	void sortPokerHands();
	void distributePot();
	void reset();
};

