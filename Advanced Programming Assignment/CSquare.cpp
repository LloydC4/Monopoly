#include "CSquare.h"

CSquare::CSquare()
{

}

CSquare::CSquare(string nameOfSquare)
{
	mOwned = false;
	mSquareName = nameOfSquare;
}

CSquare::~CSquare()
{
}

void CSquare::Behaviour(CPlayer& player)
{
	cout << player.GetName() << " lands on " << this->GetSquareName() << endl;
}

string CSquare::GetSquareName()
{
	return mSquareName;
}

int CSquare::GetCost()
{
	return mCost;
}

void CSquare::SetMortgage(bool isMortgaged)
{
	mMortgaged = isMortgaged;
}

bool CSquare::GetMortgage()
{
	return mMortgaged;
}

CPlayer* CSquare::GetOwner()
{
	return mpOwner;
}

void CSquare::SetOwner(CPlayer* newOwner)
{
	mpOwner = newOwner;
}

bool CSquare::GetOwned()
{
	return mOwned;
}

void CSquare::SetOwned(bool isOwned)
{
	mOwned = isOwned;
}