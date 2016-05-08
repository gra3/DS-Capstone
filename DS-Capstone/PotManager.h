#pragma once
#include "Pot.h"
#include "Top2Stack.h"
#include <time.h>

class PotManager
{
public:
	PotManager(vector<Player>* allPlayersIn,double minToCallIn);
	~PotManager(void);

	vector<Player>* allPlayers;
	Top2Stack<Pot> pot;
	double minCall;

	void setMinCall(double minCallIn);
	void makeMainPot();
	void makeSidePot();
	void allIn(double ammountIn, int numCalled);
	void call(double ammount);
	void raise(double ammount);
	void distributePots();
};

