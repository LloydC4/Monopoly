#include "CDice.h"
#include <iostream>
#include <fstream>

CDice::CDice()
{
	srand(ReadFile(1, "seed.txt")); // reading in seed from file
}

CDice::~CDice()
{
}

// opens file to be read, outputs error if file not found
void CDice::OpenFile(ifstream& infile, string fileToOpen)
{
	infile.open(fileToOpen);
	if (!infile)
	{
		cout << "ERROR: ";
		cout << "Can't open input file\n";
	}
}

// reads file with int value, returns the int value
int CDice::ReadFile(int SIZE, string fileToOpen)
{
	ifstream infile;
	OpenFile(infile, fileToOpen);
	int result = 0;
	infile >> result;
	infile.close();
	return result;
}

// returns random number from 1-6
int CDice::Roll()
{
	return static_cast<int>(static_cast<double> (rand()) / (RAND_MAX + 1) * 6.0f + 1);
}