#include "CProperty.h"

unsigned const char POUND = 156;

CProperty::CProperty(string nameOfSquare, int squareCost, int squareRent, int squareColourGroup)
{
	mSquareName = nameOfSquare;
	mCost = squareCost;
	mRent = squareRent;
	mColourGroup = squareColourGroup;
}

CProperty::~CProperty()
{
}

// if player lands on property and it's not owned, player buys property if he has the money
// if player lands and property and it is owned, player pays appropriate rent to owner, rent is doubled if owner owns entire colour group
// no rent if property is mortgaged
void CProperty::Behaviour(CPlayer& player)
{
	cout << player.GetName() << " lands on " << this->GetSquareName() << endl;
	if (mOwned)
	{
		if (this->GetOwner()->GetName() != player.GetName() && !this->GetOwner()->GetBankrupt() && !this->GetMortgage())
		{
			if (this->GetOwner()->DoesPlayerOwnColourGroup(this->mColourGroup))
			{
				cout << player.GetName() << " pays " << POUND << this->GetRent() * 2 << endl;
				player.SetMoney(player.GetMoney() - this->GetRent() * 2);
				this->GetOwner()->SetMoney(this->GetOwner()->GetMoney() + this->GetRent() * 2);
			}
			else
			{
				cout << player.GetName() << " pays " << POUND << this->GetRent() << endl;
				player.SetMoney(player.GetMoney() - this->GetRent());
				this->GetOwner()->SetMoney(this->GetOwner()->GetMoney() + this->GetRent());
			}
		}
	}
	else
	{
		if (player.GetMoney() > 0 && !mOwned)
		{
			cout << player.GetName() << " buys " << this->GetSquareName() << " for " << POUND << this->GetCost() << endl;
			player.SetMoney(player.GetMoney() - this->GetCost());
			this->mOwned = true;
			this->SetOwner(&player);
			player.GetColourGroupsOwned().at(this->mColourGroup)++;
			this->GetOwner()->GetColourGroupsOwned() = player.GetColourGroupsOwned();
			player.AddProperties(player.GetPosition());
		}
	}
}

int CProperty::GetColourGroup()
{
	return mColourGroup;
}

int CProperty::GetRent()
{
	return mRent;
}
