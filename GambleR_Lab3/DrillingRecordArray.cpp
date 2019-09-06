#include"DrillingRecord.h"
#include"DrillingRecordArray.h"

using namespace std;

// Default constructor
DrillingRecordArray::DrillingRecordArray()
{
	data = new DrillingRecord[DEFAULT_ARRAY_CAPACITY];
}

// Overloaded constructor
DrillingRecordArray::DrillingRecordArray(unsigned int capacity)
{
	this->capacity = capacity;
	data = new DrillingRecord[DEFAULT_ARRAY_CAPACITY];
}

// Destructor
DrillingRecordArray::~DrillingRecordArray()
{
	delete[] this->data;
	delete this;
}

// Add record to the array doubling if neccessary
void DrillingRecordArray::add(DrillingRecord record)
{
	// Double if the array has reached the capacity
	int arrIndex = 0;
	if (this->capacity == this->size)
	{

		DrillingRecord* old = this->data;

		this->capacity = 2 * this->capacity;
		DrillingRecord* copiedRecords = new DrillingRecord[this->capacity];


		while (arrIndex < (int)this->size) 

		{
		//	cout << old[arrIndex] << "\n";
			copiedRecords[arrIndex] = old[arrIndex];
		//	cout << copiedRecords[arrIndex] << "\n";
			arrIndex++;
		}

		delete[] old;
		this->data = copiedRecords;

		/* // T
		while (arrIndex < this->getSize())
		{
			copiedRecords[arrIndex] = this->data[arrIndex]; // copy data
			arrIndex++;
		}

		// Clean up memory
		delete[] this->data;
		this->data = copiedRecords;ODO FIX DOUBLING
		// Create new drilling record
		DrillingRecord* newRecord = new DrillingRecord;

		this->capacity = (2 * this->capacity);
		DrillingRecord* copiedRecords = new DrillingRecord[this->capacity];


		this->size++;
		this->data[arrIndex] = *newRecord; // Assign location of new record in array*/
	}
	else
	{
		//cout << "ADDED:"<< record.getString(0)<<" displated \n";
		this->data[this->size] = record; // Assign location of new record in array
		this->size++;
	}
}

// Return a copy of the record
DrillingRecord DrillingRecordArray::get(unsigned int index)
{
	// Memory for copied data
	DrillingRecord* newRecord = new DrillingRecord;

	// Access data to dopy
	DrillingRecord oldRecord = this->data[index];

	// Copy Numbers
	for (int i = 0; i < MAX_NUMS; i++)
	{
		//cout << "Datatocopy: " << oldRecord.getNum(i) << "\n";
		newRecord->addNum(oldRecord.getNum(i));
	}

	// Copy Strings
	for (int j = 0; j < MAX_STRINGS; j++)
	{
		newRecord->addString(oldRecord.getString(j));
	}

	return *newRecord;
}