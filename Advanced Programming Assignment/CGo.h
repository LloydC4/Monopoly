#pragma once
#include "CSquare.h"
#include <iostream>

class CGo : public CSquare
{
public:
	CGo(string nameOfSquare); // constructor
	virtual ~CGo(); // virtual destructor
	void Behaviour(CPlayer& player) override; // performs the squares behaviour when landed on

private:
};
