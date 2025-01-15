#ifndef __RESEARCHER_H
#define __RESEARCHER_H

#include "Employee.h"

#include <iostream>
using namespace std;

class Researcher : public Employee
{
public:
	const int DEFAULT_NUM_OF_PAPERS = 7;

private:
	int numOfPapers, maxNumOfPapers;
	char** papers;

public:
	Researcher(const Employee& r) : Employee(r), maxNumOfPapers(DEFAULT_NUM_OF_PAPERS), numOfPapers(0)
	{ papers = new char * [maxNumOfPapers]; }
	~Researcher();


	int getNumOfPapers() const { return numOfPapers; }
	const char* getPaper(int index) const { return papers[index]; }

	bool addPaper(const char* paper);

	friend ostream& operator<<(ostream& os, const Researcher& r); // Overloaded stream insertion operator to print Person data
	
	bool operator>(const Researcher& other) const { return this->numOfPapers > other.numOfPapers; }
	bool operator< (const Researcher& other) const { return this->numOfPapers < other.numOfPapers; }
	bool operator>= (const Researcher& other) const { return this->numOfPapers >= other.numOfPapers; }
	bool operator<= (const Researcher& other) const { return this->numOfPapers <= other.numOfPapers; }
};

#endif //__RESEARCHER_H
