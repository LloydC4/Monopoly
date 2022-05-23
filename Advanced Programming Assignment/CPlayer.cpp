#include "CPlayer.h"

// consctructor, reserves vector space to store colour group details
CPlayer::CPlayer(string playerName)
{
	mName = playerName;
	mPosition = 0;
	for (size_t i = 0; i < 8; i++)
	{
		mvColourGroupsOwned.push_back(0);
	}
}

CPlayer::~CPlayer()
{
}

int CPlayer::GetPosition()
{
	return mPosition;
}

void CPlayer::SetPosition(int newPosition)
{
	mPosition = newPosition;
}

string CPlayer::GetName()
{
	return mName;
}

int CPlayer::GetMoney()
{
	return mMoney;
}

void CPlayer::SetMoney(int newMoney)
{
	mMoney = newMoney;
}

vector<int>& CPlayer::GetColourGroupsOwned()
{
	return mvColourGroupsOwned;
}

// users vector to see if player owners all colour group, vector index = colour group
//  not the best implementation
bool CPlayer::DoesPlayerOwnColourGroup(int colourGroup)
{
	if (colourGroup == 0 || colourGroup == 1 || colourGroup == 2 || colourGroup == 4 || colourGroup == 5 || colourGroup == 7)
	{
		if (this->GetColourGroupsOwned().at(colourGroup) == 2)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if (colourGroup == 2 || colourGroup == 6)
	{
		if (this->GetColourGroupsOwned().at(colourGroup) == 3)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

int CPlayer::RollDice()
{
	return GetDice().Roll();
}


CDice& CPlayer::GetDice()
{
	return mDice;
}

void CPlayer::AddProperties(int property)
{
	mvPropertiesOwned.push_back(property);
}

vector<int>& CPlayer::GetProperties()
{
	return mvPropertiesOwned;
}

void CPlayer::SetBankrupt(bool isBankrupt)
{
	mBankrupt = isBankrupt;
}

bool CPlayer::GetBankrupt()
{
	return mBankrupt;
}

void CPlayer::SetHasMortgagedProperties(bool MortgagedProperties)
{
	mHasMortgagedProperties = MortgagedProperties;
}

bool CPlayer::GetHasMortgagedProperties()
{
	return mHasMortgagedProperties;
}

// static dice object
CDice CPlayer::mDice;