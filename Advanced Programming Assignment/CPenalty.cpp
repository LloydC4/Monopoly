#include "CPenalty.h"

unsigned const char POUND = 156;

CPenalty::CPenalty(string nameOfSquare)
{
	mSquareName = nameOfSquare;
}

CPenalty::~CPenalty()
{
}

// when player lands on penalty square, roll dice and give penalty depending on result
void CPenalty::Behaviour(CPlayer& player)
{
	cout << player.GetName() << " lands on " << this->GetSquareName() << endl;
	int roll = player.RollDice();
	if (roll == 1)
	{
		cout << "Buy a coffee in Starbucks. Lose " << POUND << "20" << endl;
		player.SetMoney(player.GetMoney() - 20);
	}
	else if (roll == 2)
	{
		cout << "Pay your broadband bill. Lose " << POUND << "50" << endl;
		player.SetMoney(player.GetMoney() - 50);
	}
	else if (roll == 3)
	{
		cout << "Visit the SU shop for food. Lose " << POUND << "100" << endl;
		player.SetMoney(player.GetMoney() - 100);
	}
	else if (roll == 4)
	{
		cout << "Buy an assignment solution. Lose " << POUND << "150" << endl;
		player.SetMoney(player.GetMoney() - 150);
	}
	else if (roll == 5)
	{
		cout << "Go for a romantic meal. Lose " << POUND << "200" << endl;
		player.SetMoney(player.GetMoney() - 200);
	}
	else if (roll == 6)
	{
		cout << "Pay some university fees. Lose " << POUND << "300" << endl;
		player.SetMoney(player.GetMoney() - 300);
	}
}
