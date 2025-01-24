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


private:


public:

	ResearcherDoctor(const Doctor& d, const Researcher& r) : Employee((Employee&)d), Doctor(d), Researcher(r) { ; }
	virtual ~ResearcherDoctor() { ; }

	virtual Researcher* clone() const override { return new ResearcherDoctor(*this); }

	virtual void toOs(ostream& os) const override;
	
};

#endif //RESEARCHERDOCTOR
