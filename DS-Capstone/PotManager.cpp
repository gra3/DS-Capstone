#include "PotManager.h"


PotManager::PotManager(vector<Player>* allPlayersIn, double minToCallIn)
{
	allPlayers = allPlayersIn;
	minCall = minToCallIn;
	srand(time(NULL));
}


PotManager::~PotManager(void)
{
}

void PotManager::makeMainPot()
{
	if(pot.size()>0) cout << "Error: Main pot already exists!!!\n";
	else
	{
		pot.push(Pot());
	}
	for(int i=0;i<allPlayers->size();i++)
	{
		if(allPlayers->at(i).isActive()&&allPlayers->at(i).isStillInRound) pot.top()->addEligiblePlayer(&allPlayers->at(i));
	}
}

void PotManager::makeSidePot()
{
	if(pot.size()==0) cout << "Error: No main pot exists!!!\n";
	else
	{
		pot.push(Pot());
	}
}

void PotManager::setMinCall(double minCallIn)
{
	minCall = minCallIn;
}

void PotManager::call(double ammount)
{
	cout << "Called for $" << ammount << endl;
	if(pot.size()==1) pot.top()->addToPot(ammount);
	else if(pot.size()>1&&pot.top()->ammount==0)
	{
		pot.secondTop()->addToPot(ammount);
	}
	else if(pot.size()>1&&pot.top()->ammount>0)
	{
		pot.top()->addToPot(ammount);
	}
}

void PotManager::raise(double ammount)
{
	cout << "Raised for $" << ammount << endl;
	if(pot.size()==1) pot.top()->addToPot(ammount);
	else if(minCall==0) pot.top()->addToPot(ammount);
	else if(pot.size()>1&&pot.top()->ammount==0)
	{
		pot.top()->addToPot(ammount/2);
		pot.secondTop()->addToPot(ammount/2);
	}
	else if(pot.size()>1&&pot.top()->ammount>0)
	{
		pot.top()->addToPot(ammount);
	}
}

void PotManager::allIn(double ammountIn, int numCalled)
{
	cout << "All in for $" << ammountIn << ". New sidepot added" << endl;
	//Make new sidepot
	makeSidePot();
	
	//Determine if anything needs to be transfered to the new sidepot
	double rmFromPrevPot = 0;
	if(minCall>ammountIn)
	{
		rmFromPrevPot = minCall - ammountIn;
		pot.secondTop()->rmFromPot(rmFromPrevPot*numCalled);
		pot.top()->addToPot(rmFromPrevPot*numCalled);
		pot.secondTop()->addToPot(ammountIn);
	}
	else if(minCall<ammountIn)
	{
		pot.secondTop()->addToPot(ammountIn);
	}
	else if(minCall==ammountIn)
	{
		pot.secondTop()->addToPot(ammountIn);
	}
}

void PotManager::distributePots()
{
	int numPots = pot.size();
	for(int i=numPots;i>0;i--)
	{
		int winningPlayerNumber = rand() % allPlayers->size();
		allPlayers->at(winningPlayerNumber).chipTotal += pot.top()->ammount;
		pot.pop();
	}
}