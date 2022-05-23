#include "CMonopolyGame.h"

unsigned const char POUND = 156;

// constructor creates new board and players
CMonopolyGame::CMonopolyGame()
{
	cout << "Welcome to Monopol-ish" << endl;
	unique_ptr<CBoard> board = make_unique<CBoard>();
	mpTheBoard = move(board);
	unique_ptr<CPlayer> playerOne = make_unique<CPlayer>("dog");
	mvPlayers.push_back(move(playerOne));
	unique_ptr<CPlayer> playerTwo = make_unique<CPlayer>("car");
	mvPlayers.push_back(move(playerTwo));
	unique_ptr<CPlayer> playerThree = make_unique<CPlayer>("shoe");
	mvPlayers.push_back(move(playerThree));
	unique_ptr<CPlayer> playerFour = make_unique<CPlayer>("hat");
	mvPlayers.push_back(move(playerFour));
}

CMonopolyGame::~CMonopolyGame()
{
}

CPlayer& CMonopolyGame::GetPlayer(int player)
{
	return *mvPlayers.at(player);
}

// takes the players turn, keeps track of their position and handles bankruptcy/mortgaging
void CMonopolyGame::TakeTurn(CPlayer& player, int diceRoll)
{
	if (!player.GetBankrupt())
	{
		cout << player.GetName() << " rolls " << diceRoll << endl;
		int newPosition = player.GetPosition() + diceRoll;
		if (newPosition >= 26) // sets new position if dice roll exceeds board size and does landed on square behaviour
		{
			int newPosition = player.GetPosition() + diceRoll - 26;
			player.SetPosition(newPosition);
			cout << player.GetName() << " passes GO and collects " << POUND << "200" << endl;
			player.SetMoney(player.GetMoney() + 200);
			mpTheBoard->GetSquare(newPosition).Behaviour(player);
		}
		else // just changes position and does landed on square behaviour
		{
			int newPosition = player.GetPosition() + diceRoll;
			player.SetPosition(newPosition);
			mpTheBoard->GetSquare(newPosition).Behaviour(player);
		}

		// bankrutpcy/mortgaging
		if (player.GetMoney() < 0)
		{
			// if player has negative money and value of all unmortgaged properties won't bring them above 0, they become bankrupt
			if (player.GetProperties().size() > 0) 
			{
				int total = 0;
				for (unsigned int i = 0; i < player.GetProperties().size(); i++)
				{
					if (!mpTheBoard->GetSquare(player.GetProperties().at(i)).GetMortgage())
					{
						total += mpTheBoard->GetSquare(player.GetProperties().at(i)).GetCost();
					}
				}

				// player is bankrupt, all properties are freed and available to buy
				if (player.GetMoney() + total < 0)
				{
					cout << player.GetName() << " is bankrupt" << endl;
					player.SetBankrupt(true);
					for (unsigned int i = 0; i < player.GetProperties().size(); i++)
					{
						mpTheBoard->GetSquare(player.GetProperties().at(i)).SetMortgage(false);
						mpTheBoard->GetSquare(player.GetProperties().at(i)).SetOwned(false);
					}
					player.GetProperties().clear();
				}
				// sorts player properties by value, then mortgages from lowest to highest until money is positive
				else
				{
					sort(player.GetProperties().begin(), player.GetProperties().end());
					for (unsigned int i = 0; i < player.GetProperties().size(); i++)
					{
						if (player.GetMoney() > 0)
						{
							break;
						}
						else if (!mpTheBoard->GetSquare(player.GetProperties().at(i)).GetMortgage())
						{
							player.SetMoney(player.GetMoney() + mpTheBoard->GetSquare(player.GetProperties().at(i)).GetCost());
							mpTheBoard->GetSquare(player.GetProperties().at(i)).SetMortgage(true);
							player.SetHasMortgagedProperties(true);
						}
					}
				}
			}
		}
		// deals with unmortgaging, if player money is higher than lowest value mortgaged property,
		// unmortgages properties until next unmortgage would make balance go negative
		else if (player.GetHasMortgagedProperties() && player.GetMoney() > mpTheBoard->GetSquare(player.GetProperties().at(0)).GetCost())
		{
			sort(player.GetProperties().begin(), player.GetProperties().end());
			for (unsigned int i = 0; i < player.GetProperties().size(); i++)
			{
				if (player.GetMoney() < mpTheBoard->GetSquare(player.GetProperties().at(i)).GetCost())
				{
					break;
				}
				else if (mpTheBoard->GetSquare(player.GetProperties().at(i)).GetMortgage())
				{
					player.SetMoney(player.GetMoney() - mpTheBoard->GetSquare(player.GetProperties().at(i)).GetCost());
					mpTheBoard->GetSquare(player.GetProperties().at(i)).SetMortgage(false);
				}
			}
			//check to see if current player has mortgaged properties
			bool doesPlayerHaveMortgages = false;
			for (unsigned int i = 0; i < player.GetProperties().size(); i++)
			{
				if (mpTheBoard->GetSquare(player.GetProperties().at(i)).GetMortgage())
				{
					doesPlayerHaveMortgages = true;
					break;
				}
			}
			if (!doesPlayerHaveMortgages)
			{
				player.SetHasMortgagedProperties(false);
			}
		}
	}

	cout << player.GetName() << " has " << POUND << player.GetMoney() << endl;

	// tracks current player
	if (mCurrentPlayer >= 3)
	{
		mCurrentPlayer = 0;
	}
	else
	{
		mCurrentPlayer++;
	}
}

void CMonopolyGame::SetCurrentPlayer(int newCurrentPlayer)
{
	mCurrentPlayer = newCurrentPlayer;
}

int CMonopolyGame::GetCurrentPlayer()
{
	return mCurrentPlayer;
}

// checks to see if 3 players are bankrupt to end the game
bool CMonopolyGame::WinCondition()
{
	int bankruptPlayers = 0;
	for (unsigned int i = 0; i < mvPlayers.size(); i++)
	{
		if (mvPlayers.at(i)->GetBankrupt())
		{
			bankruptPlayers++;
		}
	}

	if (bankruptPlayers >= 3)
	{
		for (unsigned int i = 0; i < mvPlayers.size(); i++)
		{
			if (!mvPlayers.at(i)->GetBankrupt())
			{
				cout << mvPlayers.at(i)->GetName() << " is the winner!" << endl;
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}


int CMonopolyGame::GetNoOfPlayers()
{
	return mTotalPlayers;
}