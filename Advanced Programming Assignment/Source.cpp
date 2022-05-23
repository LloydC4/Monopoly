#include "CMonopolyGame.h"
using namespace std;

unsigned const char POUND = 156;

int main()
{
	const unique_ptr<CMonopolyGame> game = make_unique<CMonopolyGame>(); // creating game

	const int NO_OF_TURNS = 80;
	for (int i = 0; i < NO_OF_TURNS; i++)
	{
		game->TakeTurn(game->GetPlayer(game->GetCurrentPlayer()), game->GetPlayer(game->GetCurrentPlayer()).RollDice());
	}

	cout << "Game Over" << endl;

	// compares all players and their balance after specified amount of turns to find the winner
	int winner = 0;
	for (int i = 0; i < game->GetNoOfPlayers(); i++)
	{
		cout << game->GetPlayer(i).GetName() << " has " << POUND << game->GetPlayer(i).GetMoney() << endl;
		if (game->GetPlayer(i).GetMoney() > game->GetPlayer(winner).GetMoney())
		{
			winner = i;
		}
	}
	cout << game->GetPlayer(winner).GetName() << " wins." << endl;

	system("pause");
}