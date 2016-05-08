#include "Player.h"


Player::Player()
{
	playerNumber = -1;
	chipTotal = 0;
	active = false;
	isD = false;
	isBB = false;
	isSB = false;
	isBet = false;
	currentBet = 0;
	lastCurrentBet = 0;
	isStillInRound = false;
	isAllIn = false;
	possibleWinner = false;
	totalPutIntoPot = 0;
	buyInNextRound = false;
	totalWon = 0;
}


Player::~Player(void)
{
}

void Player::getHand()
{

}

void Player::setPlayerNumber(int playerNum)
{
	playerNumber = playerNum;
}

int Player::getPlayerNumber()
{
	return playerNumber;
}

bool Player::isActive()
{
	return active;
}

void Player::setActive()
{
	active = true;
}

void Player::setInactive()
{
	active = false;
}

void Player::buyIn(double ammount)
{
	setActive();
	chipTotal = ammount;
}

bool Player::isDealer()
{
	return isD;
}

void Player::setDealer(bool val)
{
	isD = val;
}

bool Player::isBigBlind()
{
	return isBB;
}

void Player::setBigBlind(bool val)
{
	isBB = val;
}

bool Player::isSmallBlind()
{
	return isSB;
}

void Player::setSmallBlind(bool val)
{
	isSB = val;
}

bool Player::isBetting()
{
	return isBet;
}

void Player::setBetting(bool val)
{
	isBet = val;
}

void Player::addWinnings(double potAmmount)
{
	totalWon += potAmmount;
}

double Player::getWinnings()
{
	return totalWon;
}

Player* Player::findNextActive()
{
	Player* nextActive;
	nextActive = nextPlayer;
	while(!nextActive->isActive())
	{
		nextActive = nextActive->nextPlayer;
	}
	return nextActive;
}

Player* Player::findNextActiveAndInRound()
{
	Player* nextActive;
	nextActive = nextPlayer;
	while(!nextActive->isActive()||!nextActive->isStillInRound||nextActive->isAllIn)
	{
		nextActive = nextActive->nextPlayer;
	}
	return nextActive;
}
