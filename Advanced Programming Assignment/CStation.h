#pragma once
#include "CSquare.h"
#include <iostream>

class CStation : public CSquare
{
public:
	CStation(string nameOfSquare); // constructor
	virtual ~CStation(); // virtual destructor
	void Behaviour(CPlayer& player) override; // performs the squares behaviour when landed on

private:
};
