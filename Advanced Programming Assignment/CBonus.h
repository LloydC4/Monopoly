#pragma once
#include "CSquare.h"
#include <iostream>

class CBonus : public CSquare
{
public:
	CBonus(string nameOfSquare); // constructor
	virtual ~CBonus(); // virtual destructor
	void Behaviour(CPlayer& player) override; // performs the squares behaviour when landed on

private:
};