#include "CJail.h"

unsigned const char POUND = 156;

CJail::CJail(string nameOfSquare)
{
	mSquareName = nameOfSquare;
}

CJail::~CJail()
{
}

void CJail::Behaviour(CPlayer& player)
{
	cout << player.GetName() << " lands on " << this->GetSquareName() << endl;
	cout << player.GetName() << " is just visiting" << endl;
}