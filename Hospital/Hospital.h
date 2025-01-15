#ifndef __HOSPITAL_H
#define __HOSPITAL_H

#pragma warning(disable: 4996)
#include <iostream>

#include "ResearchCenter.h"
#include "Department.h"
#include "Doctor.h"
#include "Nurse.h"
#include "Patient.h"


class Hospital 
{

public: 

	int const DEFAULT_NUM_OF_DEPARTMENTS = 7; // Default number of departments
	int const DEFAULT_STAFF_SIZE = DEFAULT_NUM_OF_DEPARTMENTS * 20; // Default size of hospital 

private:

	char* name;
	int numOfDoctors, numOfNurses, numOfDepartments;
	int maxNumOfDoctors, maxNumOfNurses, maxNumOfDepartments;

	ResearchCenter* researchCenter; // need to update initillization values

	Doctor** doctors = nullptr;
	Nurse** nurses = nullptr;
	Department** departments = nullptr;

public:

	Hospital(const char* name);
	~Hospital();
	Hospital(const Hospital& other) = delete; // coping a hospital is not allowed 

	void operator=(const Hospital& other) = delete; // coping a hospital is not allowed

	friend ostream& operator<<(ostream& os, const Hospital& h);

	bool operator()(const char* name); // prints data according to name
	//Department* operator[](const char* name) { return getDepartment(name); } // replaces getDepartment - NOT WORKING NEED TO FIND FIX

	operator int const() const { return DEFAULT_STAFF_SIZE; } // returns size of hospital staff
	operator const char* () const { return getName(); } // returns name of hospital

	bool setName(const char* name);
	const char* getName() const { return name; }
	
	Department* getDepartment(const char* name) const; //searches through the array of departments and returns a pointer to the department with the specified name
	Doctor* getDoctor(const char* name) const; //searches through the array of doctors and returns a pointer to the doctor with the specified name
	Nurse* getNurse(const char* name) const; //searches through the array of nurses and returns a pointer to the nurse with the specified name

	bool addDoctor(Doctor& doctor);
	bool addNurse(Nurse& nurse);
	bool addDepartmant(const char* name);

	Patient* getPatient(int id);
	// Function to search for a patient by ID
	Patient* findPatientById(int id);

	// Function to add a visit for a patient
	void addVisitForPatient(int id);

	
	void showAll() const;
	void showDepartments() const;
	void showDoctors() const;
	void showNurses() const;
};



#endif //__HOSPITAL_H
