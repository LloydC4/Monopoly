#pragma once
#include "CSquare.h"
#include <iostream>

class CJail : public CSquare
{
public:
	CJail(string nameOfSquare); // constructor
	virtual ~CJail(); // virtual destructor
	void Behaviour(CPlayer& player) override; // performs the squares behaviour when landed on

private:
};
