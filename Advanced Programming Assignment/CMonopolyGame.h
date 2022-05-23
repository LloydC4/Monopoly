#pragma once
#include "CDice.h"
#include "CBoard.h"
#include <algorithm>
typedef vector<unique_ptr<CPlayer>> CPlayerVector;

class CMonopolyGame
{
public:
	CMonopolyGame(); // constructor
	~CMonopolyGame(); // destructor
	CPlayer& GetPlayer(int player);
	void TakeTurn(CPlayer& currentPlayer, int diceRoll); // performs the current players turn
	void SetCurrentPlayer(int newCurrentPlayer); // sets current player
	int GetCurrentPlayer(); // returns current player
	bool WinCondition(); // checks every turn to see if game is over
	int GetNoOfPlayers(); // returns max no of players

private:
	unique_ptr<CBoard> mpTheBoard; // stores all square details
	CPlayerVector mvPlayers; // stores players
	int mCurrentPlayer = 0; // stores current player number
	int mTotalPlayers = 4; // max no of players
};

