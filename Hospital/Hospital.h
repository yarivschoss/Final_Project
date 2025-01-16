#ifndef __HOSPITAL_H
#define __HOSPITAL_H

#pragma warning(disable: 4996)
#include <iostream>

#include "ResearchCenter.h"
#include "Department.h"
#include "Doctor.h"
#include "Nurse.h"
#include "Patient.h"
#include "Visit.h"


class Hospital 
{

public: 

	int const DEFAULT_NUM_OF_DEPARTMENTS = 7; // Default number of departments
	int const DEFAULT_STAFF_SIZE = DEFAULT_NUM_OF_DEPARTMENTS * 20; // Default size of hospital 
	int numOfPatients, numOfVisits;
private:

	char* name;
	int numOfDoctors, numOfNurses, numOfDepartments;
	int maxNumOfDoctors, maxNumOfNurses, maxNumOfDepartments, maxNumOfPatients, maxNumOfVisits;

	ResearchCenter* researchCenter; // need to update initillization values

	Doctor** doctors = nullptr;
	Nurse** nurses = nullptr;
	Department** departments = nullptr;
	Patient** patients;
	Visit** visits;

	Hospital(const Hospital& other) = delete; // coping a hospital is not allowed 
	void operator=(const Hospital& other) = delete; // coping a hospital is not allowed

public:

	Hospital(const char* name);
	~Hospital();
	
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
	Visit* getVisitByPatientId(int patientID) const;


	// Functions to add patients and visits
	bool addVisit(int patientID, const char* purpose, const char* departmentName, const char* staffName, time_t visitDate);
	int addPatient(const Person& person);

	int getNumOfPatients() const;
	Patient* getPatient(int index) const;


	

	Patient* findPatientById(int id);
	Department* getDepartmentForpatient(const char* name) const;
	Employee* getStaff(const char* name) const;

	void showPatientsInDepartment(const char* departmentName) const;

	void showAll() const;
	void showDepartments() const;
	void showDoctors() const;
	void showNurses() const;
};



#endif //__HOSPITAL_H
