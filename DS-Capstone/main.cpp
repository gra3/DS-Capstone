#include <iostream>
#include "Top2Stack.h"
#include "Pot.h"
#include "PotManager.h"
#include "Player.h"
#include <vector>
#include <Windows.h>

using namespace std;

int main(int argc, char* argv[])
{
	/////////////////////////////////////////////// First Round /////////////////////////////////////////////


	//Create 4 players and put them in a vector
	Player p1,p2,p3,p4;
	vector<Player> players;
	players.push_back(p1);
	players.push_back(p2);
	players.push_back(p3);
	players.push_back(p4);

	//Create PotManager
	PotManager potManager(&players, 0.5);
	potManager.makeMainPot();

	cout << "FIRST ROUND EXAMPLE\n";

	//P1
	potManager.call(0.5);

	//P2 - Done for round
	potManager.allIn(5,1);
	potManager.setMinCall(5);

	//P3
	potManager.call(5);

	//P4
	potManager.raise(10);
	potManager.setMinCall(10);

	//P1 -Done for round
	potManager.allIn(7.5,3);

	//P3
	potManager.call(5);

	potManager.distributePots();

	for(int i=0;i<players.size();i++)
	{
		cout << "Player chipTotal: " << players[i].chipTotal << endl;
	}
	cout << "\n\n";

	/////////////////////////////////////////////// Second Round /////////////////////////////////////////////
	
	//Clear player chip totals
	for(int i=0;i<players.size();i++) players[i].chipTotal = 0;

	//Make another PotManager for this example
	PotManager pm2(&players,0.5);
	pm2.makeMainPot();

		cout << "SECOND ROUND EXAMPLE\n";

	//P1 
	pm2.raise(5);

	//P2
	pm2.call(5);

	//P3
	pm2.raise(10);

	//P4 - Done for round
	pm2.allIn(5,1);

	//P1
	pm2.call(5);

	//P2
	pm2.raise(15);

	//P3 - Done for round
	pm2.allIn(2.25,1);

	//P1
	pm2.call(10);

	pm2.distributePots();

	for(int i=0;i<players.size();i++)
	{
		cout << "Player chipTotal: " << players[i].chipTotal << endl;
	}

	Sleep(15000);
}
