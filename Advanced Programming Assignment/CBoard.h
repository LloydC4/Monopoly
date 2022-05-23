#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include "CSquare.h"
using namespace std;
typedef vector<unique_ptr<CSquare>> CSquareVector;

const int BOARD_SIZE = 26; // total number of squares
const int PROPERTY_SIZE = 5; // number of fields needed to store property square data

class CBoard
{
public:
	CBoard(); // constructor
	~CBoard(); // destructor
	void OpenFile(ifstream& infile, string fileToOpen); // opens .txt file
	void ReadFile(string arr[], int SIZE, string fileToOpen); // reads .txt file in to array
	CSquare& GetSquare(int squareNumber); // returns CSquare reference

private:
	CSquareVector mvBoard; // vector of unique ptr to store square details
	string mBoardDetails[BOARD_SIZE]; // array to read board details in to
};

