#ifndef __RESEARCHERDOCTOR_H
#define __RESEARCHERDOCTOR_H

#pragma warning(disable: 4996)
#include <iostream>
using namespace std;

#include "Researcher.h"
#include "Doctor.h"

class ResearcherDoctor : virtual public Researcher , virtual public Doctor
{
public:

	friend class Hospital;
	friend class ResearchCenter;

private:

	ResearcherDoctor(const ResearcherDoctor& other) = default;

public:

	ResearcherDoctor(const Doctor& d, const Researcher& r) : Employee((Employee&)d), Doctor(d), Researcher(r) { ; }
	virtual ~ResearcherDoctor() { ; }

	virtual Researcher* clone() const override { return new ResearcherDoctor(*this); }

	virtual void toOs(ostream& os) const override 
	{ 
		this->Doctor::toOs(os); 
	}

	friend ostream& operator<<(ostream& os, const ResearcherDoctor& rd) // Overloaded stream insertion operator to print Person data
	{
		os << (const Researcher&)rd; // using the researcher's operator<< by casting 'rd' to 'const Researcher&';
		return os;
	}
	friend istream& operator>>(istream& in, ResearcherDoctor& rd)
	{
		in >> (Doctor&)rd;
		return in;
	}
	
};

#endif //RESEARCHERDOCTOR
