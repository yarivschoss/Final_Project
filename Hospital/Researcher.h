#ifndef __RESEARCHER_H
#define __RESEARCHER_H

#include "Employee.h"
#include "Paper.h"

#include <iostream>
using namespace std;

class Researcher : virtual public Employee
{
public:
	const int DEFAULT_NUM_OF_PAPERS = 7;

	friend class ResearchCenter;

protected:
	int numOfPapers, maxNumOfPapers;
	Paper** papers;

	Researcher(const Researcher& other) : Employee(other) { *this = other; }
	const Researcher& operator=(const Researcher& other);
	
	bool setPapers(Paper* const* papers); // changing the pointers in the array of pointer to Paper is not allowed 
	
public:
	Researcher(const Employee& r) : Employee(r), maxNumOfPapers(DEFAULT_NUM_OF_PAPERS), numOfPapers(0)
	{ papers = new Paper * [maxNumOfPapers]; }
	virtual ~Researcher();
	

	int getNumOfPapers() const { return numOfPapers; }
	const Paper* getPaper(int index) const { return papers[index]; }
	
	bool addPaper(const Paper& paper);
	void showPapers() const
	{ 
		for (int i = 0; i < numOfPapers; i++)
		{
			cout << "{" << *papers[i] << "}";
				
			if (i < numOfPapers - 1) cout << ", ";
		}
	}

	virtual Researcher* clone() const override { return new Researcher(*this); }

	virtual void toOs(ostream& os) const { ; }

	friend ostream& operator<<(ostream& os, const Researcher& r); // Overloaded stream insertion operator to print Person data
	friend istream& operator>>(istream& in, Researcher& r);
	
	bool operator>(const Researcher& other) const { return this->numOfPapers > other.numOfPapers; }
	bool operator< (const Researcher& other) const { return this->numOfPapers < other.numOfPapers; }
	bool operator>= (const Researcher& other) const { return this->numOfPapers >= other.numOfPapers; }
	bool operator<= (const Researcher& other) const { return this->numOfPapers <= other.numOfPapers; }
	bool operator== (const Researcher& other) const { return this->numOfPapers == other.numOfPapers; }
};

#endif //__RESEARCHER_H
