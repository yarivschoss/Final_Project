#ifndef __SURGEON_H
#define __SURGEON_H

#pragma warning(disable: 4996)
#include <iostream>
using namespace std;

#include "Doctor.h"


class Surgeon : virtual public Doctor
{
public:

	friend class Hospital;

private:

	int numOfOperations;


public:

	Surgeon(const Doctor& s, int numOfOperations) : Doctor(s), numOfOperations(numOfOperations) { ; }
	virtual ~Surgeon() { ; }

	virtual Employee* clone() const override { return new Surgeon(*this); }

};

#endif //__SURGEON_H