#include"DrillingRecord.h"
#include"DrillingRecordArray.h"

using namespace std;

DrillingRecordArray::DrillingRecordArray()
{
	data = new DrillingRecord[DEFAULT_ARRAY_CAPACITY];
}

DrillingRecordArray::DrillingRecordArray(unsigned int capacity)
{
	this->capacity = capacity;
	data = new DrillingRecord[DEFAULT_ARRAY_CAPACITY];
}

DrillingRecordArray::~DrillingRecordArray()
{
	delete[] this->data;
	delete this;
}

// Add record to the array doubling if neccessary
void DrillingRecordArray::add(DrillingRecord record)
{
	// Create new drilling record
	DrillingRecord* newRecord = new DrillingRecord;

	// Double if the array has reached the capacity
	int arrIndex = 0;
	if (this->capacity == this->size)
	{
		this->capacity = (2 * this->capacity);
		DrillingRecord* copiedRecords = new DrillingRecord[this->capacity];

		while (arrIndex < this->size)
		{
			copiedRecords[arrIndex] = this->data[arrIndex]; // copy data
			arrIndex++;
		}

		// Clean up memory
		delete[] this->data;
		this->data = copiedRecords;

		this->data[arrIndex] = *newRecord; // Assign location of new record in array
	}
	else
	{
		this->data[this->size + 1] = *newRecord; // Assign location of new record in array
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
		newRecord->addNum(oldRecord.getNum(i));
	}

	// Copy Strings
	for (int j = 0; j < MAX_STRINGS; j++)
	{
		newRecord->addString(oldRecord.getString(j));
	}

	return *newRecord;
}