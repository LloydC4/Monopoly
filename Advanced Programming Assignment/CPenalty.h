#pragma once
#include "CSquare.h"
#include <iostream>

class CPenalty : public CSquare
{
public:
	CPenalty(string nameOfSquare); // constructor
	virtual ~CPenalty(); // virtual destructor
	void Behaviour(CPlayer& player) override; // performs the squares behaviour when landed on

private:
};
