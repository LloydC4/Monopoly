#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include "CDice.h"
using namespace std;
typedef vector<int> intVector;

class CPlayer
{
public:
	CPlayer(string playerName); // constructor
	~CPlayer(); // destructor
	int GetPosition(); // returns current player position
	void SetPosition(int newPosition); // sets current player position
	string GetName(); // returns player name
	int GetMoney(); // returns player balance
	void SetMoney(int newMoney); // sets player balance
	void AddProperties(int property); // adds property square number to proporties owned vector
	intVector& GetColourGroupsOwned(); // vector to store number of colour group X owned to check for double rent
	bool DoesPlayerOwnColourGroup(int colourGroup); // checks to see if player owns all colour group X for double rent
	int RollDice(); // rolls dice, returns result
	CDice& GetDice(); // returns static dice reference
	intVector& GetProperties(); // gets all properties owned by player
	void SetBankrupt(bool isBankrupt); // sets player bankrupt status
	bool GetBankrupt(); // checks to see if player is bankrupt
	void SetHasMortgagedProperties(bool MortgagedProperties); // sets bool to true if player has mortgaged properties
	bool GetHasMortgagedProperties(); // returns true if player has mortgaged properties

private:
	int mMoney = 1500; // stores current money, player starts with 1500
	string mName = ""; // stores player name
	int mPosition = 0; // stores current position
	static CDice mDice; // dice
	bool mBankrupt = false; // true if player goes bankrupt
	bool mHasMortgagedProperties = false; // true if player has mortgaged properties
	intVector mvPropertiesOwned; // stores position of owned properties
	intVector mvColourGroupsOwned; // stores number of colour group properties owned
};

