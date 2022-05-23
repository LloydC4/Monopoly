#pragma once
#include "CPlayer.h"
#include <iostream>
using namespace std;

class CSquare
{
public:
	CSquare(); // constructor
	CSquare(string nameOfSquare); // 2nd constructor
	virtual ~CSquare(); // virual destructor
	virtual void Behaviour(CPlayer& player); // performs the squares behaviour when landed on
	string GetSquareName(); // returns square name
	int GetCost(); // returns cost
	void SetMortgage(bool isMortgaged); // sets mortgage status
	bool GetMortgage(); // returns mortgage status
	CPlayer* GetOwner(); // returns owner
	void SetOwner(CPlayer* newOwner); // sets owner
	bool GetOwned(); // returns if owned
	void SetOwned(bool isOwned); // sets true if owned

	string mSquareName = ""; // stores square name
	int mCost = 0; // cost of square
	bool mMortgaged = false; // true if property is mortgaged
	bool mOwned = false; // true if property is owned
	CPlayer* mpOwner = 0; // pointer to player object that owns property/station

private:

};

