#include "CGoToJail.h"

unsigned const char POUND = 156;

CGoToJail::CGoToJail(string nameOfSquare)
{
	mSquareName = nameOfSquare;
}

CGoToJail::~CGoToJail()
{
}

// sends player to jail square, they automatically pay to get out
void CGoToJail::Behaviour(CPlayer& player)
{
	cout << player.GetName() << " lands on " << this->GetSquareName() << endl;
	cout << player.GetName() << " goes to jail" << endl;
	player.SetPosition(6);
	cout << player.GetName() << " pays " << POUND << "50" << endl;
	player.SetMoney(player.GetMoney() - 50);
}