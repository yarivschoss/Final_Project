#pragma warning(disable: 4996)
using namespace std;
#include <iostream>

#include "Researcher.h"

bool Researcher::addPaper(const char* paper)
{
	if (maxNumOfPapers == numOfPapers)
	{
		maxNumOfPapers *= 2;
		char** temp = new char * [maxNumOfPapers];

		for (int i = 0; i < numOfPapers; i++)
		{
			temp[i] = papers[i];
		}

		delete[] papers;
		papers = temp;
	}

	strcpy(papers[numOfPapers], paper);
	numOfPapers++;
	return true;
}

ostream& operator<<(ostream& os, const Researcher& r)
{
	os << "{" << (const Employee&)r << ", "; // using the employee's operator<< by casting 'e' to 'const Person&';
	os << "Number of papers published: " << r.getNumOfPapers() << "}";

	return os;
}