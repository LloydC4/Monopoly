#include "CGo.h"

unsigned const char POUND = 156;

CGo::CGo(string nameOfSquare)
{
	mSquareName = nameOfSquare;
}

CGo::~CGo()
{
}

void CGo::Behaviour(CPlayer& player)
{
	cout << player.GetName() << " lands on " << this->GetSquareName() << endl;
}