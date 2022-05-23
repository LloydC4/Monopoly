#pragma once
#include "CSquare.h"
#include <iostream>

class CProperty : public CSquare
{
public:
	CProperty(string nameOfSquare, int squareCost, int squareRent, int squareColourGroup); // constructor
	virtual ~CProperty(); // virtual destructor
	void Behaviour(CPlayer& player) override; // performs the squares behaviour when landed on
	int GetRent(); // returns rent cost
	int GetColourGroup(); // returns colour group

private:
	int mRent = 0; // stores property rent
	int mColourGroup = 0; // stores colour group
};
