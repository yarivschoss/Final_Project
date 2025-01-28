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

	Surgeon(const Surgeon& other) : Employee(other), Doctor(other) { *this = other; } //using the default operator= of Surgeon

public:

	Surgeon(const Doctor& s, int numOfOperations) : Employee(s), Doctor(s), numOfOperations(numOfOperations) { ; } // will get a no default c'tor for class employee exist error if will not call Employee(s) direcly
	virtual ~Surgeon() { ; }

	int getNumOfOperations() const { return numOfOperations; }

	bool setNumOfOperations(const int numOfOperations) 
	{ 
		if (numOfOperations < 0) return false;

		this->numOfOperations = numOfOperations;
		return true;
	}

	virtual Employee* clone() const override { return new Surgeon(*this); }

	// Surgeon's info when printing an array of employees
	virtual void toOs(ostream& os) const override
	{
		os << "number of operations performed: " << this->getNumOfOperations();
	}

	friend ostream& operator<<(ostream& os, const Surgeon& s)
	{
		os << (const Doctor&)s; // using the employee's operator<< by casting 'e' to 'const Person&';
		return os;
	}
	friend istream& operator>>(istream& in, Surgeon& s)
	{
		in >> (Doctor&)s;
		cout << "Enter number of operations performed: ";
		in >> s.numOfOperations;
		return in;
	}

};

#endif //__SURGEON_H