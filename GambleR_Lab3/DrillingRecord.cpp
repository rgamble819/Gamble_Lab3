#include"DrillingRecord.h"
#include"DrillingRecordArray.h"

#include <string>
#include <sstream>

using namespace std;

// Add a number to record data
void DrillingRecord::addNum(double num)
{
	this->nums[numCtr] = num;
	this->numCtr++;
}

// Add String to record data
void DrillingRecord::addString(string str)
{
	this->strings[strCtr];
	this->strCtr++;
}

// Access a copy of number in record
double DrillingRecord::getNum(unsigned int index)
{
	double copyOfNum = this->nums[index];
	return copyOfNum;
}

// Access a copy of string in record
string DrillingRecord::getString(unsigned int index)
{
	string copyOfString = this->strings[index];
	return copyOfString;
}