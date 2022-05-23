#include "CFreeParking.h"

unsigned const char POUND = 156;

CFreeParking::CFreeParking(string nameOfSquare)
{
	mSquareName = nameOfSquare;
}

CFreeParking::~CFreeParking()
{
}

void CFreeParking::Behaviour(CPlayer& player)
{
	cout << player.GetName() << " lands on " << this->GetSquareName() << endl;
	cout << player.GetName() << " is resting" << endl;
}