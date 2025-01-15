#ifndef __DEPARTMENT_H
#define __DEPARTMENT_H

#include "Doctor.h"
#include "Nurse.h"

//class Nurse;
//class Doctor;

class Department
{

public:

	int const MAX_DEPARTMENT_SIZE = 20; // Max size of department
	friend class Doctor;
	friend class Nurse;
	
private:

	char* name;
	int numOfDoctors, numOfNurses;
	int maxNumOfDoctors, maxNumOfNurses;
	

	Doctor** doctors;
	Nurse** nurses;

public:

	Department(const char* name);
	~Department();

	Department(const Department& other) = delete; // coping a department is not allowed 
	void operator=(const Department& other) = delete; // coping a department is not allowed

	friend ostream& operator<<(ostream& os, const Department& d); // prints department's data

	bool operator()(const char* name); // prints data according to name
	
	operator int const() const { return maxNumOfDoctors + maxNumOfNurses; } // returns size of department staff
	operator const char* () const { return getName(); } // returns name of department
	
	bool setName(const char* name);
	const char* getName() const { return name; }


	bool addDoctor(Doctor& doctor); // adding a doctor to this department - returns false if department is full
	bool addNurse(Nurse&nurse); // adding a nurse to this department - returns false if department is full

	void showAll() const;
	void showDoctors() const;
	void showNurses() const;

};

#endif //__DEPARTMENT_H