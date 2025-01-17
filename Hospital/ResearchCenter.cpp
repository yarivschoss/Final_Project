#include <iostream>
using namespace std;
#pragma warning(disable: 4996)

#include <string.h>
#include "ResearchCenter.h"

ResearchCenter::ResearchCenter(const char* name) : numOfResearchers(0), 
maxNumOfResearchers(DEFAULT_NUM_OF_RESEARCHERS)
{
	setName(name);
	researchers = new Researcher * [maxNumOfResearchers];
}

bool ResearchCenter::setName(const char* name)
{
	if (!name) return false;

	else
	{
		delete[] this->name;
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
		return true;
	}
}

ResearchCenter::~ResearchCenter()
{
	for (int i = 0; i < numOfResearchers; i++) // fire researchers
		delete researchers[i];
	delete[] researchers;

	delete[] name;

	cout << "destroy Research Center" << endl;
}

bool ResearchCenter::addResearcher(const Researcher& researcher)
{
	if (maxNumOfResearchers == numOfResearchers)
	{
		maxNumOfResearchers *= 2;
		Researcher** temp = new Researcher * [maxNumOfResearchers];

		for (int i = 0; i < numOfResearchers; i++)
		{
			temp[i] = researchers[i];
		}

		delete[] researchers;
		researchers = temp;
	}

	researchers[numOfResearchers] = new Researcher(researcher);
	numOfResearchers++;
	return true;
}

Researcher* ResearchCenter::getResearcher(const char* name) const
{
	if (!name || numOfResearchers == 0)
	{
		return nullptr; // Return nullptr if name is invalid or no doctors exist
	}

	for (int i = 0; i < numOfResearchers; ++i)
	{
		if (strcmp(researchers[i]->getName(), name) == 0)
		{
			return researchers[i]; // Return pointer to the doctor if names match
		}
	}

	return nullptr; // Return nullptr if no matching doctor is found
}

ostream& operator<<(ostream& os, const ResearchCenter& r)
{
	os << "name: " << r.getName() << ", Number of researchers: " << r.numOfResearchers;
	return os;
}