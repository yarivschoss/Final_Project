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
	/*friend class Doctor;
	friend class Nurse;*/
	
private:

	char* name;
	int numOfEmployees;
	int maxNumOfEmployees;
	

	Employee** employees = nullptr;

	void operator=(const Department& other) = delete; // coping a department is not allowed
	Department(const Department& other) = delete; // coping a department is not allowed 

public:

	Department(const char* name);
	virtual ~Department();

	operator int const() const { return maxNumOfEmployees; } // returns size of department staff
	operator const char* () const { return getName(); } // returns name of department
	
	bool setName(const char* name);
	const char* getName() const { return name; }

	bool addDoctor(Doctor& doctor); // adding a doctor to this department - returns false if department is full
	bool addNurse(Nurse& nurse); // adding a nurse to this department - returns false if department is full

	void showDoctors() const;
	void showNurses() const;

	friend ostream& operator<<(ostream& os, const Department& d); // prints department's data


	const Department& operator+=(Doctor& other)
	{
		this->addDoctor(other);
		return *this;
	}
	const Department& operator+=(Nurse& other)
	{
		this->addNurse(other);
		return *this;
	}
	bool operator()(const char* name); // prints data according to name
};

#endif //__DEPARTMENT_H