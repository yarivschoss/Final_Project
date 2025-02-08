#ifndef __RESEARCHER_H
#define __RESEARCHER_H

#include "Employee.h"
#include "Paper.h"

#include <iostream>
#include <vector>
using namespace std;

class Researcher : virtual public Employee
{
public:
	const int DEFAULT_NUM_OF_PAPERS = 7;

	friend class ResearchCenter;

protected:
	vector<Paper> papers;

public:
	Researcher(const Employee& r) : Employee(r) { papers.reserve(DEFAULT_NUM_OF_PAPERS); }
	virtual ~Researcher() { ; }
	

	int getNumOfPapers() const { return papers.size(); }
	const Paper* getPaper(int index) const 
	{ 
		if (index < 0) return nullptr;

		vector<Paper>::const_iterator itr = papers.begin();
		vector<Paper>::const_iterator itrEnd = papers.end();

		for (int i = 0; i < index; ++itr, i++);
		return &(*itr);
	}
	
	bool addPaper(const Paper& paper)
	{
		papers.push_back(paper);
		return true;
	}
	void showPapers() const
	{ 
		vector<Paper>::const_iterator itr = papers.begin();
		vector<Paper>::const_iterator itrEnd = papers.end();

		int size = papers.size();

		for (int i = 0; itr!=itrEnd ; ++itr, i++)
		{
			cout << "{" << *itr << "}";
				
			if (i < size) cout << ", ";
		}
	}

	virtual Researcher* clone() const override { return new Researcher(*this); }

	virtual void toOs(ostream& os) const { os << "Number of papers published: " << this->getNumOfPapers(); }

	friend ostream& operator<<(ostream& os, const Researcher& r) // Overloaded stream insertion operator to print Person data
	{
		os << (const Employee&)r; // using the employee's operator<< by casting 'e' to 'const Person&';
		return os;
	}
	friend istream& operator>>(istream& in, Researcher& r)
	{
		in >> (Employee&)r;
		return in;
	}
	
	bool operator>(const Researcher& other) const { return this->papers.size() > other.papers.size(); }
	bool operator< (const Researcher& other) const { return this->papers.size() < other.papers.size(); }
	bool operator>= (const Researcher& other) const { return this->papers.size() >= other.papers.size(); }
	bool operator<= (const Researcher& other) const { return this->papers.size() <= other.papers.size(); }
	bool operator== (const Researcher& other) const { return this->papers.size() == other.papers.size(); }
};

#endif //__RESEARCHER_H
