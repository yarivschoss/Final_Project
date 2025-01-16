#pragma warning(disable: 4996)
using namespace std;
#include <iostream>

#include "Researcher.h"

Researcher::~Researcher()
{
	for (int i = 0; i < numOfPapers; i++) // fire doctors
		delete papers[i];
	delete[]papers;

	cout << "fire researcher" << endl;
}

bool Researcher::addPaper(const Paper& paper)
{
	if (maxNumOfPapers == numOfPapers)
	{
		maxNumOfPapers *= 2;
		Paper** temp = new Paper * [maxNumOfPapers];

		for (int i = 0; i < numOfPapers; i++)
		{
			temp[i] = papers[i];
		}

		delete[] papers;
		papers = temp;
	}

	papers[numOfPapers] = new Paper(paper);
	numOfPapers++;
	return true;
}

bool Researcher::setPapers(Paper*const* papers)
{
	if (!papers) return false;  // Check if the provided papers is valid

	delete[] this->papers;  // Free previously allocated memory
	this->papers = new Paper* [maxNumOfPapers];  // Allocate new memory for the papers

	for (int i = 0; i < numOfPapers; i++)
	{
		this->papers[i] = papers[i];
	}

	return true;
}

ostream& operator<<(ostream& os, const Researcher& r)
{
	os << "{" << (const Employee&)r << ", "; // using the employee's operator<< by casting 'e' to 'const Person&';
	os << "Number of papers published: " << r.getNumOfPapers() << "}";

	return os;
}

const Researcher& Researcher::operator=(const Researcher& other)
{
	if (this != &other)
	{
		Employee::operator=(other); // using the operator= of employee 
		numOfPapers = other.numOfPapers;
		maxNumOfPapers = other.maxNumOfPapers;
		setPapers(other.papers); // not allowing the other and this objects to point to the same address
		return *this;
	}
}