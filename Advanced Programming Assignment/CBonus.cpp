#include "CBonus.h"

unsigned const char POUND = 156;

CBonus::CBonus(string nameOfSquare)
{
	mSquareName = nameOfSquare;
}

CBonus::~CBonus()
{
}

// when player lands on bonus square, roll dice and give bonus depending on result
void CBonus::Behaviour(CPlayer& player)
{
	cout << player.GetName() << " lands on " << this->GetSquareName() << " and has " << POUND << player.GetMoney() << endl;
	int roll = player.RollDice();
	if (roll == 1)
	{
		cout << "Find some money. Gain " << POUND << "20" << endl;
		player.SetMoney(player.GetMoney() + 20);
	}
	else if (roll == 2)
	{
		cout << "Win a coding competition. Gain " << POUND << "50" << endl;
		player.SetMoney(player.GetMoney() + 50);
	}
	else if (roll == 3)
	{
		cout << "Receive a rent rebate. Gain " << POUND << "100" << endl;
		player.SetMoney(player.GetMoney() + 100);
	}
	else if (roll == 4)
	{
		cout << "Win the lottery. Gain " << POUND << "150" << endl;
		player.SetMoney(player.GetMoney() + 150);
	}
	else if (roll == 5)
	{
		cout << "Receive a bequest. Gain " << POUND << "200" << endl;
		player.SetMoney(player.GetMoney() + 200);
	}
	else if (roll == 6)
	{
		cout << "It's your birthday. Gain " << POUND << "300" << endl;
		player.SetMoney(player.GetMoney() + 300);
	}
}