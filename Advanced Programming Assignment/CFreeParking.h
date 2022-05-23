#pragma once
#include "CSquare.h"
#include <iostream>

class CFreeParking : public CSquare
{
public:
	CFreeParking(string nameOfSquare); // constructor
	virtual ~CFreeParking(); // virtual destructor
	void Behaviour(CPlayer& player) override;  // performs the squares behaviour when landed on

private:
};
