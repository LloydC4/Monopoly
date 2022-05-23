#pragma once
#include <memory>
#include <string>
using namespace std;

class CDice
{
public:
	CDice(); // contructor
	~CDice(); // destructor
	void OpenFile(ifstream& infile, string fileToOpen); // opens .txt file
	int ReadFile(int SIZE, string fileToOpen); // reads file with int value, returns the int value
	int Roll(); // rolls dice

private:
};

