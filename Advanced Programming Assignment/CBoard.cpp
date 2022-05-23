#include "CBoard.h"
#include "CProperty.h"
#include "CGo.h"
#include "CBonus.h"
#include "CJail.h"
#include "CGoToJail.h"
#include "CStation.h"
#include "CFreeParking.h"
#include "CPenalty.h"
using namespace std;

CBoard::CBoard()
{
	ReadFile(mBoardDetails, BOARD_SIZE, "monopoly.txt"); // read file in to array
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		if (mBoardDetails[i].front() == '1') // uses first character of line to determine square type
		{
			string details = mBoardDetails[i]; // unformatted square data
			string squareDetails[PROPERTY_SIZE]; // stores line after broken up
			for (unsigned int j = 2, k = 0; j < details.length(); j++) // breaks up the string in to an array(excluding first character)
			{
				if (details[j] != ' ') // creates substring by iterating over string until space, then carries on in the next index of the array
				{
					squareDetails[k].push_back(details[j]);
				}
				else
				{
					k++;
				}
			}
			unique_ptr<CSquare> square = make_unique<CProperty>(squareDetails[0] + " " + squareDetails[1], stoi(squareDetails[2]), stoi(squareDetails[3]), stoi(squareDetails[4]));
			mvBoard.push_back(move(square)); // add to board
		}
		else if (mBoardDetails[i].front() == '2') // uses first character of line to determine square type
		{
			string details = mBoardDetails[i]; // unformatted square data
			string squareDetails; // stores square name
			for (unsigned int j = 2; j < details.length(); j++) // extracts square name from unformatted data
			{
				squareDetails.push_back(details[j]);
			}
			unique_ptr<CSquare> square = make_unique<CGo>(squareDetails);
			mvBoard.push_back(move(square)); // add to board
		}
		else if (mBoardDetails[i].front() == '3') // uses first character of line to determine square type
		{
			string details = mBoardDetails[i]; // unformatted square data
			string squareDetails; // stores square name
			for (unsigned int j = 2; j < details.length(); j++) // extracts square name from unformatted data
			{
				squareDetails.push_back(details[j]);
			}
			unique_ptr<CSquare> square = make_unique<CStation>(squareDetails);
			mvBoard.push_back(move(square)); // add to board
		}
		else if (mBoardDetails[i].front() == '4') // uses first character of line to determine square type
		{
			string details = mBoardDetails[i]; // unformatted square data
			string squareDetails; // stores square name
			for (unsigned int j = 2; j < details.length(); j++) // extracts square name from unformatted data
			{
				squareDetails.push_back(details[j]);
			}
			unique_ptr<CSquare> square = make_unique<CBonus>(squareDetails);
			mvBoard.push_back(move(square)); // add to board
		}
		else if (mBoardDetails[i].front() == '5') // uses first character of line to determine square type
		{
			string details = mBoardDetails[i]; // unformatted square data
			string squareDetails; // stores square name
			for (unsigned int j = 2; j < details.length(); j++) // extracts square name from unformatted data
			{
				squareDetails.push_back(details[j]);
			}
			unique_ptr<CSquare> square = make_unique<CPenalty>(squareDetails);
			mvBoard.push_back(move(square)); // add to board
		}
		else if (mBoardDetails[i].front() == '6') // uses first character of line to determine square type
		{
			string details = mBoardDetails[i]; // unformatted square data
			string squareDetails; // stores square name
			for (unsigned int j = 2; j < details.length(); j++) // extracts square name from unformatted data
			{
				squareDetails.push_back(details[j]);
			}
			unique_ptr<CSquare> square = make_unique<CJail>(squareDetails);
			mvBoard.push_back(move(square)); // add to board
		}
		else if (mBoardDetails[i].front() == '7') // uses first character of line to determine square type
		{
			string details = mBoardDetails[i]; // unformatted square data
			string squareDetails; // stores square name
			for (unsigned int j = 2; j < details.length(); j++) // extracts square name from unformatted data
			{
				squareDetails.push_back(details[j]);
			}
			unique_ptr<CSquare> square = make_unique<CGoToJail>(squareDetails);
			mvBoard.push_back(move(square)); // add to board
		}
		else
		{
			string details = mBoardDetails[i]; // unformatted square data
			string squareDetails; // stores square name
			for (unsigned int j = 2; j < details.length(); j++) // extracts square name from unformatted data
			{
				squareDetails.push_back(details[j]);
			}
			unique_ptr<CSquare> square = make_unique<CFreeParking>(squareDetails);
			mvBoard.push_back(move(square)); // add to board
		}
	}
}

CBoard::~CBoard()
{
}

// opens file to be read, outputs error if file not found
void CBoard::OpenFile(ifstream& infile, string fileToOpen)
{
	infile.open(fileToOpen);
	if (!infile)
	{
		cout << "ERROR: ";
		cout << "Can't open input file\n";
	}
}

// reads file in to array
void CBoard::ReadFile(string arr[], int SIZE, string fileToOpen)
{
	ifstream infile;
	OpenFile(infile, fileToOpen);
	for (int i = 0; i < SIZE; i++)
	{
		string input = "";
		getline(infile, input);
		arr[i] = input;
	}

	infile.close();
}

// returns square
CSquare& CBoard::GetSquare(int squareNumber)
{
	return *mvBoard.at(squareNumber);
}