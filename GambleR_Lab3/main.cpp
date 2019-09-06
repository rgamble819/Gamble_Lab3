// GambleR_Lab3.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <set>

#include"DrillingRecordArray.h"
#include"DrillingRecord.h"

using namespace std;

// Declaring functions for main
bool hasDifferentDate(string dataValue, int row);
bool hasUniqueTime(string dataValue);
bool isValidFloatData(string dataValue);
void printArray(DrillingRecordArray* array);

int main(int argc, char *argv[])
{
	// Setting cin with the file stream as buffer.

	// Alternative way to redirect cin to file
	ifstream inFile(argv[1]);
	cin.rdbuf(inFile.rdbuf());

	// Declare array for records to store them
	DrillingRecordArray* drillData = new DrillingRecordArray;

	//Skip first line according to filetype & project specs.
	string line = "";
	getline(cin, line);
	line = "";

	// Loop through each row in the CSV.
	int row = 0;
	int validLines = 0;
	while (getline(cin, line))
	{
		//Increment row.
		row++;

		// For every line exists a record.
		DrillingRecord* recordPtr = new DrillingRecord;

		// Open stream to dataLine.
		stringstream dataLine(line);
		string dataValue = "";

		// Loop through each individual column.
		bool skipRow = false;
		//bool addData = false;
		int column = 0;
		while (getline(dataLine, dataValue, ','))
		{
			// Increment Colummn
			column++;

			bool differentDate = false;
			bool hasDuplicateTime = false;

			// Check if the data line has a different date.
			if (column == 1
				&& !hasDifferentDate(dataValue, row)
				&& row > 1)
			{
				cout << "Non-matching date stamp " << dataValue << " at line " << row << ".\n";
				differentDate = true;
				dataValue = "";
				skipRow = true;
				continue;
			}

			// Check if the data lines has duplicate time stamps.
			if (column == 2
				&& !differentDate
				&& hasUniqueTime(dataValue)
				&& row > 1
				&& !skipRow)
			{
				cout << "Duplicate timestamp " << dataValue << " at line " << row << ".\n";
				hasDuplicateTime = true;
				dataValue = "";
				skipRow = true;
				continue;
			}

			// Check if the data on the line is valid float-point data ( data > 0).
			if (column == 3
				&& !differentDate
				&& !hasDuplicateTime
				&& !isValidFloatData(line)
				&& !skipRow)
			{
				cout << "Invalid floating-point data at line " << row << ".\n";
				dataValue = "";
				skipRow = true;
				continue;
			}

			if (column < 3)
			{
				//cout << "String Added";
				recordPtr->addString(dataValue);
				//cout << drillData->get(0).getString(0) << " : DATA\n";
			}
			else
			{
				recordPtr->addNum(stod(dataValue));
			}

			// Reset data Value for loop
			dataValue = "";
		}

		if (skipRow != true) 
		{
			drillData->add(*recordPtr);
		}

		// Need to output data

		column = 0;
	}

	delete drillData;
	return 0;
}


//Stored data to compare
// don't do this anymore not good to declare variables here
set<string> timeStamps;
string baseDate = "";

// Function returns true is the date is different from the 1st date in the file.
bool hasDifferentDate(string dataValue, int row)
{

	bool isDifferent = false;
	if (row == 1)
	{
		baseDate = dataValue.c_str(); // set base date to check the rest of the records against
		return false;
	}
	else
	{
		isDifferent = ((baseDate.compare(dataValue)) == 0); // check date of record against base date.
		return isDifferent;
	}
}

// Function returns true is the time is unqiue.
bool hasUniqueTime(string dataValue)
{
	// Find word in set or return last string in set
	set<string>::iterator timeIt = timeStamps.find(dataValue.c_str());

	// If the set is not at the end then the time exists
	if (timeIt != timeStamps.end())
	{
		return true;
	}
	else
	{
		timeStamps.insert(dataValue.c_str());
		return false;
	}
}

// Function that returns true if the argument passed through is considered valid float data (greater than 0).
bool isValidFloatData(string line)
{
	// Get line of float data
	stringstream dataLine(line);

	bool isValid = true;

	// Loop through individual float data
	string data = "";
	int column = 0;
	while (getline(dataLine, data, ','))
	{
		if (column >= 2)
		{
			float fVal = stof(data);

			if (fVal <= 0.0) // Check if proper valid float value
			{
				isValid = false;
			}
		}
		column++;
	}
	return isValid;
}