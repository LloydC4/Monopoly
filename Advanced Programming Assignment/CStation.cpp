#include "CStation.h"

unsigned const char POUND = 156;

CStation::CStation(string nameOfSquare)
{
	mSquareName = nameOfSquare;
	mCost = 200;
}

CStation::~CStation()
{
}

// if station is not owned and player has money, player buys it
// if station is owned, player pays owner appropriate rent
void CStation::Behaviour(CPlayer& player)
{
	cout << player.GetName() << " lands on " << this->GetSquareName() << endl;
	if (mOwned)
	{
		if (this->GetOwner()->GetName() != player.GetName())
		{
				cout << player.GetName() << " pays " << POUND << "10" << endl;
				player.SetMoney(player.GetMoney() - 10);
				this->GetOwner()->SetMoney(this->GetOwner()->GetMoney() + 10);
		}
	}
	else
	{
		if (player.GetMoney() > 0)
		{
			cout << player.GetName() << " buys " << this->GetSquareName() << " for " << POUND << "200" << endl;;
			player.SetMoney(player.GetMoney() - 200);
			this->mOwned = true;
			this->SetOwner(&player);
		}
	}
}
