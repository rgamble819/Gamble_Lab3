#include"DrillingRecord.h"
#include"DrillingRecordArray.h"

#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

// Format output for this type
ostream& operator << (ostream& os, const DrillingRecord& record) 
{
	for (int i = 0; i < 18; i++) 
	{
		if (i < 2)
		{
			os << record.strings[i] << ";";
		}
		else if (i < 17)
		{
			os << fixed << setprecision(2) << record.nums[i-2] << ";";
		}
		else if (i == 17)
		{
			os << fixed << setprecision(2) << record.nums[i-2] << "\n";
		}
	}

	return os;
}

// Add a number to record data
void DrillingRecord::addNum(double num)
{
	if (this->nums == NULL) 
	{
		this->nums[MAX_NUMS-1];
	}
	this->nums[numCtr] = num;
	this->numCtr++;
}

// Add String to record data
void DrillingRecord::addString(string str)
{
	if (this->strings == NULL) 
	{
		this->strings[MAX_STRINGS-1];
	}
	this->strings[strCtr] = str;
	this->strCtr++;
}

// Access a copy of number in record
double DrillingRecord::getNum(unsigned int index)
{
	return this->nums[index];
}

// Access a copy of string in record
string DrillingRecord::getString(unsigned int index)
{
	return this->strings[index];
}