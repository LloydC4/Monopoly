#pragma once
#include "CSquare.h"
#include <iostream>

class CGoToJail : public CSquare
{
public:
	CGoToJail(string nameOfSquare); // constructor
	virtual ~CGoToJail(); // virtual destructor
	void Behaviour(CPlayer& player) override; // performs the squares behaviour when landed on

private:
};

